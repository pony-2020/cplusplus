// using conditions of polomorphic 
// 1. ssuccesor
// 2. virtual function
// 3. parent pointer points child's object 
#include <iostream>

using namespace std ;
/*
class P{
	public :
		int a ;
		P(int a1):a(a1){

			cout << "parent a" << endl ;
		}

		virtual	void print(){
		
			cout << "print p" << endl;
		}
};

class C : public P {

	public:
		int b ;
		C(int b1):P(50){

			this -> b = b1 ;
			cout << "Child b" << endl ;
		}

		int printInt(){

			cout << "hello world" << endl;
			return 0;
		}
	 virtual void print(){

		cout << "printf child" << endl;
	}
};
*/

class hero{

	public:
		virtual int power(){

			return 10;
		}

		int print(){

			cout << "this is parent func"<<endl;
			return 0;
		}

};

class enermy{

	public:
		int attack(){

			return 15;
		}
};

class advHero: public hero{

	public:
		virtual int power(){

			return 20;
		}
};

int playStage(hero &hero , enermy &ener){

	if(hero.power() > ener.attack()){
		cout << "win" << endl;
	}
	else{
		cout << "lose" << endl ;
	}
	return 0;
}

int main(){

	hero hero;
	advHero adv;
 	enermy en;

	playStage(hero,en);

	playStage(adv,en);
	adv.print();
	return 0;
}
