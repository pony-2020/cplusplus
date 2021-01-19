#include <iostream>
#include <deque>

using namespace std;

/*--------------------deque----------------------------*/
/*    push_front push_back pop_front pop_back          */

int main(){

	deque<int> deInt;
	for(int i = 1 ; i <= 9 ; i++){
		deInt.push_back(i);
	}

	for(int j = 1 ; j >-11 ; j--){
		deInt.push_front(j);
	}

	for(deque<int>::iterator it = deInt.begin();it != deInt.end() ; it++){
		cout << *it << " " ;
	}
	cout <<"head element is " << deInt.front() << endl;
	cout <<"tail element is " << deInt.back()  << endl;
	deInt.pop_front();
	deInt.pop_back();
	for(deque<int>::iterator it = deInt.begin();it != deInt.end() ; it++){
		cout << *it << " " ;
	}
	cout << endl;
	for(deque<int>::iterator it1 = deInt.begin();it1 != deInt.end();){

		if(*it1 % 2 == 0) it1 = deInt.erase(it1) ;
		else ++it1;
	}
	for(deque<int>::iterator it = deInt.begin();it != deInt.end() ; it++){
		cout << *it << " " ;
	}
	cout << endl;

	return 0;
}
