//  parenthesis checking using Stack ADT

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int stk[MAX], top = -1;
void push(char);
char pop();

void main(){
	char exp[MAX], temp;	// expression
	int i, flag = 1;
	printf("Enter an Expression - ");
	scanf("%s", &exp);
	
	for(i=0; i< strlen(exp); i++){
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
			push(exp[i]);
			continue;
		}
		
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
			if (top == -1)
				flag = 0;
			else{
				temp = pop();
				if (exp[i] == ')' && (temp == '[' || temp == '{'))
					flag = 0;
				if (exp[i] == '}' && (temp == '[' || temp == '('))
					flag = 0;
				if (exp[i] == ']' && (temp == '(' || temp == '{'))
					flag = 0;
			}
		}
	}
	
	if (top >= 0)
		flag = 0;
	
	if (flag == 1)
		printf("VALID EXPRESSION.");
	else
		printf("InVALID EXPRESSION.");
}

void push(char ch){
	if (top == MAX-1)
		printf("STACK OVERFLOW");
	else{
		top ++;
		stk[top] = ch;
	}
}

char pop(){
	if (top == -1)
		printf("STACK UNDERFLOW");
	else{
		return (stk[top--]);
	}
}

