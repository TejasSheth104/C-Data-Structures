// implementation of STACK using Array.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 3

int st[MAX], top = -1;  
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(){
// Main Menu
	int val, option;
	do{
		printf("\n\nMAIN MENU -");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n5. EXIT");
		printf("\nEnter - ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("Enter Number to PUSH to the Stack - ");
				scanf("%d", &val);
				push(st, val);
				break;
			case 2:
				val = pop(st);
				if (val != -1)
					printf("Value Deleted is - %d", val, "\n");
				break;
			case 3:
				val = peek(st);
				if (val != -1)
					printf("Value at the TOP of Stack is - %d", val, "\n");
				break;
			case 4:
				display(st);
				break;
		}	
	}while(option != 5);
	
	return 0;
}

// push function, takes Stack Array and an integer value as input.
void push(int st[], int val){
	if (top == MAX - 1)
		printf("STACK OVERFLOW");
	else{
		top ++;
		st[top] = val;
	}
}

// pop function, takes Stack Array as input, and returns and removes Stack Top
int pop(int st[]){
	int val;
	if (top == -1){
		printf("STACK UNDERFLOW");
		return -1;
	}
	else{
		val = st[top];
		top --;
		// val = st[top--];
		return val;
	}
}

// peep function, takes stack array as input and returns Stack Top 
int peek(int st[]){
	if (top == -1){
		printf("STACK EMPTY");
		return -1;
	}
	else{
		return (st[top]);
	}
}

// display fucntion, displays the stack in proper order.
void display(int st[]){
	int i;
	if (top == -1)
		printf("STACK EMPTY");
	else{
		for (i=top; i>=0; i--){
			printf("\n %d", st[i], "\n");
		}
	}
}






