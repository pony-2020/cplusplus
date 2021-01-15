#include <iostream>

using namespace std ;

template<class T>
int mySwap(T &a , T &b)
{
	T t = a ; 
	a = b ; 
	b = t ;
	cout << "template func do" << endl;
	return 0;
}

int mySwap(int &a , int &b)
{

	int tmp ;
	tmp = a ;
	a = b ; 
	b = tmp;
	cout << "ordinary func do " << endl;
	return 0 ;
}

int main(){

	int a = 3 ; 
	int b = 5;
	mySwap(a , b);
	float c = 1.0 ;
	float d = 2.0 ;
	mySwap(c,d);

	return 0 ; 
}
