#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	char arr[10];
	setvbuf(stdout, arr, _IOLBF, 5);
	printf("H"); sleep(1);	
	printf("e"); sleep(1);
	printf("l"); sleep(1);
	printf("l"); sleep(1);
	printf("o"); sleep(1);
	printf("\n");
	return 0;
}
