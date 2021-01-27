#include "sock.h"

void client_data_handle(void*fd){

	int newfd = *(int*)fd;
	printf("Handler thread : newfd = %d\n",newfd);
	int ret = -1;
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
		if(!ret)break;// client is colsed
		printf("Rec data is %s\n",buf);
		if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))){
			printf("client(fd=%d) is existing!\n",newfd);
			break;
		}
	}
	close(newfd);
	return;
}

int main(){

	// socket 
	int fd = -1;
	if((fd = socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket");
		exit(-1);
	}
	
	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_port	 =	 htons(SERV_PORT);
	sin.sin_family	 =	 AF_INET;
#if 0
	// inet_addr only for IPV4
	sin.sin_addr.s_addr 	=	inet_addr(SERV_IP_ADDR);
	// inet_pton() for IPV4 and IPV6
	if(inet_pton(AF_INET,SERV_IP_ADDR,(void*)&sin.sin_addr) != 1){
		perror("inet_pton");
		exit(-1);
	}
#else 
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	// all local IP	
#endif
	
	if(bind(fd,(struct sockaddr*)&sin,sizeof(sin))<0){
		perror("bind");
		exit(-1);
	}

	if(listen(fd,BACKLOG)<0){
		perror("listen");
		exit(-1);
	}

	int newfd = -1;
#if 0
	struct sockaddr_in cin;
	char ipv4_addr[16];
	socklen_t addrlen = sizeof(cin);
	if((newfd = accept(fd,(struct sockaddr*)&cin,&addrlen))<0){
		perror("accept");
		exit(-1);
	}
	inet_ntop(AF_INET,(void*)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin));
	printf("client (%s:%d) is conneted !",ipv4_addr,htons(cin.sin_port));
#endif
	pthread_t thread;
	struct sockaddr_in cin;
	char ipv4_addr[16];
	while(1){
		
		socklen_t addrlen = sizeof(cin);
		if((newfd = accept(fd,(struct sockaddr*)&cin,&addrlen))<0){
			perror("accept");
			exit(-1);
		}
		inet_ntop(AF_INET,(void*)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin));
		printf("client (%s:%d) is conneted !",ipv4_addr,htons(cin.sin_port));

		pthread_create(&thread,NULL,(void*)&client_data_handle,(void*)&newfd);
	}
	close(fd);
	return 0;
}
