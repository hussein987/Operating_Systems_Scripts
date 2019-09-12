#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int main(){
	char s[MAX_N];
	printf("SHELL> ");
	scanf("%s", s);
	while(strcmp(s, "exit")){	
		system(s);
		printf("SHELL> ");
		scanf("%s", s);
	}
	return 0;
}
