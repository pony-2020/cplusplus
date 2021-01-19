#include <iostream>
#include <vector>

using namespace std;

int playStage(){

	vector<int> vecInt;
	for(int i = 1 ; i < 9 ; i += 2){
		vecInt.push_back(i);
	}
	cout << "vecInt.size = " << vecInt.size() << endl;
	for(vector<int>::iterator it = vecInt.begin() ; it != vecInt.end() ;){
		cout << *it;
		it ++;
	}
	/*-
	int *arr = new int[vecInt.size()+1];
	i = 0 ;	
	for(it = vecInt.begin();it != vecInt.end() ; it++){
		arr[i++] = 	
	}
	return 0;
	*/

	if(vecInt.empty() != 1) cout << "vecInt is not empty" << endl;

	return 0;

}

int main(){

	int ret = playStage();
	return 0;
}
