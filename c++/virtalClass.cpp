#include <iostream>

using namespace std ;

class A{
	
	public:
		unsigned int age ;
};

class B : public A{

	public:
};


class B1 : virtual A {

	public:
};

int main(){

	
	A a1 ;
	B b;
	B1 b1;
	cout << "sizeof(A)" << sizeof(A) << endl ;
	cout << "sizeof(B)" << sizeof(B) << endl;
	cout << "sizeof(B1)"<< sizeof(B1) << endl;
	return 0 ;
}
