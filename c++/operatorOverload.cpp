#include <iostream>

using namespace std;

// operator overloaded 
class Complex{

	public:
		int a ;
		int b ;

		// Complex(int _a = 0 , int _b = 0):a(_a),b(_b){}
		
		Complex(int a = 0 , int b = 0){

			this -> a = a ;
			this -> b = b ;
		}
		Complex operator + (const Complex &c1 ,const  Complex &c2(0,0))
		{
			Complex c3(c1.a + c2.a , c1.b + c2.b);
			return c3;
		}

};

int main(){

	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3 = c1 + c2 ;

	cout << "Hello world !" << endl;
	return 0;
}
