// Linked Implementation of Stack.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *top = NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
struct node *display(struct node *);
void peek(struct node *);

int main(){
	int option;
	do{
		printf("\n***MAIN MENU***");
		printf("\n1. Push into Stack");
		printf("\n2. Pop from Stack");
		printf("\n3. Peek at Stack");
		printf("\n4. Display Stack");
		printf("\n5. Exit");
		printf("\nEnter your Option - ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				top = push(top);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				peek(top);
				break;
			case 4:
				top = display(top);
				break;
		}
	}while(option != 5);
	return 0;
}

struct node *push(struct node *top){
	struct node *new_node;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node *));
	new_node->data = num;
	if (top == NULL){
		new_node->next = NULL;
		top = new_node;
	}
	else{
		new_node->next = top;
		top = new_node;
	}
	return top;
}

struct node *pop(struct node *top){
	struct node *temp;
	if (top == NULL)
		printf("\tSTACK UNDERFLOW.\n");
	else{
		temp = top;
		printf("\nElement Popped Out is %d.\n", top->data);
		top = top->next;
		free(temp);
	}
	return top;		
}

void peek(struct node *top){
	if (top == NULL)
		printf("\tSTACK UNDERFLOW.\n");
	else
		printf("\nElement at Top of Stack is %d.\n", top->data);
}

struct node *display(struct node *top){
	struct node *ptr;
	if (top == NULL)
		printf("\tSTACK UNDERFLOW.\n");
	else{
		printf("\n");
		ptr = top;
		while (ptr != NULL){
			printf("\t %d", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	return top;
}


