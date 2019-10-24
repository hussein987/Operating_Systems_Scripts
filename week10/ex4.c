#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void solve(char* file, char* dir, ino_t inode) {
	DIR *dirp = opendir(dir);
	if (dirp == NULL) return;
	char filep[360];		
	struct stat sdata;	
	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		sprintf(filep, "%s/%s", dir, dp->d_name);
		stat(filep, &sdata);
		if (sdata.st_ino == inode) 
			printf("%s\n", dp->d_name);
	}
}

int main() {
	DIR *dirp = opendir("./temp");
	if (dirp == NULL) 
		return 1;  //ERROR
	char filep[360];		
	struct stat sdata;
	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		sprintf(filep, "%s/%s", "./temp", dp->d_name);
		stat(filep, &sdata);
		if (sdata.st_nlink >= 2 && strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) 
			solve(dp->d_name, "./temp", sdata.st_ino);
	}

	return 0;
}
