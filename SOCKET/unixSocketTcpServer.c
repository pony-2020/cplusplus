#include "sock.h"
#include <signal.h>
#include <sys/wait.h>
void sig_child_handler(int signo){
	if(SIGCHLD == signo){
		waitpid(-1,NULL,WNOHANG);
	}
}

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
	if((fd = socket(AF_LOCAL,SOCK_STREAM,0))<0){
		perror("socket");
		exit(-1);
	}
	
	int b_reuse = 1 ;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&b_reuse,sizeof(int));

#if 0
	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_port	 =	 htons(SERV_PORT);
	sin.sin_family	 =	 AF_INET;
	// inet_addr only for IPV4
	sin.sin_addr.s_addr 	=	inet_addr(SERV_IP_ADDR);
	// inet_pton() for IPV4 and IPV6
	if(inet_pton(AF_INET,SERV_IP_ADDR,(void*)&sin.sin_addr) != 1){
		perror("inet_pton");
		exit(-1);
	}
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	// all local IP	
#else
	struct sockaddr_un sun;
	bzero(sun,sizeof(sun));
	sun.sun_family = AF_LOCAL;

	if(access(UNIX_DOMAIN_FILE,F_OK)){
		unlink(UNIX_DOMAIN_FILE);
	}
	strncpy(sun.sun_path,UNIX_DOMAIN_FILE,strlen(UNIX_DOMAIN_FILE));
	
#endif 
	
	if(bind(fd,(struct sockaddr*)&sun,sizeof(sun))<0){
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
#if 0
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
#else
	pid_t pid=-1;
	signal(SIGCHLD,sig_child_handler);
	while(1){
		if(newfd=accept(fd,NULL,NULL)<0){
			perror("accept");
			exit(-1);
		}
		printf("hello4\n");
		if(pid=fork()<0){
			perror("fork");
			printf("hello5");
			exit(-1);
		}
		printf("%d",getpid());
		if(pid==0){
			printf("%d",getpid());
			printf("hello7");
				close(fd);
			char ipv4_addr[16];
			if(!inet_ntop(AF_INET,(void*)&cin.sin_addr.s_addr,ipv4_addr,sizeof(sin))){
				perror("inet_ntop");
				exit(-1);
			}

			printf("Client (%s:%d) is connected!\n",ipv4_addr,ntohs(cin.sin_port));
			client_data_handle(&newfd);
			exit(0);
		}
		else{
			printf("%d",getpid());
			close(newfd);
		}
	}

#endif
	close(fd);
	return 0;
}
