#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 5, * p = &a;
	
	//int arr[10];
	
	//using the malloc function we can allocate the location
	//int *  arr = malloc(40);
	int * arr = (int *) malloc(sizeof(int) * 10);
	
	printf("%i\n", arr);
	//	printf("%i\n", arr[0]);
	//	printf("%i\n", arr[1]);
	
	//pointer
	printf("Location of %d is %d\n", a, p);
	printf("%d is %d\n", a, * p);
	
	//declaring array using pointers
	* (arr + 0 ) = 12;
	printf("%d\n", arr[0]);
	
	//can also use (cross platform)
	arr[0] = 34;
	printf("%d\n", arr[0]);
	
	return 0;
}
