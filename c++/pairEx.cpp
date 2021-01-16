#include <iostream>
#include <utility>

using namespace std ;

pair<string,int> playStage(){

	return make_pair("pony",25);
}

typedef pair<string,int> Author;

int main(){

	string name;
	int age ;
	pair<string,int>p1 = playStage();
	cout << "name : " <<p1.first << endl;
	cout << "age : "  << p1.second<< endl;
	Author  p2;
	p2 = make_pair("MIke",25);
	cout << "name : " <<p2.first << endl;
	cout  << "age : "  << p2.second<< endl;

	return 0;
}
