#include <stdio.h>
#include <dirent.h>

int main(){

	DIR *dirp = opendir("/home/pony/Desktop/cplusplus");
	struct dirent *fp = NULL;
	while((fp = readdir(dirp)) != NULL){
		printf("%s\t",fp->d_name);
		printf("%ld\t",fp->d_ino);
		printf("%d\n",fp->d_type);
	}
	return 0;
}
