#include <stdio.h>
#include <stdlib.h>

typedef struct ele{
	int num;
	struct ele *next;
} ele ;

// Function to free entire linked list. Takes a ptr to the head of list.
void freeList(ele **head) {
	ele *fr;

	while ((*head) != NULL) {
		fr = *head;
		(*head) = (*head)->next;
		free(fr);
	}
}

// Takes a linked list and prints every element in it.
void printArr(ele *head)
{
	ele *arr;
	arr = head;
	for (int i = 0; arr != NULL; i++)
	{
		printf("num %d = %d\n", i + 1, (*arr).num); // arr->num.
		arr = arr->next;
	}
}

// Takes pointer to a head of linked list and adds an element to front of the list.
void scanele(ele **arr)
{
	ele *new;
	new = (ele *)malloc(sizeof(ele));
	//*(new->next) = NULL;
	printf("Enter value :");
	scanf("%d", &new->num);
	new->next = *arr;
	*arr = new;
}

int main(void)
{
	int exit, choice;
	ele *arrstr = NULL;
	while (exit != 0)
	{
		printf("Press 1 for Print, 2 For Write, 5 to free the complete list :");
		scanf("%d", &choice);

		// If number of possiblities for choices > 5, change to switch case.
		if (choice == 2)
		{
			scanele(&arrstr);
		}

		if (choice == 1)
		{
			printArr(arrstr);
		}

		if (choice == 5) {
			freeList(&arrstr);
		}

		printf("Do you wish to exit? Press 0 to exit, else press 1 to repeat :");
		scanf("%d", &exit);
	}

	// Freeing remaining data at end of program.
	freeList(&arrstr);
}