#include <iostream>

using namespace std ;

class myArray{

	public:
		myArray(int len);

		// using reference is to return a left value 
		// arr[i] = i + 1 ;
		int& operator [](int index);

		int getLen();

		class eSize{
			public:

				eSize(int size){
					this ->  size = size ;
				}
				
				virtual int printErr() = 0;
			protected:
				int size ;

		};

		class eNegative : public eSize
		{
			public:
				eNegative(int len):eSize(len){
					;
				}

				virtual int printErr(){
					cout << "this -> size = " <<  this -> size<< endl;
					return 0;
				}
		};
		class eZero : public eSize{
			public:
				eZero(int len) : eSize(len){
					;
				}
				virtual int printErr(){
					cout << "this -> size = " <<  this -> size<< endl;
					return 0;
				}
		};
		class eSmall : public eSize{
			public:	
				eSmall(int len):eSize(len){
					;
				}

				virtual int printErr(){
					cout << "this -> size = " << this -> size<< endl;
					return 0;
				}
		};
		class eBig : public eSize{
			public:
				eBig(int len):eSize(len){
						;
				}
				virtual int printErr(){
					cout << "this -> size = " <<  this -> size<< endl;
					return 0;
				}
		};

	private:
		int myLen ;
		int *mySpace;
};

myArray::myArray(int len){
	if(len < 0){
		throw eNegative(len);
	}
	else if(len == 0){
		throw eZero(len);
	}
	else if(len < 10){
		throw eSmall(len);
	}
	else{
		throw eBig(len);
	}
	this -> myLen = len ;
	mySpace = new int[len];
}

int myArray::getLen(){ return(this -> myLen); }
int& myArray::operator[](int index){ return mySpace[index]; }

int poloFun(myArray::eSize &size){
	size.printErr();
	return 0;
}
int tryCatch(int len){
	try{
		myArray arr(len);
	}
	catch(myArray::eNegative e){
		cout << "negative value" << endl;
		poloFun(e);		
		goto BEGIN;
	}
	catch(myArray::eZero e){
		cout << "zero value" << endl;
		poloFun(e);		
		goto BEGIN;
	}
	catch(myArray::eSmall e){
		cout << "too samll" << endl;
		poloFun(e);		
		goto BEGIN;
	}
	catch(myArray::eBig e){
		cout << "too big" << endl;
		poloFun(e);		
		goto BEGIN;
	}
	catch(...){
		cout << "unknown exception" << endl;
		goto BEGIN;
	}
BEGIN:
	return -1;
	return 0;
}
int main(){
	int i = -1 ;
STR:
	for(; i < 55 ;){
		int ret = tryCatch(i);
		if(ret == -1){
		i += 5;       
		goto STR;
		}
	}
	return 0;
}
