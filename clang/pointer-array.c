#include<stdio.h>

int main(){
	
	//int arr[10];
	
	//using the malloc function we can allocate the location
	//int *  arr = malloc(40);
	int * arr = malloc(sizeof(int) * 10);
	
	printf("%i\n", arr);
	
	return 0;
}
