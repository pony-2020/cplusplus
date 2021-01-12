#include <iostream>

using namespace std;

typedef struct Teacher
{
	int age ;
	char name[15];
}Teacher;
int constTeacher(const Teacher* &ptr){

	ptr -> age = 0 ;
	// error 
	// ptr is not allowed being modified 
	return 0;
}
int main(){
	
	// simple reference 
	int a = 10 ; 
	int &b = a ;
	cout << "a:"<< a << "\t b: "<< b << endl ;

	// constant reference 
	int x = 10 ;
	const int &y = x ; // we can not modify x via y 

	// initialization of constant reference has two situations
	// one : via variable 
	int x1 = 20 ;
	const int &y1 = x1 ;

	// two :via literal
	// there is no room for literal
	const int a1 = 40 ;
       	// cplusplus compiler puts 'a' in symbol table
	
	// int &b = 50 ; 
	// variable b is not allowed a memory
	// compiler error 
	
	const int &c = 50 ;
	// malloc memory 
	cout << "c= " << c << endl;
	return 0;
}
