#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	FILE *fp;
	struct tm *info;
	time_t curtime;
	char time_c[50];
	if((fp = fopen("/home/pony/Desktop/cplusplus/IO/stuINFO.txt","w")) == NULL){
		perror("fopen");
		return -1;
	}
	else{
		fprintf(fp,"%s\n","Today is a big day!");
		time(&curtime);
		info = localtime(&curtime);
		//fprintf(fp,"local time is :%s",asctime(info));
		fprintf(fp,"%d-%02d-%02d\n",info->tm_year+1900,info->tm_mon+1,info->tm_mday);
		printf("%l\n",ftell(fp));
		// sprintf(time_c,"%d-
	}
	fclose(fp);
	return 0;
}
