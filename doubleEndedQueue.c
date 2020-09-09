// Double Ended Queue

#include<stdio.h>
#include<conio.h>
#define MAX 10
int deque[MAX];
int left = -1, right = -1;

void input_deque();
void output_deque();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

int main(){
	int option;
	printf("\n\n ***** MAIN MENU *****");
	printf("\n1. Input Restricted Deque ");
	printf("\n2. Output Restricted Deque ");
	printf("\nEnter your Option -  ");
	scanf("%d", &option);
	switch(option){
		case 1:
			input_deque();
			break;
		case 2:
			output_deque();
			break;
	}
	return 0;
}

void input_deque(){
	int option;
	do{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n1. Insert at Right ");
		printf("\n2. Delete from Left ");
		printf("\n3. Delete from Left ");
		printf("\n4. Display the Queue ");
		printf("\n5. Exit ");
		printf("\nEnter your Option -  ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_right();
				break;
			case 2:
				delete_left();
				break;
			case 3:
				delete_left();
				break;
			case 4:
				display();
		}
	}while(option != 5);
}

void output_deque(){
	int option;
	do{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n1. Insert at Right ");
		printf("\n2. Insert from Left ");
		printf("\n3. Delete from Left ");
		printf("\n4. Display the Queue ");
		printf("\n5. Exit ");
		printf("\nEnter your Option -  ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_right();
				break;
			case 2:
				insert_left();
				break;
			case 3:
				delete_left();
				break;
			case 4:
				display();
		}
	}while(option != 5);
}

void insert_right(){
	int num;
	printf("\nEnter Number to be inserted - ");
	scanf("%d", &num);
	if ((left == 0 && right == MAX-1) || left == right + 1){
		printf("\n OVERFLOW ");
		return;
	}
	if (left == -1)
		left = right = 0;
	else{
		if (right == MAX - 1)
			right = 0;
		else
			right ++;
	}
	deque[right] = num;
}

void insert_left(){
	int num;
	printf("\nEnter Number to be inserted - ");
	scanf("%d", &num);
	if ((left == 0 && right == MAX-1) || left == right + 1){
		printf("\n OVERFLOW ");
		return;
	}
	if (left == -1)
		left = right = 0;
	else{
		if (left == 0)
			left = MAX - 1;
		else
			left ++;
	}
	deque[left] = num;
}

void delete_left(){
	if (left == -1){
		printf("\n UNDERFLOW ");
		return ;
	}
	printf("Value Deleted is %d", deque[left]);
	if (left == right)
		left = right = -1;
	else{
		if (left == MAX - 1)
			left == 0;
		else
			left ++;	
	}
}

void delete_right(){
	if (left == -1){
		printf("\n UNDERFLOW ");
		return ;
	}
	printf("Value Deleted is %d", deque[left]);
	if (left == right)
		left = right = -1;
	else{
		if (right == MAX - 1)
			right == MAX - 1;
		else
			right ++;	
	}
}

void display(){
	int front = left, rear = right;
	if (front == -1){
		printf("\n QUEUE IS EMPTY ");
		return ;
	}
	printf("\n");
	printf("\nThe Elements of the Queue are - ");
	if (front <= rear){
		while (front <= rear){
			printf("\t %d", deque[front]);
			front ++;
		}
	}
	else{
		while (front <= MAX - 1){
			printf("\t %d", deque[front]);
			front ++;
		}
		front = 0;
		while (front <= rear){
			printf("\t %d", deque[front]);
			front ++;
		}
	}
	printf("\n");
}

