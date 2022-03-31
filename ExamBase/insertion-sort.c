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
void scanele(ele **arr) {
	int cont=1;
	while (cont == 1) {
		ele *new;
		new = (ele *)malloc(sizeof(ele));

		//*(new->next) = NULL;
		printf("Enter value :");
		scanf("%d", &new->num);

		new->next = *arr;
		*arr = new;

		printf("Enter 0 to exit loop, else enter 1 :");
		scanf("%d", &cont);
	}
}

// Uses bubbleSort.
void sortList(ele **arrstr) {

}

// Use insertion Sort.
void sortAdd(ele **arrstr) {

}

int main(void)
{
	int choice = -1;
	ele *arrstr = NULL;
	while (choice != 0)
	{
		printf("Press 0 to exit, 1 for Print, 2 For Write, 3 to sort,\n4 to add element to sorted array, 5 to free the complete list :");
		scanf("%d", &choice);

		// If number of possiblities for choices > 5, change to switch case.
		switch (choice) {
			case 1:
				printArr(arrstr);
				break;

			case 2:
				scanele(&arrstr);
				break;

			case 3:
				// Currently does not sort.
				sortList(&arrstr);
				break;

			case 4:
				// Does not work currently.
				sortAdd(&arrstr);
				break;

			case 5:
				freelist(&arrstr);
				break;
			
			default:
				printf("Enter a valid Answer\n");
		}
	}

	// Freeing remaining data at end of program.
	freeList(&arrstr);
}