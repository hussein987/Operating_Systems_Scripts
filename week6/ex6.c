#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
	pid_t pid1, pid2;
	int p[2];
	if(pipe(p) < 0){
		printf("pipe failed\n");
		exit(0);	
	}
	pid1 = fork();
	if(pid1 == 0){
		sleep(2);
		pid_t dest_pid;
		read(p[0], &dest_pid, sizeof(int));
		close(p[0]);
		kill(dest_pid, SIGSTOP);
		printf("SIGSTOP was sent to the child 2 of pid: %d\n", dest_pid);
		sleep(2);
		kill(dest_pid, SIGCONT);
		printf("SIGCONT was sent to the child 2 of pid: %d\n", dest_pid);
		sleep(2);
		kill(dest_pid, SIGTERM);
		printf("SIGTERM was sent to the child 2 of pid: %d\n", dest_pid);	
	}
	pid2 = fork();
	if(pid2 == 0){
		while(1);
	}
	if(pid2 > 0){
		write(p[1], &pid2, sizeof(int));
		close(p[1]);
		int status = 0, pid;
			while(1) {
				pid = waitpid(pid2, &status, 0);
				printf("Child 2 changed status.\n");
				if(pid == -1) break;
			}
	}
	return 0;
}
