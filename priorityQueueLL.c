// priority Queue Linked List.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct pQueue{
	int data, prio;
	struct pQueue *next;
};

struct pQueue *front = NULL;
struct pQueue *rear = NULL;
struct pQueue *insert(struct pQueue *);
struct pQueue *delete_element(struct pQueue *);
struct pQueue *display(struct pQueue *);
struct pQueue *peek(struct pQueue *);
struct pQueue *sort_list(struct pQueue *)

int main(){
	int option;
	do{
		printf("\n***MAIN MENU***");
		printf("\n1. Insert into Queue");
		printf("\n2. Delete from Queue");
		printf("\n3. Peek at Queue");
		printf("\n4. Display Queue");
		printf("\n5. Exit");
		printf("\nEnter your Option - ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				start = insert(start);
				break;
			case 2:
				start = delete_element(start);
				break;
			case 3:
				start = peek(start);
				break;
			case 4:
				start = display(start);
				break;
		}
	}while(option != 5);
	return 0;
}

struct pQueue *insert(struct pQueue *){
	struct pQueue *ptr;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	ptr = (struct pQueue *)malloc(sizeof(struct pQueue *));
	ptr->data = num;
	if (front == NULL){
		front = ptr;
		rear = ptr;
		front->next = rear->next = NULL;
	}
	else{
		rear->next = ptr;
		rear = ptr;
		rear->next = NULL;
	}
	return start;
}

struct pQueue *delete_element(struct pQueue *){
	struct pQueue *ptr;
	ptr = front;
	if (front == NULL)
		printf("\tQUEUE UNDERFLOW.\n");
	else{
		printf("\nElement Deleted is %d.\n", ptr->data);
		front = front->next;
		free(ptr);		
	}
	return start;
}

struct pQueue *peek(struct pQueue *){
	if (front == NULL)
		printf("\tQUEUE UNDERFLOW.\n");
	else
		for 
		printf("\nElement at Front of Queue is %d.\n", front->data);
	return start;
}

struct pQueue *display(struct pQueue *){
	struct pQueue *ptr;
	if (front == NULL)
		printf("\tQUEUE UNDERFLOW.\n");
	else{
		printf("\n");
		ptr = front;
		while (ptr != NULL){
			printf("\t %d", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	return start;
}

struct pQueue *sort_list(struct pQueue *start){
	struct pQueue *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while (ptr1->next != NULL){
		ptr2 = ptr1->next;
		while (ptr2 != NULL){
			if (ptr1->data > ptr2->data){
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr1->next;
		}
		return start;
	}
}

