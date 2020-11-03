// Polynomial Evaluation.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct polyNode{
	int coeff;
	int expo;
	struct polyNode *next;
};

struct polyNode *start1 = NULL;
struct polyNode *start2 = NULL;
struct polyNode *start3 = NULL;
struct polyNode *start4 = NULL;
struct polyNode *create_poly(struct polyNode *);
struct polyNode *display_poly(struct polyNode *);
struct polyNode *add_poly(struct polyNode *, struct polyNode *, struct polyNode *);
struct polyNode *sub_poly(struct polyNode *, struct polyNode *, struct polyNode *);
struct polyNode *add_node(struct polyNode *, int, int);

int main(){
	int option;
	printf("\n***MAIN MENU***");
	printf("\n1. Enter \'FIRST\' polynomial.");
	printf("\n2. Display \'FIRST\' polynomial.");
	printf("\n3. Enter \'SECOND\' polynomial.");
	printf("\n4. Display \'SECOND\' polynomial.");
	printf("\n5. \'ADD\' the polynomials.");
//	printf("\n6. Display the Result of Polynomial Additon.");
	printf("\n7. \'SUBTRACT\' the polynomials.");
//	printf("\n8. Display the Result of Polynomial Subtraction.");
	printf("\n9. Exit");
	do{
		printf("\nEnter your Option - ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				start1 = create_poly(start1);
				break;
			case 2:
				start1 = display_poly(start1);
				break;
			case 3:
				start2 = create_poly(start2);
				break;
			case 4:
				start2 = display_poly(start2);
				break;
			case 5:
				start3 = add_poly(start1, start2, start3);
				break;
//			case 6:
//				start3 = display_poly(start3);
//				break;
			case 7:
				start4 = sub_poly(start1, start2, start4);
				break;
//			case 8:
//				start4 = display_poly(start4);
//				break;
		}
	}while(option != 9);
	return 0;
}

struct polyNode *create_poly(struct polyNode *start){
	struct polyNode *ptr, *new_node;
	int coefficient, exponent;
	printf("\nEnter the Coefficient - ");
	scanf("%d", &coefficient);
	printf("Enter the Exponent - ");
	scanf("%d", &exponent);
	while(coefficient != 0){
		if (start == NULL){
			new_node = (struct polyNode *)malloc(sizeof(struct polyNode *));
			new_node->coeff = coefficient;
			new_node->expo = exponent;
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr->next != NULL)
				ptr = ptr->next;
			new_node = (struct polyNode *)malloc(sizeof(struct polyNode *));
			new_node->coeff = coefficient;
			new_node->expo = exponent;
			new_node->next = NULL;
			ptr->next = new_node;
		}
		printf("\nEnter the Coefficient - ");
		scanf("%d", &coefficient);
		if (coefficient == 0)
			break;
		printf("Enter the Exponent - ");
		scanf("%d", &exponent);
	}
	return start;
}

struct polyNode *display_poly(struct polyNode *start){
	struct polyNode *ptr;
	ptr = start;
	if (ptr == NULL)
		printf("\tUNDERFLOW.\n");
	else{
		printf("\n\t");
		while (ptr != NULL){
			printf("(%d x^%d) + ", ptr->coeff, ptr->expo);
			ptr = ptr->next;
		}
		printf("0\n");
	}
	return start;
}

struct polyNode *add_poly(struct polyNode *start1, struct polyNode *start2, struct polyNode *start3){
	struct polyNode *ptr1,*ptr2;
	int sum_coeff;
	ptr1 = start1;
	ptr2 = start2;
	while (ptr1 != NULL && ptr2 != NULL){
		if (ptr1->expo == ptr2->expo){
			sum_coeff =  ptr1->coeff + ptr2->coeff;
			start3 = add_node(start3, sum_coeff, ptr1->expo);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if (ptr1->expo > ptr2->expo){
			start3 = add_node(start3, ptr1->coeff, ptr1->expo);
			ptr1 = ptr1->next;
		}
		else if (ptr1->expo < ptr2->expo){
			start3 = add_node(start3, ptr2->coeff, ptr2->expo);
			ptr2 = ptr2->next;
		}
	}
	if (ptr1 == NULL){
		while (ptr2 != NULL){
			start3 = add_node(start3, ptr2->coeff, ptr2->expo);
			ptr2 = ptr2->next;
		}
	}
	if (ptr2 == NULL){
		while (ptr1 != NULL){
			start3 = add_node(start3, ptr1->coeff, ptr1->expo);
			ptr1 = ptr1->next;
		}
	}
	printf("\tAddition Result of the Polynomials =>\n");
	start3 = display_poly(start3);
	return start3;
}

struct polyNode *sub_poly(struct polyNode *start1, struct polyNode *start2, struct polyNode *start4){
	struct polyNode *ptr1,*ptr2;
	int diff_coeff;
	ptr1 = start1;
	ptr2 = start2;
	while (ptr1 != NULL && ptr2 != NULL){
		if (ptr1->expo == ptr2->expo){
			diff_coeff =  ptr1->coeff - ptr2->coeff;
			start4 = add_node(start4, diff_coeff, ptr1->expo);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if (ptr1->expo > ptr2->expo){
			start4 = add_node(start4, ptr1->coeff, ptr1->expo);
			ptr1 = ptr1->next;
		}
		else if (ptr1->expo < ptr2->expo){
			start4 = add_node(start4, (-1)*ptr2->coeff, ptr2->expo);
			ptr2 = ptr2->next;
		}
	}
	if (ptr1 == NULL){
		while (ptr2 != NULL){
			start4 = add_node(start4, ptr2->coeff, ptr2->expo);
			ptr2 = ptr2->next;
		}
	}
	if (ptr2 == NULL){
		while (ptr1 != NULL){
			start4 = add_node(start4, ptr1->coeff, ptr1->expo);
			ptr1 = ptr1->next;
		}
	}
	printf("\tSubtraction Result of the Polynomials =>\n");
	start4 = display_poly(start4);
	return start4;
}

struct polyNode *add_node(struct polyNode *start, int value, int exponent){
	struct polyNode *ptr, *new_node;
	new_node = (struct polyNode *)malloc(sizeof(struct polyNode *));
	new_node->coeff = value;
	new_node->expo = exponent;
	new_node->next = NULL;
	if (start == NULL)
		start = new_node;
	else{
		ptr = start;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
	return start;
}

