#include <iostream>

using namespace std;

class programmer{

	public :
		virtual void getSal() = 0 ;
};

class juniorPro : public programmer {

	public :
		juniorPro(char *name , char *job , int sal){

			this -> name = name ;
			this -> job  = job ;
			this -> sal  = sal;
		}

		virtual void getSal(){

			cout << name << " " << job << " " << sal << endl;
		}

		juniorPro(){
	
			this -> name = new char[15];
			this -> job  = new char[10];
		}

		~juniorPro(){
			delete [] name ;
			delete [] job ;
		}
	private:
		char *name ;
		char *job ;
		int sal;
};

class middlePro : public programmer {

	public :
		middlePro(char *name , char *job , int sal){

			this -> name = name ;
			this -> job  = job ;
			this -> sal  = sal;
		}

		virtual void getSal(){

			cout << name << " " << job << " " << sal << endl;
		}

		middlePro(){
	
			this -> name = new char[15];
			this -> job  = new char[10];
		}

		~middlePro(){
			delete [] name ;
			delete [] job ;
		}



	private:
		char *name ;
		char *job ;
		int sal;
};
class advancePro : public programmer {

	public :
		advancePro(char *name , char *job , int sal){

			this -> name = name ;
			this -> job  = job ;
			this -> sal  = sal;
		}

		virtual void getSal(){

			cout << name << " " << job << " " << sal << endl;
		}

		advancePro(){
	
			this -> name = new char[15];
			this -> job  = new char[10];
		}

		~advancePro(){
			delete [] name ;
			delete [] job ;
		}

	private:
		char *name ;
		char *job ;
		int sal;
};


int calSal(programmer &base){

	base.getSal();
	return 0;
}
int main(){

	juniorPro   Mike("Mike" , "primary" , 5000);
	middlePro   Pony("Kaven" , "Middle" , 15000);
	advancePro Polly("Polly", "adv" , 25000);
	calSal(Mike);
	calSal(Pony);
	calSal(Polly);
	return 0;

}
