#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Teacher{

	public:
		Teacher(char *n,int age){
			this -> m_name = new char(sizeof(n));
			strcpy(this -> m_name , n);
			this -> age = age;
		}
	
		// deep copy
		// Teacher t1 = t2 
		Teacher(const Teacher &t){
			this -> m_name = new char(sizeof(t.m_name));
			strcpy(this -> m_name,t.m_name);
			this -> age = t.age;
		}

		// t1 = t2 = t3 
		// overloaded operator =
		Teacher &operator=(const Teacher &obj){
			if(this -> m_name != NULL){
				delete[] m_name;
				m_name = NULL;
				age = 0;
			}

			this -> m_name = new char(sizeof(obj.m_name));
			strcpy(this->m_name,obj.m_name);
			this->age = obj.age;
			return *this;
		}
	public:
		int printTe(){
			cout << "name is "<< this->m_name<<endl;
			cout << "age is " << this->age << endl;
			return 0;
		}
	private:
		int age;
		char *m_name;
};

int main(){

	vector<Teacher> V1;
	Teacher t1("Trump",71);
	Teacher t2 = t1 ;
	Teacher t3("Baden",60);
	V1.push_back(t1);
	V1.push_back(t2);
	V1.push_back(t3);
	for(vector<Teacher>::iterator it=V1.begin();it!=V1.end();it++){

		int ret = (*it).printTe();
	}
	return 0;
}
