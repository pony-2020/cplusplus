#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int a = sizeof("hello");
	int b = strlen("hello");
	printf("a = %d , b = %d",a,b);
	return 0;
}
