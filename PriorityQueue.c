// Priority Queue Implementation using 2 different Arrays.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

// both as Integer arrays.
int pri_queue[MAX], queue[MAX];
int front = -1, rear = -1;

void insert_pri();
void delete_highest_pri();
void display_pri();

int main(){
	int option;
	printf("\n\n ***** MAIN MENU *****");
	printf("\n1. Insert an Element, with Priority ");
	printf("\n2. Delete an Element of Highest Priority");
	printf("\n3. Display the Queue ");
	printf("\n4. Exit ");
	do{
		printf("\nEnter your Option -  ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_pri();
				break;
			case 2:
				delete_highest_pri();
				break;
			case 3:
				display_pri();
				break;
			case 4:
				printf("\nThank You, EXIT.\n");			
		}
	}while(option != 4);
	return -1;
}

void insert_pri(){
	int input, priority;
	printf("\n");
	printf("Enter Number to be Inserted - ");
	scanf("%d", &input);
	printf("Enter Priority of Number Inserted - ");
	scanf("%d", &priority);
	
	if (front == -1 && rear == -1)
		front = rear = 0;
	else if ((front == 0 && rear == MAX - 1) || front == rear + 1){
		printf("\n\tQUEUE IS FULL.");
		return;
	}
//	else if (front != 0 && rear == MAX - 1)
//		rear = 0;
	else
		rear ++;
	
	queue[rear] = input;
	pri_queue[rear] = priority;
}

void delete_highest_pri(){
	int smallest, index = 0, i;
	smallest = pri_queue[0];
	
	if (front == -1 && rear == -1){
		printf("\n\tQUEUE IS EMPTY.");
		return;
	}
		
	for (i = 1; i <= rear; i++){
		if (pri_queue[i] < smallest){
			smallest = pri_queue[i];
			index = i;
		}
	}

	printf("\nElement with Highest Priority = %d", queue[index]);
	for (i = index; i <= rear; i++){
		queue[i] = queue[i+1];
		pri_queue[i] = pri_queue[i+1];
	}
	rear--;
	if (front > rear)
		front = rear = -1;
}

void display_pri(){
	int i;
	if (front == -1 && rear == -1) //|| front == rear)
		printf("\n\tQUEUE IS EMPTY.");
	else{
		for (i = front; i <= rear; i++){
			printf("\n\t%d,\t p- %d", queue[i], pri_queue[i]);
		}
	}
	
}

