#include "socket_header.h"

int main(){

	int fd = -1 ;
	
	if((fd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port   = htons(SOCK_PORT);
	
#if _LOCAL_
	if((inet_pton(fd,SOCK_ADDR,(void*)&(sin.sin_addr.s_addr)))!=1){
		perror("inet_pton");
		exit(-1);
	}

#else

	sin.sin_addr.s_addr = htons(INADDR_ANY);
#endif

	if(bind(fd,(const struct sockaddr*)&sin,sizeof(sin))<0){
		perror("bind");
		exit(-1);
	}

	if(listen(fd,BACKLOG)<0){
		perror("listen");
		exit(-1);
	}

	struct sockaddr_in cin;
	socklen_t addrlen = sizeof(cin);
	bzero(&cin,sizeof(cin));
	int newfd = -1;
	int ret   = -1;
	if((newfd=accept(fd,(struct sockaddr*)&cin,&addrlen))<0){
		perror("accept");
		exit(-1);
	}

	char ipv4[16] ;
	if(inet_ntop(AF_INET,(const void*)&cin.sin_addr.s_addr,ipv4,sizeof(cin)) == NULL){
		perror("inet_ntop");
		exit(-1);
	}
	printf("Client(%s:%d) is connected.\n",ipv4,cin.sin_port);
	char buf[BUFSIZE];
	while(1){
		bzero(buf,BUFSIZE);
		do{
			ret = read(newfd,buf,BUFSIZE-1);
		}while(ret<0 && EINTR == errno);
		if(ret<0){
			perror("read");
			exit(-1);
		}
		if(ret == 0) break;
		if(strncmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
			printf("Client is exited!\n");
			break;
		}
		printf("data is : %s",buf);
	}
	close(newfd);

	return 0;
}

	
