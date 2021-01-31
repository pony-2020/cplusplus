#include "socket_header.h"

void prompt_message(char*name){
	printf("argv[0] is %s\n",name);
	printf("argv[1] is address\n");
	printf("argv[2] is port ( recommend > 5000)\n");
}

int main(int argc,char* argv[]){

	if(argc<3){
		prompt_message(argv[0]);
		exit(-1);
	}

	int fd = -1;
       if((fd=socket(AF_INET,SOCK_STREAM,0))<0){
	       perror("socket");
	       exit(-1);
       }

       struct sockaddr_in cin;
       // bzero(&cin,sizeof(cin));
       memset((void*)&cin,0,sizeof(cin));
       cin.sin_family = AF_INET;
       cin.sin_port   = htons(atoi(argv[2]));
       if(inet_pton(AF_INET,argv[1],(void*)&cin.sin_addr.s_addr)<0){
	       perror("inet_pton");
	       exit(-1);
       }

	if(connect(fd,(const struct sockaddr*)&cin,sizeof(cin))<0){
		perror("connect");
		exit(-1);
	}
	
	printf("Client is connected.\n");
	char buf[BUFSIZE];
	int ret = -1;
	while(1){
		bzero(buf,BUFSIZE);
		if(fgets(buf,BUFSIZE-1,stdin)==NULL){
			continue;
		}
		do{
			ret = write(fd,buf,strlen(buf));
		}while(ret<0 && EINTR == errno);
		if(strncmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
			printf("Quit!\n");
			break;
		}
	}

	close(fd);	
	return 0;
}

	



