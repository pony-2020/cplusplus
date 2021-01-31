/*#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE  	64
#define QUIT_STR 	"quit"
#define SERV_PORT 	5001
*/
#include 	 "sock.h"

int main(){

	int fd = -1;
	if((fd = socket(AF_INET,SOCK_DGRAM,0))<0){
		perror("socket");
		exit(-1);
	}

	// bind a name to a socket 
	//
	int b_reuse = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&b_reuse,sizeof(int));

	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_family		 = AF_INET;
	sin.sin_port  		 = htons(SERV_PORT);
	sin.sin_addr.s_addr	 = htonl(INADDR_ANY);
	if(bind(fd,(struct sockaddr*)&sin,sizeof(sin))<0){
		perror("bind");
		exit(-1);
	}

	char buf[BUFSIZE];
	struct sockaddr_in cin;
	socklen_t addrlen = sizeof(cin);
	while(1){
		bzero(buf,BUFSIZE);
		char ipv4_addr[16];
		if(recvfrom(fd,buf,BUFSIZE-1,0,(struct sockaddr*)&cin,&addrlen)<0){
			perror("recvfrom");
			continue;
		}
		
		if(!inet_ntop(AF_INET,(void*)&cin.sin_addr,ipv4_addr,sizeof(cin))){
			perror("inet_ntop");
			exit(-1);
		}
	
		printf("Receive from(%s:%d) , data is %s",ipv4_addr,ntohs(cin.sin_port),buf);

		if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))){
			printf("Client(%s:%d) is exiting!\n",ipv4_addr,ntohs(cin.sin_port));
		}
	}

	close(fd);
	return 0;
}
