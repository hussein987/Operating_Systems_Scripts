#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int f = open("ex1.txt", O_RDWR);
        struct stat st;
        fstat(f, &st);
        off_t size = st.st_size;
        char *address = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
	strncpy(address, "This is a nice day", size);
        return 0;
} 
