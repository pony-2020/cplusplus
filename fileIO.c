#include <stdio.h>
#include <fcntl.h>

int main(){

	int fd ;
	if((fd = open("1.txt",O_RDWR|O_CREAT|O_EXCL,0666))<0){
		perror("other error");
	}
	return 0;
}
