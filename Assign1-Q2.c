// A priority queue stores a set of keys (priorities) and their associated values. This assignment
// models a hospital waiting room as a priority queue. If two patients in the queue have the same
// priority, you will break ties by choosing the patient who arrived earliest with that priority. This
// means that if a patient arrives at priority K and there are already other patients in the queue with
// priority K, your new patient should be placed after them.
// For example, if the following patients arrive at the hospital in this order:
// "D" with priority 5
// "B" with priority 4
// "A" with priority 8
// "W" with priority 5
// "T" with priority 5
// "F" with priority 2
// Then if you were to dequeue the patients to process them, they would come out in this order: 
// - F, B, D, W, T, A.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define PRI 10

char pqueue[PRI][MAX];
int front[PRI] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; 
int rear[PRI] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void enqueue();
void dequeue();
void display();
void circular(int );

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
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nThank You, EXIT.");			
		}
	}while(option != 4);
	return 1;
}

void enqueue(){
	char init_name;
	int priority, i;
	
	printf("\nEnter Name to be Inserted - ");
	scanf(" %c", &init_name);
	do{
		printf("Enter Priority of Person Inserted - ");
		scanf("%d", &priority);
		if (priority < 1 && priority > PRI)
			printf("\tEnter Again - ");
	}while(priority < 1 && priority > PRI);
	
	if (front[priority-1] == 0 && rear[priority-1] == MAX-1){
		printf("\n\t OVERFLOW \n");
		return;
	}
	else if (front[priority-1] == -1 && rear[priority-1] == -1)
		front[priority-1] = rear[priority-1] = 0;
	else if (front[priority-1] != 0 && rear[priority-1] == MAX - 1)
		rear[priority-1] = 0;
	else
		rear[priority-1] ++;
	pqueue[priority-1][rear[priority-1]] = init_name;
}

void dequeue(){
	int row, col, flag = 0, i;

	for (row = 0;row < PRI; row++){
		if (front[row] > rear[row]){
			for (col = front[row]; col < MAX; col++){
				if (pqueue[row][col] != '\0'){
					printf("\nName With Highest Priority - %c", pqueue[row][col]);
					pqueue[row][col] = '\0';
					circular(row);
					flag = 1;
					break;
				}
			}
			for (col = 0; col <= rear[row]; col++){
				if (flag == 1)
					break;
				if (pqueue[row][col] != '\0'){
					printf("\nName With Highest Priority - %c", pqueue[row][col]);
					pqueue[row][col] = '\0';
					circular(row);
					flag = 1;
					break;
				}
			}
		}
		else{
			for (col = front[row]; col <= rear[row]; col++){
				if (pqueue[row][col] != '\0'){
					printf("\nName With Highest Priority - %c", pqueue[row][front[row]]);
					pqueue[row][col] = '\0';
					circular(row);
					flag = 1;					
					break;
				}
			}
		}
		
		if (flag == 1)
			break;
		else if (row == PRI-1 && flag == 0)
			printf("\n\tQUEUE IS EMPTY\n");
	}
	printf("\n");
}

void circular(int row){
	if (front[row] == rear[row])
		front[row] = rear[row] = -1;
	else{
		if (front[row] == MAX - 1)
			front[row] = 0;
		else
			front[row] ++;	
	}
}

void display(){
	int i, j;
	for (i = 0; i < PRI; i++){
		if (front[i] == -1 && rear[i] == -1)
			printf("\n Priority QUEUE %d - UNDERFLOW", i+1);
		else{
			printf("\n Priority QUEUE %d -", i+1);
			if (front[i] <= rear[i]){
				for (j = front[i]; j <= rear[i]; j++)
					printf("\t %c", pqueue[i][j]);
			}
			else{
				for (j = front[i]; j < MAX; j++)
					printf("\t %c", pqueue[i][j]);
				for (j = 0; j <= rear[i]; j++)
					printf("\t %c", pqueue[i][j]);
			}
		}
	}
	printf("\n");
}

