// Write a C Program to Reverse the words in a sentence 
// that has no punctuations other than letters and spaces.

// "REVERSE THE WORDS in a SENTENCE"
// pendinggg...

#include<stdio.h>
#include<string.h>
#define MAX 100

char st[MAX], top = -1;
void push(char );
char pop();
void reverse(char input[], char output[]);

int main(){
	char input[MAX], output[MAX];
	printf("Enter the Input String - \n\t");
	gets(input);
	strcpy(output, "");
	reverse(input, output);
	printf("Reverse of the Sentence -> \n\t");
	puts(output);
	return 0;
}

void reverse(char input[], char output[]){
	int i = 0, j = 0;
	while (input[i] != '\0'){
		push(input[i]);
		i++;
	}
	while (j != strlen(input)){
		output[j] = pop();
		j++;
	}
	output[j] = '\0';
}

void push(char letter){
	if (top == MAX-1)
		printf("\nSTACK OVERFLOW.");
	else{
		top ++;
		st[top] = letter;
	}
}

char pop(){
	char val = ' ';
	if (top == -1)
		printf("\nSTACK UNDERFLOW.");
	else{
		val = st[top];
		top--;
	}
	return val;	
}




