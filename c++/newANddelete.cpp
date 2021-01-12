#include <iostream>

using namespace std;
class Name{

	public:
		int a ;
		Name(int _a): a(_a){
			cout << "a is " << this -> a << endl ;
		}

		~Name(){
			cout << "destrutor is called" << endl ;
		}

		int getName(){   // ===> int getName(Name *this)
			cout << "test" << endl ;
			return 0;
		}

		int getName02() const{ // ===> int getName02(const Name *this)
				       // which means all attributes is read_only
			cout << "test02"<<endl ;
			return 0;
		}
};
int main(){

	// assign base types
	int *p = new int(30);
	cout << "p=" << p << endl;
	delete p;

	// assign array type
	int *pArr = new int[4];
	for(int i = 0 ; i < 4 ; i++){
		pArr[i] = i ; 
	}

	for(int i = 0 ; i < 4 ; i ++){

		cout << "pArr[" << i <<"]"<< "=" << pArr[i] << endl;
	}
	delete [] pArr ;

	// defferences between new and malloc ,delete and free is 
	// when it comes to assgin memory for class ,
	// new can call constructor of the class , malloc can not 
	// delete can call its destructor , free can not 
	// new and delete are keywords , malloc and free are functions 
	// obviously , it is faster to use new and delete instead of mallc and free 
	// Apart from that , new and malloc ,delete and free they have same effect .
	//
	Name *name = new Name(1);
	delete name ;
	return 0;
}
