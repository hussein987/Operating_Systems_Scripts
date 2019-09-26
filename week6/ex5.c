#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid > 0){
		sleep(10);
		kill(pid, SIGTERM);
	}
	else {
		while(1){
			printf("I'm alive\n");
			sleep(1);
		}
	}
	return 0;
}
