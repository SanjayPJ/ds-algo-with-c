#include<stdio.h>

struct person{
	int id;
	char * name;
};

typedef struct person person;

int main(){
	
	person * student0;
	
	printf("%d\n", student0);	
	return 0;
}
