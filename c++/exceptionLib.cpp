// using libary function of c plus plus
//

#include <iostream>
#include <stdexcept>

using namespace std ;

class Teacher{

	public:
		Teacher(int age){
			if(age > 100) throw out_of_range("too old!");
			this -> age = age ;
		}

	private:
		int age ;
};

int exceptionStage(int age){
	try{
		Teacher t1(age);
	}
	catch(out_of_range &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

int main(){
	int ret = exceptionStage(150);
	return ret;
}
