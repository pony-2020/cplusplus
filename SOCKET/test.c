#include "sock.h"

int main(){

/*	uint32_t addr;
	inet_pton(AF_INET,SERV_IP_ADDR,(void*)&addr);
	printf("%x ",addr);
*/
	pid_t pid;
	if((pid=fork())<0){
		perror("fork");
		exit(-1);
	}

	if(pid==0){
		printf("i am child\n");
	}
	else{
		printf("i am parent\n");
	}
	return 0;
}
