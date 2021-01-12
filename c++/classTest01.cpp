#include <iostream>

using namespace std;

class AA
{
	public:
		AA(){
			cout<< "i am constructor , called automatically" << endl;
		}

		AA(int _a){
			a = _a;
			cout << "my a is " << this -> a <<endl;
			// no parament constructor , default constructor
		}

		AA(const AA &A1){
			cout << "i am another constructor , initialing myself through another AA class"<<endl;
			a = A1.a + 100 ;
		}
			~AA(){
				cout << "i am a destructor , called automatically."<<endl;
				getA();
			}

			int getA(){

				cout<<"A.a = " << this -> a << endl;
				return 0;
			}
	private:
			int a ;

};

int roleStage(){
	
	cout << "hello world " << endl;
	AA a1(5);
	AA a2(a1);
	AA a3 = 10 ;
	return 0;
}
int main(){
	

	int ret = roleStage();
	return 0;
}
