#include<stdio.h>

int handshakes(int );
int main() {
	int n_ppl, total_hs;
	printf("\nEnter Number of People\'s - ");
	scanf("%d", &n_ppl);
	total_hs = handshakes(n_ppl);
	printf("Total Handshakes between %d people = %d", n_ppl, total_hs);
	return 0;
}

int handshakes(int n) {
	if (n == 2)
		return 1;
	else
		return (handshakes(n-1) + (n-1));
}

