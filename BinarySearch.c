#include <stdio.h>
int main(){
	int i, j, first, last, middle, n, val, array[100], temp;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter %d integers - \n", n);
	for (i = 0; i < n; i++)
		scanf("%d",&array[i]);
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;	
			}
		}
	}
	printf("Integers in Sorted Order - \n", n);
	for (i = 0; i < n; i++)
		printf("\t%d\n", array[i]);
	printf("Enter value to find\n");
	scanf("%d", &val);
	first = 0;
	last = n - 1;
	middle = (first+last)/2;
	while (first <= last) {
		if (array[middle] < val)
			first = middle + 1;
		else if (array[middle] == val) {
			printf("%d found at location %d.\n", val, middle+1);
			break;
		}
		else
			last = middle - 1;
		middle = (first + last)/2;
	}
	if (first > last)
		printf("Not found! %d is not present in the list.\n", val);
	return 0;
}

