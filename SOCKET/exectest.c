#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>

int main(){

	if(execl("/home/pony/Desktop/cplusplus/SOCKET/test","test",NULL)<0){
		perror("execl");
		exit(-1);
	}
	printf("never be printed");
	return 0;
}
