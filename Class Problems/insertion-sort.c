#include <stdio.h>
#include <stdlib.h>

typedef struct node_rec
{ // Two equivalent types: "struct node" is equivalent to "Node"
   // char *name;
    int key;
    struct node_rec *next;
    // Node *next;
} Node;

Node *head = NULL;

Node *allocateNode(int key)
{
    Node *node;

    node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;

    return node;
}

void freeNode(Node *node)
{
    free(node);
}

// do insertion so that the list is sorted
void insertNode(int key)
{

    Node *pnode = NULL, *cnode;
    Node *N;

    N = allocateNode(key);

    // Base -1 Case

    if (head == NULL)
    {
        head = N;
        return;
    }

    cnode = head;
    // Base Case
    if (key < cnode->key)
    {
        head = N;
        N->next = cnode;
        return;
    }

    // Inductive case
    pnode = cnode;
    cnode = cnode->next;
    while (cnode != NULL)
    {
        if (key < cnode->key)
        {
            pnode->next = N;
            N->next = cnode;
            return;
        }
        pnode = cnode;
        cnode = cnode->next;
    }

    // Inductive Case + 1
    pnode->next = N;

    return;
}

void deleteNode(int key)
{
    Node *pnode = NULL, *cnode;

    cnode = head;
    // Base Case
    if (cnode->key == key)
    {
        head = cnode->next;
        freeNode(cnode);
        return;
    }

    // Inductive case
    pnode = cnode;
    cnode = cnode->next;
    while (cnode != NULL)
    {
        if (cnode->key == key)
        {
            pnode->next = cnode->next;
            freeNode(cnode);
            return;
        }
        pnode = cnode;
        cnode = cnode->next;
    }
}

Node *searchNode(int key)
{
    for (Node *cnode = head; cnode != NULL; cnode = cnode->next)
    {
        if (cnode->key == key)
            return cnode;
    }
    return NULL;
}

void printList()
{
    printf("====\n");
    for (Node *cnode = head; cnode != NULL; cnode = cnode->next)
    {
        printf("%d\n", cnode->key);
    }
    printf("====\n");
}

void main(int argc, char *argv[])
{
    FILE *fp;
    int key;

    fp = fopen(argv[1], "r");

    while (fscanf(fp, "%d", &key) != EOF)
        insertNode(key);

    printList();
    printf("Deleting 22 ..\n");
    deleteNode(22);
    printList();
    printf("Insert -10 ..\n");
    insertNode(-10);
    printList();
    printf("Insert 200 ..\n");
    insertNode(200);
    printList();
    printf("Deleting -10 ..\n");
    deleteNode(-10);
    printList();
}