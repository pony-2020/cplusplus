#include <iostream>

using namespace std;

/*
class Parent{
	public:
		virtual int cry() = 0 ;
};

class dog : public Parent {
	public:
		virtual int cry(){

			cout << "wangwang" << endl;
			return 0 ; 
		}

		void superHOme(){
			cout << "stand" << endl;
		}
};

class cat : public Parent{

	virtual int cry(){
		cout << "miao miao"<< endl;
		return 0;
	}

	void eat(){

		cout << "eat food" << endl;
	}
};

// we could use dynamic_cast<>() to recognise formal paramrter type
int playStage(Parent *p){
	int ret = p -> cry();
	return 0;
}
int playStage2(Parent *p){

	int ret = p -> cry();
	dog *pDog = dynamic_cast<dog *>(p);
	if(pDog != NULL){
		pDog -> superHOme();
	}
	else {
		cout << "this is not a dog " << endl;
	}
	return 0;
}
*/ 
int main(){

	// char *p1 = "hello world" ;
	// int *p2 = reinterpret_cast<int *>(p1);
	// dog *d1 ;
	// cat *c1 ;
	// playStage(d1);
	// playStage(c1);
	// playStage2(c1);
	// playStage2(d1);
	return 0 ;
}
