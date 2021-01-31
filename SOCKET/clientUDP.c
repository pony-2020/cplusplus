#include "sock.h"

int usage(char*name){

	printf("This is a UDP APP\n");
	printf("Usage: %s serve_ip serve_port",name);
	printf("\n serve_ip:server ip address");
	printf("\n servr_port:server port (>5000)");
	return 0;
}

int main(int argc,char *argv[]){

	if(argc<3){
		usage(argv[0]);
		exit(-1);
	}

	int fd=-1;
	if((fd=socket(AF_INET,SOCK_DGRAM,0))<0){
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	
	char buf[BUFSIZE];
	while(1){
		bzero(buf,BUFSIZE);
		if(fgets(buf,BUFSIZE-1,stdin) ==NULL){
			perror("fgets");
			continue;
		}

		sendto(fd,buf,strlen(buf),0,(struct sockaddr*)&sin,sizeof(sin));

		if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))){
			printf("Client is exited!\n");
			break;
		}
	}
	close(fd);

	return 0;
}
