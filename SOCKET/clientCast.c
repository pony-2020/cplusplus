#include "sock.h"

int usage(char*name){

	printf("\n serve_ip serve_port");
	printf("\n serve_ip:server ip address");
	printf("\n servr_port:server port (>5000)");
	return 0;
}
int main(int argc,char *argv[]){

	if(argc < 3){
		usage(argv[0]);
		exit(-1);
	}

	int fd = -1;
	struct sockaddr_in sin;
	if((fd=socket(AF_INET,SOCK_DGRAM,0))<0){
		perror("socket");
		exit(-1);
	}

	int b_br =1 ;
	setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&b_br,sizeof(int));
	
	
	int port = atoi(argv[2]);
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if(inet_pton(AF_INET,argv[1],(void*)&sin.sin_addr) != 1){
		perror("inet_pton");
		exit(-1);
	}

	if(connect(fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
		perror("connet");
		exit(-1);
	}

	printf("Client starting .....OK\n");
	char buf[BUFSIZE];
	int ret ;
	while(1){
		
		bzero(buf,BUFSIZE);
		if(fgets(buf,BUFSIZE-1,stdin)==NULL){
			continue;
		}
		do{
			ret = write(fd,buf,strlen(buf));
		}while(ret<0 && EINTR==errno);
			
	}
	return 0;
}
