#include <iostream>

using namespace std ;

void __div__(int x , int y){

	if( y == 0){
		throw x ;
	}

	cout << "result is " << x /y  << endl;
}

int main(){

	try{
		__div__(10,2);
		__div__(100,0);
	}

	catch(int e){
		cout << e <<" divided by zero" << endl; 
	}


	// remaining exceptions 
	catch(...)
	{
		cout << " unknow error" << endl ;
	}
	return 0;
}
