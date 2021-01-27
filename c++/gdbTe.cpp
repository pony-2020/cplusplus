#include <iostream>

using namespace std;

int swap(int *a,int *b){
	int tmp = *a ;
	*a = *b;
	*b = tmp;
	
	return 0;
}

int main(){

	//int a = 10 ;
	//int b = 20;
	int a , b ;
	cin >> a ;
	cin >> b;
	cout << "a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	int ret = swap(&a,&b);
	cout << "a = "<<a<<endl;
	cout<<"b = "<<b<<endl;

	return 0;
}
