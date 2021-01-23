#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
	pid_t pid;
	FILE *fp;
	time_t t;
	if((pid = fork())<0){
		perror("fork");
		exit(-1);
	}
	else if(pid>0){
		exit(0);
	}
	setsid();
	umask(0);
	chdir("/tmp");
	for(int i=0;i < getdtablesize();i++){
		close(i);
	}
	
	if((fp=fopen("time.log","a"))==NULL){
		perror("fopen");
		exit(-1);
	}

	while(1){
		time(&t);
		fprintf(fp,"%s",ctime(&t));
		fflush(fp);
		sleep(1);
	}
	return 0;
}
