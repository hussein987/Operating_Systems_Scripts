#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int n = atoi(argv[1]);
	if(fork() == 0)
		printf("Hello from child [%d - %d]\n", getpid(), n);
	else 
		printf("Hello from parent [%d - %d]\n", getppid(),  n);
	return 0;
}
