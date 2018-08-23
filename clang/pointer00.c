

#include<stdio.h>

int main(){

	int num = 8;

	int * p = &num;

	printf("%i\n", p);
	
	printf("%i\n", *p);

	*p = 23;

	printf("%i\n", *p);

	printf("%d\n", num);

	return 0;
}
