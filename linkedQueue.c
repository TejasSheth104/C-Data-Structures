// Linked Implementation of Queue.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct queue{
	int data;
	struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;
void insert();
void delete_element();
void display();
void peek();

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
				insert();
				break;
			case 2:
				delete_element();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
		}
	}while(option != 5);
	return 0;
}

void insert(){
	struct queue *ptr;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	ptr = (struct queue *)malloc(sizeof(struct queue *));
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
}

void delete_element(){
	struct queue *ptr;
	ptr = front;
	if (front == NULL)
		printf("\tQUEUE UNDERFLOW.\n");
	else{
		printf("\nElement Deleted is %d.\n", ptr->data);
		front = front->next;
		free(ptr);		
	}
}

void peek(){
	if (front == NULL)
		printf("\tQUEUE UNDERFLOW.\n");
	else
		printf("\nElement at Front of Queue is %d.\n", front->data);
}

void display(){
	struct queue *ptr;
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
}




