
/*---- protocol type stack ----*/
/*----                     ----*/ 




#include <iostream>
#include <stack>

using namespace std;


class Teacher{

	public:

};
int main(){

	stack<int> staINT;
	for(int i= 0 ; i < 10 ; i ++){

		staINT.push(i);
	}

	while(!staINT.empty()){

		int tmp = staINT.top();
		cout << tmp << " " << endl ;
		staINT.pop();
	}
	return 0;
}
