// Circular Singly LinkedList

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *createLL(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *display(struct node *);

int main(){
	int option;
	do{
		printf("\n* * * MAIN MENU * * *");
		printf("\n1. Create a LinkedList");
		printf("\n2. Display the LinkedList");
		printf("\n3. Insert Node at Beginning");
		printf("\n4. Insert Node at End");
		printf("\n5. Delete Node at Beginning");
		printf("\n6. Delete Node at End");
		printf("\n7. EXIT");
		printf("\nEnter your Option - ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				start = createLL(start);
				printf("\n\tCircular Singly LinkedList created.\n");
				break;
			case 2:
				start = display(start);
				break;
			case 3:
				start = insert_beg(start);
				break;
			case 4:
				start = insert_end(start);
				break;
			case 5:
				start = delete_beg(start);
				break;
			case 6:
				start = delete_end(start);
				break;
		}
	}while(option != 7);
	return 0;
}

struct node *createLL(struct node *start){
	struct node *newnode, *ptr;
	int val;
	printf("\n Enter -1 to End");
	printf("\n Enter the data - ");
	scanf("%d", &val);
	while(val != -1){
		newnode = (struct node *)malloc(sizeof(struct node *));
		newnode->data = val;
		if (start == NULL){
			newnode->next = newnode;
			start = newnode;
		}
		else{
			ptr = start;
			while(ptr->next != start){
				ptr = ptr->next;
			}
			ptr->next = newnode;
			newnode->next = start;
		}
		printf("\n Enter the data - ");
		scanf("%d", &val);
	}
	return start;
}

struct node *insert_beg(struct node *start){
	struct node *newnode, *ptr;
	int val;
	printf("\nEnter the data - ");
	scanf("%d", &val);
	newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = val;
	ptr = start;
	while(ptr->next != start){
		ptr = ptr->next;
	}
	ptr->next = newnode;
	newnode->next = start;
	start = newnode;
	return start;
}

struct node *insert_end(struct node *start){
	struct node *newnode, *ptr;
	int val;
	printf("\nEnter the data - ");
	scanf("%d", &val);
	newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = val;
	ptr = start;
	while (ptr->next != start){
		ptr = ptr->next;
	}
	ptr->next = newnode;
	newnode->next = start;
	return start;
}

struct node *delete_beg(struct node *start){
	struct node *ptr;
	if (start == NULL){
		printf("\n\tUNDERFLOW.\n");
		return start;
	}	
	ptr = start;
	while(ptr->next != start){
		ptr = ptr->next;
	}
	ptr->next = start->next;
	printf("\nElement Deleted - %d\n", start->data);
	free(start);
	start = ptr->next;
	return start;
}

struct node *delete_end(struct node *start){
	struct node *ptr, *preptr;
	if (start == NULL){
		printf("\n\tUNDERFLOW.\n");
		return start;
	}	
	ptr = start;
	while(ptr->next != start){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = ptr->next;
	printf("\nElement Deleted - %d\n", ptr->data);
	free(ptr);
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	if (start == NULL){
		printf("\n\tUNDERFLOW.\n");
		return start;
	}
	ptr = start;
	printf("\n");
	while(ptr->next != start){
		printf("\t %d", ptr->data);
		ptr = ptr->next;
	}
	printf("\t %d\n", ptr->data);
	return start;
}




