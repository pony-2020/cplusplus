#include <iostream>

using namespace std ;

class A {
public :
	int b;
};

class B : public A{

public :
	int c ;
};

class B1 : public A
{
	public :
		int ba ;
};

class c : public B , public B1 {

	public :
		int kk ;
};


int main(){

	c c1 ;
	c1.kk = 5 ;
	return 0;
}
