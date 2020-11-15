// Binary Search Tree

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *tree = NULL;
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void postorderTraversal(struct node *);
void inorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int height(struct node *);
struct node *deleteTree(struct node *);

int main(){
	int option, val;
	struct node *ptr;
	do{
		printf("\n*****-MAIN MENU-*****\n");
		printf("\n01. Insert Element");
		printf("\n02. PreOrder Traversal");
		printf("\n03. InOrder Traversal");
		printf("\n04. PostOrder Traversal");
		printf("\n05. Find the Smallest Element");
		printf("\n06. Find the Largest Element");
		printf("\n07. Delete an Element");
		printf("\n08. Count the Total Number of Nodes");
		printf("\n09. Count the Total Number of External Nodes");
		printf("\n10. Count the Total Number of Internal Nodes");
		printf("\n11. Determine the Height of the Tree");
		printf("\n12. Find the Mirror Image of the Tree");
		printf("\n13. Delete the Tree");
		printf("\n14. Exit");
		printf("\n\nEnter Your Option - ");
		scanf("%d", &option);
		switch (option){
			case 1:
				printf("\nEnter the value of new node - ");
				scanf("%d", &val);
				tree = insertElement(tree, val);
				break;
			case 2:
				printf("\nElements of Tree in PreOrder - ");
				preorderTraversal(tree);
				break;
			case 3:
				printf("\nElements of Tree in InOrder - ");
				inorderTraversal(tree);
				break;
			case 4:
				printf("\nElements of Tree in PostOrder - ");
				postorderTraversal(tree);
				break;
			case 5:
				ptr = findSmallestElement(tree);
				printf("\nSmallest Element is - %d", ptr->data);
				break;
			case 6:
				ptr = findLargestElement(tree);
				printf("\nLargest Element is - %d", ptr->data);
				break;
			case 7:
				printf("\nEnter the value to be Deleted - ");
				scanf("%d", &val);
				tree = deleteElement(tree, val);
				break;
			case 8:
				printf("\nTotal Number of Nodes is - %d", totalNodes(tree));
				break;
			case 9:
				printf("\nTotal Number of External Nodes is - %d", totalExternalNodes(tree));
				break;
			case 10:
				printf("\nTotal Number of Internal Nodes is - %d", totalInternalNodes(tree));
				break;
			case 11:
				printf("\nHeight of the Tree is - %d", height(tree));
				break;
			case 12:
				tree = mirrorImage(tree);
				break;
			case 13:
				tree = deleteTree(tree);
				break;
		}
	}while(option != 14);
	return 0;
}

struct node *insertElement(struct node *tree, int val){
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->right = NULL;
	ptr->left = NULL;
	if (tree == NULL){
		tree = ptr;
		tree->right = NULL;
		tree->left = NULL;
	}
	else{
		parentptr = NULL;
		nodeptr = tree;
		while (nodeptr != NULL){
			parentptr = nodeptr;
			if (val < nodeptr->data)
				nodeptr = nodeptr->left;
			else
				nodeptr = nodeptr->right;
		}
		if (val < parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}

void preorderTraversal(struct node *tree){
	if (tree != NULL){
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree){
	if (tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

void inorderTraversal(struct node *tree){
	if (tree != NULL){
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}

struct node *findSmallestElement(struct node *tree){
	if ((tree != NULL) || (tree->left == NULL))
		return tree;
	else
		return findSmallestElement(tree->left);
}

struct node *findLargestElement(struct node *tree){
	if ((tree != NULL) || (tree->right == NULL))
		return tree;
	else
		return findLargestElement(tree->right);
}

struct node *deleteElement(struct node *tree, int val){
	return tree;
}

struct node *mirrorImage(struct node *tree){
	struct node *temp;
	if (tree != NULL){
		mirrorImage(tree->left);
		mirrorImage(tree->right);
		temp = tree->left;
		tree->left = tree->right;
		tree->right = temp;
	}
}

int totalNodes(struct node *tree){
	if (tree == NULL)
		return 0;
	else{
		return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
	}
}

int totalExternalNodes(struct node *tree){
	if ((tree == NULL) || (tree ->left == NULL && tree->right == NULL))
		return 1;
	else{
		return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
	}
}

int totalInternalNodes(struct node *tree){
	if ((tree == NULL) || (tree ->left == NULL && tree->right == NULL))
		return 0;
	else{
		return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
	}
}

int height(struct node *tree){
	int leftHeight, rightHeight;
	if (tree == NULL)
		return -1;
	else
		leftHeight = height(tree->left);
		rightHeight = height(tree->right);
		if (leftHeight > rightHeight)
			return (leftHeight + 1);
		else
			return (rightHeight + 1);
}

struct node *deleteTree(struct node *tree){
	if (tree != NULL){
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
}


