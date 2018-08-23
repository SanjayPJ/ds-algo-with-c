#include<stdio.h>
#include<stdlib.h>

struct person{
	int id;
	char * name;
	char * address;
	char * phone;
};

typedef struct person person;

int main(){
	
	person student00;
	person * per_pointer = &student00;
	person student01;
	person * per01_pointer = &student01;
	
	(* per_pointer).id = 23;
	(* per_pointer).name = "Sanjay PJ";
	(* per_pointer).address = "I have no address";
	(* per_pointer).phone = "9567890347";
	
	printf("id of student00 is %d\n", student00.id);
	printf("name of student00 is %s\n", student00.name);
	printf("address of student00 is %s\n", student00.address);
	printf("phone of student00 is %s\n", student00.phone);
	
	(* per01_pointer).id = 34;
	(* per01_pointer).name = "Nikhil";
	(* per01_pointer).address = "i dont have any fuck'n idea about that one";
	(* per01_pointer).phone= "976887979898";
	
	printf("id of student01 is %d\n", (* per01_pointer).id);
	printf("name of student01 is %s\n", (* per01_pointer).name);
	printf("address of student01 is %s\n", (* per01_pointer).address);
	printf("phone of student01 is %s\n", (* per01_pointer).phone);
	return 0;	
}
