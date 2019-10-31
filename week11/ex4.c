#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
	int x1, x2;
	char *f1, *f2;
	x1 = open("ex1.txt", O_RDONLY);
	int size = lseek(x1, 0, SEEK_END);
	f1 = mmap(NULL, size, PROT_READ, MAP_PRIVATE, x1, 0);
	x2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 1000);
	ftruncate(x2, size);
	f2 = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, x2, 0);
	memcpy(f2, f1, size);
	munmap(f1, size);
	munmap(f2, size);
	return 0;
}
