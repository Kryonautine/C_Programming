#include <stdio.h>
#include <stdlib.h>

typedef struct ele{
	int num;
	struct ele *next;
} ele ;

void freeList(ele* head) {
	ele *fr;
}

void printArr(ele* head) {
	ele *arr;
	arr=head;
	for (int i=0; arr != NULL; i++) {
		printf("num %d = %d\n", i+1, (*arr).num); // arr->num.
		arr = arr->next;
	}
}

ele* scanele(ele *arr) {
	ele* new;
	new =(ele*) malloc(sizeof(ele));
	//*(new->next) = NULL;
	printf("Enter value :");
	scanf("%d", &new->num);
	new->next= arr;
	arr = new;// Doesn't seem to work.
}

int main(void) {
	int exit, choice;
	ele *arrstr = NULL;
	while (exit != 0) {
		printf("Press 1 for Print, 2 For Write :");
		scanf("%d", &choice);
		if (choice == 2) {
			arrstr = scanele(arrstr);
		}
		if (choice == 1) {
			printArr(arrstr);
		}
		printf("Do you wish to exit? Press 0 to exit, else press 1 to repeat :");
		scanf("%d", &exit);
	}
	// Freeing data is necessary.
}