// Linked Implementation of Stack.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
	int data;
	struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *);
void peek(struct stack *);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);

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

struct stack *push(struct stack *top){
	struct stack *ptr;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	ptr = (struct stack *)malloc(sizeof(struct stack *));
	ptr->data = num;
	if (top == NULL){
		ptr->next = NULL;
		top = ptr;
	}
	else{
		ptr->next = top;
		top = ptr;
	}
	return top;
}

struct stack *pop(struct stack *top){
	struct stack *temp;
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

void peek(struct stack *top){
	if (top == NULL)
		printf("\tSTACK UNDERFLOW.\n");
	else
		printf("\nElement at Top of Stack is %d.\n", top->data);
}

struct stack *display(struct stack *top){
	struct stack *ptr;
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


