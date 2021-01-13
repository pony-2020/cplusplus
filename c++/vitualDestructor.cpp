// The virtual destructor that passed through the parent class 
// executes all the destructors of the child class
// namely , via parent class pointer releases all child resource
//
//


#include <iostream>

using namespace std;

class A{

public:
	A(){

		cout << "parent A()" << endl;
	}

	virtual ~A(){
		
		cout << "delete A()" <<endl;
	}
};

class B : public A {
	public:
	B(){
		cout << "child B()"<< endl;
	}

	virtual ~B(){

		cout << "delete B()" << endl;
	}
};

class C : public B{
	public:
	C(){
		cout << "child C" << endl;
	}

	virtual ~C(){
		cout << "delete C()" <<endl;
	}
};

int playStage(A *base){

	delete base;
	return 0;
}

int main(){

	C *baseC = new C;
	// playStage(baseC);
	// line 51 and line 53 have same effects 
	delete baseC;
	return 0;
}
