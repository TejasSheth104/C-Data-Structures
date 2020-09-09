// A priority queue stores a set of keys (priorities) and their associated values. This assignment
// models a hospital waiting room as a priority queue. If two patients in the queue have the same
// priority, you will break ties by choosing the patient who arrived earliest with that priority. This
// means that if a patient arrives at priority K and there are already other patients in the queue with
// priority K, your new patient should be placed after them.
// For example, if the following patients arrive at the hospital in this order:
// "Dolores" with priority 5
// "Bernard" with priority 4
// "Arnold" with priority 8
// "William" with priority 5
// "Teddy" with priority 5
// "Ford" with priority 2
// Then if you were to dequeue the patients to process them, they would come out in this order: Ford,
// Bernard, Dolores, William, Teddy, Arnold.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#define len 100

// both as Integer arrays.
int pri_queue[MAX];
char queue[MAX][len]; 	// stores Maximum MAX strings of len Characters each.
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
		printf("\n\nEnter your Option -  ");
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
	char name[len]; 
	int priority;
	
	printf("Enter Names to be Inserted - ");
	scanf("%s", name); 
//	gets(name);
	printf("Enter Priority of Person Inserted - ");
	scanf("%d", &priority);
	
	if (front == -1 && rear == -1)
		front = rear = 0;
	else if ((front == 0 && rear == MAX - 1) || front == rear + 1){
		printf("\n\tQUEUE IS FULL.");
		return;
	}
	else if (front != 0 && rear == MAX - 1)
		rear = 0;
	else
		rear ++;

	strcpy(&queue[rear][0], name);
	pri_queue[rear] = priority;
}

void delete_highest_pri(){
	int smallest, index = 0;
//	char val;
	int i, j;
	smallest = pri_queue[0];
	
	if (front == -1 && rear == -1){
		printf("\n\tQUEUE IS EMPTY.");
		return;
	}
	printf("HEllooo u there..3...\n");
	for (i = 1; i <= rear; i++){
		if (pri_queue[i] < smallest){
			smallest = pri_queue[i];
			index = i;
		}
	}
//	val = queue[index];
	// front > < rear conditions
	// check every MAX.
	printf("\nElement with Highest Priority = %s \n", queue + index);
//	for (j=0;j!='\0';j++){
//		printf("%s", queue[index][j]);
//	}
//	if (front == rear)
//		front = rear = -1;
	if (front > rear){
		for (i = index; i < MAX - 1; i++){
			strcpy(&queue[i][0], &queue[i+1][0]);
			pri_queue[i] = pri_queue[i+1];
		}
		
		strcpy(&queue[MAX-1][0], &queue[0][0]);			
		
		pri_queue[MAX-1] = pri_queue[0];
//		for (i = index; i < MAX - 1; i++){
		for (i = 0; i <= rear; i++){
			strcpy(&queue[i][0], &queue[i+1][0]);
			pri_queue[i] = pri_queue[i+1];
		}
		
		if (rear == 0)
			rear = MAX - 1;
		else
			rear--;
	}
	else{
//		for (i = index; i < MAX - 1; i++){
		for (i = index; i <= rear; i++){
//			for (j = 0; j < len; j++){
//				queue[i][j] = queue[i+1][j];
//			}
			strcpy(&queue[i][0], &queue[i+1][0]);
			pri_queue[i] = pri_queue[i+1];
		}
		rear--;
		
		// incomplete
		
	}
	

//	else{
//		if (front == MAX -1)
//			front = 0;
//		else
//			front ++;
//	}
}

void display_pri(){
	int i;
	if (front == -1 && rear == -1)
		printf("\n\tQUEUE IS EMPTY.");
	else{
		if (front > rear){
			for (i = front; i < MAX; i++){
				printf("\n\t%s,\t p- %d", queue + i, pri_queue[i]);
			}
			for (i = 0; i <= rear; i++){
				printf("\n\t%s,\t p- %d", queue + i, pri_queue[i]);
			}
		}
		else{
			for (i = front; i <= rear; i++){
				printf("\n\t%s,\t p- %d", queue + i, pri_queue[i]);
			}
		}
	}
	
}

