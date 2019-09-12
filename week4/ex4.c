#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_N 1000

void  parse(char *line, char **argv)
{
	while (*line != '\0') {       
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;            
     }
     *argv = NULL;  
}


int main(){
	char line[MAX_N];
	char *argv[MAX_N];
	while(1){
		scanf("%[^\n]%*c", line);
		parse(line, argv);
		if(strcmp(argv[0], "exit") == 0)
			exit(0);
		if(fork() == 0)
			execvp(argv[0], argv);
	}
	return 0;
}
