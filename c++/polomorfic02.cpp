#include <iostream>

using namespace std ;

class calArea{

	public :
		virtual double areaCal(){

			// this is polomorphic function
			// depends on child function
		}
};

class rectangle : public calArea{

	public:
		rectangle(int a , int b): calArea() {
			this -> a = a ;
			this -> b = b;

		}

		virtual double areaCal(){

			return ( this-> a) * ( this -> b) * 1.0 ;
		}
	private:
		int a ;
		int b;
};

class circle : public calArea {


	public:
		circle(int r) : calArea() {
		       	this -> radias = r ;

		}

		virtual double areaCal(){

			return (this -> radias) *(this -> radias) * 3.14;
		}
	private:
		int radias;
};

double playStage(calArea &para){

	double area = para.areaCal();
	cout << "area is " << area  << endl;
	return area;
}
int main(){

	rectangle rec(10,20);
	circle cir(5);
	playStage(rec);

	playStage(cir);
	return 0;
};
