#include<stdio.h>

struct student{
	char name[10];
	int age;
};

typedef struct student student;

int main(){
	student std1[10];
	int range, i;
	printf("enter the range of students :: ");
	scanf("%d", &range);
	for(i = 0; i < range; i++ ){
		printf("enter %d th name :: ", i );
		scanf("%s", &std1[i].name);
		printf("enter %d th age :: ", i );
		scanf("%d", &std1[i].age);
	}
	for(i = 0; i < range; i++){
		printf("name of %d th student :: %s\n", i, std1[i].name);
		printf("age of %d th student :: %d\n", i, std1[i].age);
	}
	return 0;
}
