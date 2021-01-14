#include <iostream>
// #include <cstdio.h>

using namespace std;

class Parent {

public :
	Parent(int a = 0){
		cout << "Parent class"<< endl;
	}

	virtual int priClass(){
		cout << " a = " << this -> a << endl;
		cout << "I AM FATHER CLASS"  << endl ;
		return 0;
	}

private :
	int a ;


};


class Parent2 {

public :
	Parent2(int a = 0){
		cout << "Parent class"<< endl;
	}

	 int priClass(){
		cout << " a = " << this -> a << endl;
		cout << "I AM FATHER CLASS"  << endl ;
		return 0;
	}

private :
	int a ;

};

class Child : public Parent {

public :
	Child(int a = 0 , int b = 10) : Parent(a){

		this -> b = b ;
	}

	virtual int priClass(){

		cout << " b = " <<  b  << endl;
		return 0;
	}

private :
	int b ;
};

int main(){
	
	Parent  *Par  = new Parent;
	Parent2 *Par2 = new Parent2;
	Child   *Chi  = new Child;
	cout << sizeof(*Par)  << endl;
	cout << sizeof(*Par2) << endl;
	cout << sizeof(*Chi)   << endl;
	return 0;
}
