#include <iostream>
#include <string.h>

using namespace std;

class Name{

	public:
		Name(const char *ptr){
		// if(ptr == NULL )
			this -> len = strlen(ptr);
			this -> p = (char *)malloc(sizeof(char)*(len+1));
			strcpy(p,ptr);
		}

		Name(const Name &name){
			this -> len = name.len +1 ;
			this -> p = (char*)malloc(sizeof(char)*(this -> len));
			strcpy(p,name.p);
		}

		int getName(){
			
			cout << "my name is :" << this -> p << endl ;
			return 0;
		}

		// using the initializer list for initialization 
		Name(int _len):len(_len){
		}

		~Name(){
			getName();
			free(this -> p);
			this -> p = NULL;
		}
	protected:
	private:
		int len ;
		char *p;
};

int roleStage(){

	Name name1("ponytail");
	Name name2(name1);
	return 0;
}

int main(){
	
	cout << "hello world!"<< endl;
	return 0;

}
