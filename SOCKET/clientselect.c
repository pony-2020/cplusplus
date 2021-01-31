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
	if((fd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket");
		exit(-1);
	}

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
#if 0
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
#else
        struct 	fd_set readset;
	int maxfd = -1;
	struct timeval tout;
	char buf[BUFSIZE];
	int ret;
	while(1){

		FD_ZERO(&readset);
		FD_SET(0,&readset);
		FD_SET(fd,&readset);
		maxfd = fd;

		tout.tv_sec 	= 5;
		tout.tv_usec	= 0; 

		select(maxfd+1,&readset,NULL,NULL,&tout);
		if(FD_ISSET(0,&readset)){
			// stdin 
			//
			bzero(buf,BUFSIZE);
			do{
				ret = read(0,buf,BUFSIZE);		
			}while(ret < 0 && EINTR == errno);

			if(ret<0){
				continue;
			}

			if(!ret) continue;
			if(write(fd,buf,strlen(buf))<0){
				perror("write() to socket");
				continue;
			}

			if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))){
				printf("Client is exited!\n");
				break;
			}
		}

		if(FD_ISSET(fd,&readset)){
			// servers
			bzero(buf,BUFSIZE);
			do{
				ret = read(fd,buf,BUFSIZE-1);
			}while(ret<0 && EINTR == errno);

			if(ret<0){
				perror("read");
				continue;
			}
			if(!ret)break;

			printf("Server said: %s\n",buf);

			if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))){
				printf("Sender CLient is exited!\n");
				break;
			}
		}
	}
#endif
	return 0;
}
