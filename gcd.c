#include<stdio.h>

int gcd(int n1, int n2);
int main(){
	int n1, n2, ans;
	printf("\nEnter 2 numbers - \n");
	scanf("%d %d", &n1, &n2);
	ans = gcd(n1, n2);
	printf("GCD of %d, %d = %d", n1, n2, ans);
	return 0;
}

// Euclids Algorithm.
int gcd(int n1, int n2){
	int remainder = n1 % n2;
	if (remainder == 0)
		return n2;
	else
		return gcd(n2, remainder);
}


