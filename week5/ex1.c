#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUMB_OF_THREADS 10

void *thread_f(void *t_id){
	int my_id = *((int *)t_id);
	printf("the id number is: %d\n", my_id);	
}

int main(){
	pthread_t thread_id[10];
	int id[10];
	for(int i=0;i<NUMB_OF_THREADS;i++){
		id[i] = i;
		pthread_create(&thread_id[i], NULL, thread_f, (void *)&id[i]);
	}
	pthread_exit(NULL);
	return 0;
}
