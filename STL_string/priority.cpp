#include <iostream>
#include <queue>
// #include <cstdio.h>
using namespace std;

int main(){

	priority_queue<int> score;
	int tmp;
	while(cin>>tmp){
		if(tmp < 0) break;
		score.push(tmp);
	}
	cout << "amount of students is " << score.size()<<endl;
	cout << "the hightest score is " << score.top() << endl;
	return 0;
}
