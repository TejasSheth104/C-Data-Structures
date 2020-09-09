// Postifx Evaluation

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100
float st[MAX];
int top = -1;
void push(float st[], float val);
float pop(float st[]);
float evalPostfix(char exp[]);

int main(){
	float val;
	char exp[100];
	printf("\nEnter any Postfix Expression - ");
	gets(exp);
	val = evalPostfix(exp);
	printf("\nVAlue of the PostFix Expression is - %.2f", val);
	return 0;
}

float evalPostfix(char exp[]){
	int i = 0;
	float op1, op2, val;
	while (exp[i] != '\0'){
		if (isdigit(exp[i]))
			push(st, (float)(exp[i] - '0'));
		else{
			op2 = pop(st);
			op1 = pop(st);
			switch(exp[i]){
				case '+':
					val = op1 + op2;
					break;
				case '-':
					val = op1 - op2;
					break;
				case '*':
					val = op1 * op2;
					break;
				case '/':
					val = op1 / op2;
					break;
				case '%':
					val = (int)op1 % (int)op2;
					break;
			}
			push(st, val);
		}
		i++;
	}
	return (pop(st));
}

void push(float st[], float val){
	if (top == MAX - 1)
		printf("\nSTACK OVERFLOW");
	else{
		top++;
		st[top] = val;
	}
}

float pop(float st[]){
	float val = -1;
	if (top == -1)
		printf("\nSTACK UNDERFLOW");
	else
		val = st[top--];
	return val;
}

