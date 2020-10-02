// Singly Linked List

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
struct node *sort_list(struct node *);

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
	new_node->next = start;
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
	return start;
}

struct node *insert_before(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int val, num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	printf("\nEnter the Value after which the data has to be inserted - ");
	scanf("%d", &val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	preptr = ptr;
	while (ptr->data != val){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = new_node;
	new_node->next = ptr;
	return start;
}

struct node *insert_after(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int val, num;
	printf("\nEnter the data - ");
	scanf("%d", &num);
	printf("\nEnter the Value after which the data has to be inserted - ");
	scanf("%d", &val);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	preptr = ptr;
	while (preptr->data != val){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = new_node;
	new_node->next = ptr;
	return start;
}

struct node *delete_before(struct node *start){
	struct node *ptr, *preptr;
	int val, temp;
	printf("\nEnter the Value of the Node which has to be deleted - ");
	scanf("%d", &val);
	ptr = start;
	if (ptr->data == val){
		start = delete_beg(start);
		return start;
	}
	else{
		while (ptr->data != val){
			preptr = ptr;
			ptr = ptr->next;
		}
//		temp = ptr;
		preptr->next = ptr->next;
//		free(temp);
		free(ptr);
		return start;
	}
}

struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start->next;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start){
	struct node *ptr, *preptr;
	ptr = start;
	while (ptr->next != NULL){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = NULL;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start){
	struct node *ptr, *preptr;
	int val, temp;
	printf("\nEnter the Value after which the Node has to be deleted - ");
	scanf("%d", &val);
	ptr = start;
	preptr = ptr;
	while (preptr->data != val){
		preptr = ptr;
		ptr = ptr->next;
	}
//	temp = ptr;
	preptr->next = ptr->next;
//	free(temp);
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start){
	struct node *ptr;
	
	if (start != NULL){
		ptr = start;		
		while (ptr != NULL){
			printf("\n %d is to be deleted next", ptr->data);
			start = delete_beg(ptr);
			ptr = start;
		}
	}
	return start;
}

struct node *sort_list(struct node *start){
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while (ptr1->next != NULL){
		ptr2 = ptr1->next;
		while (ptr2 != NULL){
			if (ptr1->data > ptr2->data){
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr1->next;
		}
		return start;
	}
}

