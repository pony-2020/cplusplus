#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
	pid_t pid;

	if((pid=fork())<0){
		perror("fork");
		return -1;
	}
	else if(pid == 0){
		cout << "Child process : my pid is "<<getpid()<<endl;
	}
	else{
		cout << "parent process : my pid is "<<getpid()<<endl;
	}
	
	if(execl("/bin/ls","ls","-a","-l","/etc",NULL)<0){
		perror("execl");
	}
	return 0;
}
