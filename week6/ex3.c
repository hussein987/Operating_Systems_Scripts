#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) 
{ 
    printf("Caught signal: Ctrl-c was pressed %d\n", sig); 
} 

int main(){
	signal(SIGINT, handle_sigint);
	while(1){
		printf("process alive\n");
		sleep(1);
	}
	return 0;
}
