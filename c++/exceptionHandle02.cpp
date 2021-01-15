#include <iostream>

using namespace std ;


int strcpy_( char *from , char *to){

	if(*from == NULL){
	
		throw 1 ;
	}

	if(*from != 'a'){
		throw '1';
	}

	if(*to != NULL){
		throw 1.1;
	}

	while(*from != '\0'){
		*to++ = *from++;
	}

	*to = '\0';
	return 0;
}

int playStage(int(*myFun)(char *f , char *t) ){

	char from1[] = "hello world";
	char *to = new char[1024];
	int ret = myFun(from1,to);
	return ret;
}


int main(){
	try{
		playStage(strcpy_);
		//strcpy_(from2,to);
		//strcpy_(from3,to);
	}
	catch(int){
		cout << "catch int " << endl; 
	}

	catch(double){
		cout << "catch double"<<endl;
	}
	catch(...){
		cout << "catch char" << endl;
	}
	return 0;
}
