#include <iostream>
#include <string.h>
#include <errno.h>

using namespace std;
/*
int main(){

	FILE *fp = NULL;
	if((fp = fopen("passwd3.txt","r")) == NULL){
		// cout << "fopen err" << endl;
		cout << strerror(errno) << endl;
	}
	else{
		cout << "fopen" << endl;
	}
	return 0;
}
*/

typedef struct stu{
	int num;
	char name[8];
	float score;
}stu;
/*
int main(){
	int ch;
	int cnt =0 ;
	ch = fgetc(stdin);
	cout << ch << endl;

	cout << "count passwd.txt" << endl;
	cout << "----------------" << endl;
	FILE *fp = NULL; 
	if((fp = fopen("passwd.txt","r")) == NULL){
			cout << strerror(errno) << endl;
	}
	else{
		while((ch = fgetc(fp)) != EOF){
			cnt ++;
		}
	}
	cout << "cnt = "<< cnt << endl;
	return 0;
}
*/

int main(){
	FILE *fp = fopen("stuINFO.txt","w+");
	stu s[] = {{1,"MIke",56},{2,"pony",78}};
	if(fwrite(s,sizeof(stu),2*sizeof(stu),fp)<0){
		perror("fwrite");
		return -1;
	}
	else{
		stu ptr[2];
		if(fread(ptr,sizeof(stu),2,fp)<0){
			perror("fread");
			return -1;
		}
	}

	cout << ptr[0] -> num << " " << ptr[1] -> num <<endl;
	return 0;
}
