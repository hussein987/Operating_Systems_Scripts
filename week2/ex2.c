#include <stdio.h>
#include <string.h>

int main(){

	char s[10];
	scanf("%s", s);
	int length = strlen(s);
	for(int i=0;i<length/2; i++){
		char temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	}
	printf("%s", s);
	return 0;
}
