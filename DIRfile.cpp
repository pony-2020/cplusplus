#include <iostream>
#include <dirent.h>

using namespace std;
int main(){

	DIR *dnum = opendir("cplusplus");
	struct dirent *ret = NULL;
	while((ret = readdir(dnum)) != NULL){
		cout << ret -> d_name << endl;
	}
	closedir(dnum);
	return 0;

}
