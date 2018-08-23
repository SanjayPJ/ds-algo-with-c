
#include<stdio.h>

int main(){

	int num = 5;

	//pointers
	
	int * pointer;

	//you cant declare pointer like this
	//int pointer_int = &num;

	pointer = &num;

	printf("%i\n", pointer );

	printf("%i\n", &num );

	//this will show an error
	//printf("%i\n", &pointer_int );

	return 0;
}
