#include <iostream>
#include <map>

using namespace std;

int main(){

	map<string,int>Author;
	Author.insert(pair<string,int>("pony",22));
	Author.insert(make_pair("Mike",34));
	Author.insert(map<string,int>::value_type("itcast",54));
	for(map<string,int>::iterator it = Author.begin();
		it != Author.end();it++){
		pair<string,int> pa= *it;
		cout << "name = " << pa.first << endl;
	        cout << "age  = " << pa.second<<endl;
		}	
	for(map<string,int>::reverse_iterator it_re = Author.rbegin();
		it_re != Author.rend();it_re++){
		pair<string,int> pa= *it_re;
		cout << "name = " << pa.first << endl;
	        cout << "age  = " << pa.second<<endl;
		}	
	cout << "map size = " << Author.size() << endl;
	if(Author.find("pony") != Author.end()) cout << "found pony"<< endl;

	return 0;
}
