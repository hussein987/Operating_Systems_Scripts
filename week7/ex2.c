#include <stdlib.h>
#include <stdio.h>


int main()
{
	int n;
	printf("please enter the number of arguments\n");
	scanf("%d",&n);
	int *arr = (int*) malloc(sizeof(int));
	for(int i = 0; i<n; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);


	return 0;
}
