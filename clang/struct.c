

#include<stdio.h>

struct person{
	int id;
	char * first_name;
	char * last_name;
};

typedef struct person person;

int main(){
	
	person student01;
	student01.id = 6;
	student01.first_name = "Sanjay";
	student01.last_name = "PJ";
	
	person student02;
	student02.id = 12;
	student02.first_name = "Nikhil";
	student02.last_name = "James";

	person student03;
	student03.id = 2;
	student03.first_name = "Arpith";
	student03.last_name = "Baiju";

	printf("%i. %s %s\n", student01.id, student01.first_name, student01.last_name);
	printf("%i. %s %s\n", student02.id, student02.first_name, student02.last_name);
	printf("%i. %s %s\n", student03.id, student03.first_name, student03.last_name);

	return 0;
}
