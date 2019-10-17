#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_FRAMES 100
#define BITMASK 31

int ticks = 0, miss = 0, hit = 0;
int p[NUM_OF_FRAMES];
int counter[NUM_OF_FRAMES];

int main(){
	FILE* f = fopen("Lab 09 input.txt", "r");
	int page;
	for(int i=0;i<NUM_OF_FRAMES;i++)
		p[i] = -1;
	while(fscanf(f, "%d", &page) == 1){
   		int fault = 1;
		int subs = 0;
		for(int i=0;i<NUM_OF_FRAMES;i++){
			if(p[i] == page){
				counter[i] = (1 << (BITMASK - 1)) | (counter[i] >> 1);
				fault = 0;
			}
			else {
				counter[i] = counter[i] >> 1;
			}
			
			if(counter[i] < counter[subs] || p[i] == -1)
				subs = i;
		}
		//printf("%d %d\n", subs, page);
		ticks++;
		if(!fault) continue;
		miss++;
		counter[subs] = (1 << (BITMASK - 1));
		p[subs] = page;
	}

	hit = ticks - miss;
	printf("%d %d %d\n", ticks, miss, hit); 
	printf("hits/miss = %f\n", (hit*1.0)/(miss*1.0));
	return 0;
}


