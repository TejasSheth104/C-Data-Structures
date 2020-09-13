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
// Then if you were to dequeue the patients to process them, they would come out in this order: 
// - Ford, Bernard, Dolores, William, Teddy, Arnold.

#include<stdio.h>
#include<string.h>
#define MAX 10
#define len 100

int pri_queue[MAX];			// <integer array> stores MAximum MAX integers.
char queue[MAX][len]; 		// <string array> stores Maximum MAX strings of len Characters each.
int front = -1, rear = -1;

void insert_pri();
void delete_highest_pri();
void display_pri();

int main(){
	int option;
	printf("\n\t ***** MAIN MENU *****");
	printf("\n1. Insert Patient, with Priority ");
	printf("\n2. Dequeue a Patient of Highest Priority");
	printf("\n3. Display the Patient Queue ");
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
				printf("\nThank You, EXIT.");			
		}
	}while(option != 4);
	return 1;
}

void insert_pri(){
	char name[len];				// <character array> stores a String of Maximum len characters.
	int priority;
	
	printf("Enter Name to be Inserted - ");
	scanf("%s", name);
	printf("Enter Priority of Person Inserted - ");
	scanf("%d", &priority);
	
	if (front == -1 && rear == -1)
		front = rear = 0;
	else if (front == 0 && rear == MAX - 1){
		printf("\n\tQUEUE IS FULL.");
		return;
	}
	else
		rear ++;

	strcpy(&queue[rear][0], name);
	pri_queue[rear] = priority;
}

void delete_highest_pri(){
	int smallest, i, index = 0;
	smallest = pri_queue[0];
	
	if (front == -1 && rear == -1){
		printf("\n\tQUEUE IS EMPTY.\n");
		return;
	}
	for (i = 1; i <= rear; i++){			// finds the smallest number(HighestPriority) and its Index.
		if (pri_queue[i] < smallest){
			smallest = pri_queue[i];
			index = i;
		}
	}
	printf("\nPerson with Highest Priority => \"%s\", with Priority - %d \n", queue + index, pri_queue[index]);

	for (i = index; i <= rear; i++){		// sets val[n] = val[n+1]. 
		strcpy(&queue[i][0], &queue[i+1][0]);
		pri_queue[i] = pri_queue[i+1];
	}
	rear--;

	if (front > rear)						// executes only after the last element is deleted.
		front = rear = -1;

}

void display_pri(){
	int i;
	if (front == -1 && rear == -1)
		printf("\n\tQUEUE IS EMPTY.\n");
	else{
		for (i = front; i <= rear; i++){	// prints elements from front until rear.
			printf("\n\t>>> %s,\t p-> %d", queue + i, pri_queue[i]);
		}
		printf("\n");
	}	
}

