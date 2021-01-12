#include "teacher.h"
#include <stdio.h>
#include <stdlib.h>

int creatTeacher(Teacher** arr ,int num )
{
	Teacher *tmp = NULL ;
	tmp = (Teacher *)malloc(sizeof(Teacher ) * num );
	
	for(int i = 0 ; i < num ; i++)
	{
		
		// malloc primary pointer 
  		tmp[i].name = (char *)malloc(sizeof(char)*25);
		
		char **p = NULL;
		p = (char **)malloc(sizeof(char*)*2);	
		
		// malloc second pointer 

		for(int j = 0 ; j < 2 ; j ++)
		{
			p[j] = (char*)malloc(sizeof(char)*24);
		}
	
		tmp[i].stuName = p ;
	
	}
 	*arr = tmp;
	
	return 0;
}

int sortTeacher(Teacher *arr , int  num )
{
	for(int i = 0 ; i < num ; i++)
	{	
		for(int j = i ; j < num ; j++ )
		{
			if(arr[i].age > arr[j].age)
			{
				Teacher tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return 0;
}

int printTeacher(Teacher *arr , int num)
{
	for(int i = 0 ; i < num ; i++ )
	{
		printf("\n teacher's name is : %s " , arr[i].name);
		
		printf("\n teacher's  age is : %d " , arr[i].age);
	}
	return 0;
}

int printfTeacherStu(Teacher *arr , int num )
{
	
	for(int i = 0 ; i < num ; i++ )
	{
		printf("\n first stu  name is : %s " , arr[i].stuName[0]);
		
		printf("\n second stu name is : %s " , arr[i].stuName[1]);
	}
	return 0;
}

int freeTeacher(Teacher *arr , int num )
{
	if( arr == NULL ) return -1 ;
	
	for(int i = 0 ; i < num ; i++ )
	{
		if(arr[i].name != NULL )
		{
			free(arr[i].name );
		}

		if(arr[i].stuName != NULL )
		{
			char ** myptr = arr[i].stuName ;
			for(int j = 0 ; j < 2 ; j ++)
			{
				if(myptr[j] != NULL )
				{
					free(myptr[j]);
				}
			}
			free(myptr);
			arr[i].stuName = NULL ;
		}

	}

	free(arr);
	return 0;
}

int inputTeacher(Teacher *arr , int num )
{

	for(int i = 0 ; i < num ; i ++ )
	{
		printf("please input %dth teacher's name : \n",i);
		// gets(arr[i].name);
		scanf("%s" ,(arr[i].name));
		printf("please input %dth teacher's age : \n",i);
		scanf("%d",&(arr[i].age));
		for(int j = 0 ; j < 2 ; j++)
		{
			printf("please input %dth teacher's %dth stu name : \n",i,j);
		//	gets(arr[i].stuName[j]);
			scanf("%s" ,(arr[i].stuName[j]));
		}
				
	}
	return 0;
}
