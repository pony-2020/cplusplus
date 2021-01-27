#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc,char *argv[]){

	int i = 0;
	for(; i < argc ; i++){
		cout << argv[i] << endl ;
	}
	return 0;
}
