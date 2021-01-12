#include <iostream>

using namespace std;

/*---pointer's reference ---*/

typedef struct Teacher
{
	int age ;
	char name[64];
}Teacher;

/*---get information from called function ---*/
int getTeacher(Teacher **ptr){
	
	Teacher *tmp = NULL ;
	if(ptr == NULL){
		return -1;
	}

	tmp = (Teacher *)malloc(sizeof(Teacher));
	if(tmp==NULL){
		return -1;
	}
	tmp -> age = 21 ;
	*ptr = tmp ;
	return 0;
}

/*---reference in cplusplus ----*/ 
int getTeacher02(Teacher* &ptr){
	
	// assigning value to ptr equals assignment of ptr in main function
 
	ptr = (Teacher *)malloc(sizeof(Teacher));
	if(ptr == NULL){
		return -1;
	}
	ptr -> age = 100 ;
	return 0;
}

int freeTeacher(Teacher *ptr){

	free(ptr);
	return 0;
}
int main(){
	
	// second pointer in c 
	Teacher *ptr = NULL;
	getTeacher(&ptr);

	// reference function in cplusplus 
	getTeacher02(ptr);
	cout <<"age: "<< ptr -> age << endl;
	cout << "Hello world" << endl ;
	freeTeacher(ptr);
	return 0;
}
