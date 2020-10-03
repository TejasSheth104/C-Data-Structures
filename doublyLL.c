// Doubly Linked List

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main(){
	int option;
	do{
		printf("\n***MAIN MENU***");
		printf("\n1. Create a List");
		printf("\n2. Display the List");
		printf("\n3. Add a Node at the beginning");
		printf("\n4. Add a Node at the end");
		printf("\n5. Add a Node before a given Node");
		printf("\n6. Add a Node after a given Node");
		printf("\n7. Delete a Node from the beginning");
		printf("\n8. Delete a Node from the end");
		printf("\n9. Delete a Node before a given Node");
		printf("\n10. Delete a Node after a given Node");
		printf("\n11. Delete the entire List");
		printf("\n12. EXIT");
		printf("\nEnter your Option - ");
		scanf("%d", & option);
		
		switch(option){
			case 1:
				start = create_ll(start);
				printf("\n Doubly Linked List Created");
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
				start = insert_before(start);
				break;
			case 6:
				start = insert_after(start);
				break;
			case 7:
				start = delete_beg(start);
				break;
			case 8:
				start = delete_end(start);
				break;
			case 9:
				start = delete_before(start);
				break;
			case 10:
				start = delete_after(start);
				break;
			case 11:
				start = delete_list(start);
				printf("\n Doubly Linked List Deleted");
				break;
		}
	}while (option != 12);
	return 0;
}

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to End");
	printf("\n Enter the data - ");
	scanf("%d", &num);
	while (num != -1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if (start == NULL){
			new_node->prev = NULL;
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while (ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->prev = ptr;
			new_node->next = NULL;
		}
		printf("\n Enter the data - ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while (ptr != NULL){
		printf("\t %d", ptr->data);
		ptr = ptr->next;
	}
	return start;
}

struct node *insert_beg(struct node *start){
	struct node *new_node;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	start->prev = new_node;
	new_node->next = start;
	new_node->prev = NULL;
	start = new_node;
	return start;
}

struct node *insert_end(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;
	ptr = start;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = NULL;
	return start;
}

struct node *insert_before(struct node *start){
	struct node *new_node, *ptr;
	int val, num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	printf("\nEnter the Value before which the data has to be inserted - ");
	scanf("%d", &val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while (ptr->data != val){
		ptr = ptr->next;
	}
	new_node->next = ptr;
	new_node->prev = ptr->prev;
	ptr->prev->next = new_node;
	ptr->prev = new_node;
	return start;
}

struct node *insert_after(struct node *start){
	struct node *new_node, *ptr;
	int val, num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	printf("\nEnter the Value after which the data has to be inserted - ");
	scanf("%d", &val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while (ptr->data != val){
		ptr = ptr->next;
	}
	new_node->prev = ptr;
	new_node->next = ptr->next;
	ptr->next->prev = new_node;
	ptr->next = new_node;
	return start;
}

struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start){
	struct node *ptr;
	ptr = start;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->prev->next = NULL;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start){
	struct node *ptr, *temp;
	int val;
	printf("\nEnter the Value after which the Node has to be deleted - ");
	scanf("%d", &val);
	ptr = start;
	while (ptr->data != val){
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	return start;
}

struct node *delete_before(struct node *start){
	struct node *ptr, *temp;
	int val;
	printf("\nEnter the Value before which the Node has to be deleted - ");
	scanf("%d", &val);
	ptr = start;
	while (ptr->data != val){
		ptr = ptr->next;
	}
	temp = ptr->prev;
	if (temp == start)
		start = delete_beg(start);
	else{
		ptr->prev = temp->prev;
		temp->prev->next = ptr;
	}
	free(temp);
	return start;
}

struct node *delete_list(struct node *start){
	while (start != NULL){
		start = delete_beg(start);
	}
	return start;
}

