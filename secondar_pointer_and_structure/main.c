#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"

int main()
{
	Teacher *T;
	int num = 3 ;
	int ret = creatTeacher(&T,num);
	inputTeacher(T,num);
	printTeacher(T,num);
	printf("sort according to age .\n");
	sortTeacher(T,num);
	printTeacher(T,num);
	freeTeacher(T,num);
 	printf("Hello , World !\n");
	
	return 0;
}
