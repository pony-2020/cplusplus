#ifndef _TEACHER_H
#define _TEACHER_H

typedef struct Teacher 
{
	int age ;
	int ID[24];
	char *name ;
	char **stuName;
}Teacher;

int creatTeacher(Teacher** arr , int num );

int sortTeacher(Teacher *arr ,int num ); // according to age 

int printTeacher(Teacher *arr , int num );

int printTeacherStu(Teacher *arr ,int num);

int freeTeacher(Teacher *arr , int num) ;

int inputTeacher(Teacher *arr , int num);

#endif 
