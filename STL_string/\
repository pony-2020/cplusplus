#include <iostream>
#include <set>

using namespace std;


int main(){

	set<int> setINT;
	int tmp;
	while(cin>>tmp){
		if(tmp <= 0) break;
		setINT.insert(tmp);
	}
	for(set<int>::iterator it = setINT.begin();it != setINT.end();){
		cout << *it ;
		it = setINT.erase(it);
	}
	cout << endl;
	return 0;
}
