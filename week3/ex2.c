#include <stdio.h>

#define MAX_SIZE 1000

int array_size;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int a[]){
	for(int i=0;i<array_size;i++){
		for(int j=0;j<array_size-1;j++)
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);		
	}
}

int main(){
	int a[MAX_SIZE];
	printf("please enter the nuber of elements in the array\n");
	scanf("%d", &array_size);
	printf("please enter the elements of the array\n");
	for(int i=0;i<array_size;i++)
		scanf("%d", &a[i]);
	bubble_sort(a);
	for(int i=0;i<array_size;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
