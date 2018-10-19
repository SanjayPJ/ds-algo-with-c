#include<stdio.h>
#include<stdlib.h>

struct emp{
	int emp_id;
	char name[10];
};

struct emp *ptr;

int main(){
	printf("Enter the Employee Details :: \n");
	ptr = (struct emp *) malloc(sizeof(struct emp));

	printf("Enter the Employee ID :: ");
	scanf("%d", &ptr->emp_id);
	printf("Enter the Employee Name :: ");
	scanf("%s", ptr->name);

	printf("Employee Details :: \n");
	printf("Roll No :: %d\n", ptr->emp_id);
	printf("Employee Name :: %s\n", ptr->name);

	return 0;
}
