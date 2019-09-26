#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char message_in[] = "Hello! Message from the pipe";

int main(){
	size_t msg_size = sizeof(message_in);
	char message_out[msg_size];
	int p[2];	
	if(pipe(p)){
		printf("pipe failed\n");	
		exit(0);
	}
	if(fork() > 0){
		write(p[1], message_in, msg_size);
	}
	else{	
		read(p[0], message_out, msg_size);
		printf("%s\n", message_out);
	}
	return 0;
}
