#include <iostream>
#include <string>

using namespace std;

int printString(string &str){

// 	for(char *it = str.begin();it < str.end();it ++){
//		cout << *it;
//	}

	cout << str << endl; 
	return 0;
}
int main(){

	string str = "hello world , hello python , hello c";
	size_t length = str.length();
	cout << "string length : "<< length <<endl;
	size_t index = str.find("hello",0);

	while(index != string::npos){
		cout << "find 'hello' " << index << endl;
		index += 1;
		index = str.find("hello",index);
	}

	str.append(",hello java");
	str += ",hello php";
	cout << str.at(17) << endl;
	str.at(17) = 'a';
	
	int ret = printString(str);

	string str1(str);
	ret = printString(str1);
	
	str.assign(20,'c');
	ret = printString(str);

	str1.replace(str1.find("php",0),string::npos,str);
	cout << str1 << endl;

	str1.insert(str1.find("hello java",0) + 11,"hello MATLAB");
	cout << str1 << endl;
	str1.erase(str1.find("hello cccc",0),string::npos);
	cout << str1 << endl;
	return 0;
}
