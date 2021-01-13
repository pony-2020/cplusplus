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
		Complex operator+(const Complex &c1 )
		{
			
			Complex c3(this -> a + c1.a , this -> b + c1.b);

			return c3;

		}

		/*
		friend Complex operator + (const Complex &c1 , const Complex &c2){

			Complex c3(c1.a + c2.a , c1.b + c2.b);
			return c3;
		}
		*/

		friend int printCpm(Complex &c){


			cout << "c.a = "  << c.a << endl ;
			cout << "c.b = "  << c.b << endl ;
			cout << endl ;
			return 0;
		}
		
		Complex operator - (const Complex c1){

			
			Complex c2( this -> a - c1.a , this -> b -c1.b );
			return c2;
		}

		Complex operator *(const Complex &c){
			
			Complex c2( this -> a *c.a , this ->b * c.b );
			return c2;
		}

		// Complex operator + (const Complex &c);



};

int main(){

	Complex c1(1,2);
	Complex c2(3,4);
  	Complex c3 = c1 + c2 ;
	Complex c4 = c1 + c3 ;

	Complex c5 = c4 ;
 	printCpm(c1);
 	printCpm(c2);
 	printCpm(c3);
 	printCpm(c4);
	printCpm(c5);


	cout << "Hello world !" << endl;
	return 0;
}
