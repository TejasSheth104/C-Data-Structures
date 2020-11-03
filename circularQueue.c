// Circular Queue
// mask the disadvantage of Linear Queue

#include<stdio.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void enque();
void deque();
void peek();
void display();

int main(){
	int option;
	do{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n1. Insert an Element ");
		printf("\n2. Delete an Element ");
		printf("\n3. Peek ");
		printf("\n4. Display the Queue ");
		printf("\n5. Exit ");
		printf("\nEnter your Option -  ");
		scanf("%d", &option);
		switch(option){
			case 1:
				enque();
				break;
			case 2:
				deque();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
		}
	}while(option != 5);
	return 0;
}

void enque(){
	int num;
	printf("\nEnter Number to be inserted - ");
	scanf("%d", &num);
	if (front == 0 && rear == MAX-1){
		printf("\n OVERFLOW ");
		return;
	}
	else if (front == -1 && rear == -1)
		front = rear = 0;
	else if (front != 0 && rear == MAX - 1)
		rear = 0;
	else
		rear ++;
	queue[rear] = num;
}

void deque(){
	if (front == -1 && rear == -1){
		printf("\n UNDERFLOW ");
		return ;
	}
	printf("\nValue Deleted is %d", queue[front]);
	if (front == rear)
		front = rear = -1;
	else{
		if (front == MAX - 1)
			front = 0;
		else
			front ++;	
	}
}

void peek(){
	if (front == -1){
		printf("\n QUEUE IS EMPTY ");
		return ;
	}
	else
		printf("\nValue in Front is - %d", queue[front]);
}

void display(){
	int i;
	printf("\n");
	if (front == -1){
		printf("\n QUEUE IS EMPTY ");
		return ;
	}
		if (front < rear){
			for (i = front; i <= rear; i++)
				printf("\t %d", queue[i]);
		}
		else{
			for (i = front; i < MAX; i++)
				printf("\t %d", queue[i]);
			for (i = 0; i <= rear; i++)
				printf("\t %d", queue[i]);
		}
}


