#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
int print(char *addr){
	
	FILE *fp = fopen(addr,"w");
	int ret = fputs("hello world!\n",fp);
	ret = fputs("hello java\n",fp);
	fputs("hello pony\n",fp);
	fclose(fp);
	return 0;
}

int _read(char *addr,char *rcv[]){

	FILE *fp;
	int rlt;
	fp=fopen(addr,"r");
	for(int i = 0  ;!feof(fp);i++){
		fgets(rcv[i],15,fp);
	}

	fclose(fp);
	return 0;
}


int main(){

	char *addr =(char*)malloc(sizeof(char)*64);
	strcpy(addr,"file.txt");
	pid_t pid;
	int pfd[2],status;
	char *rcv[3];

	for(int j=0;j<3;j++){
		rcv[j] =(char*)malloc(sizeof(char)*15);
	}

	print(addr);
	_read(addr,rcv);

	if((pid=fork)<0){
		perror("fork");
		exit(-1);
	}
	for(int j=0;j<3;j++){
		free(rcv[j]);
	}

	free(addr);
	return 0;
}
	
