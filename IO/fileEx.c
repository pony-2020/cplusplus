#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stu{
	int age ;
	char name[15];
	float score;
}STU;

int main(){
	FILE *fp;
	struct tm *info;
	time_t curtime;
	char time_c[50];

	STU stu[]={{1,"MIke",99},{2,"pony",56.5}};
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
	/*
	if(fwrite(stu,sizeof(STU),2,fp) < 0){
		perror("fwrite");
		return -1;
	}
	*/
	fclose(fp);
	return 0;
}
