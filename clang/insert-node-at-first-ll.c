
#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *ptr;
};

int main(){
	
	typedef struct node NODE;
	NODE *start = NULL, *temp;

	printf("Single Linked List\n");
	temp = (NODE *)malloc(sizeof(NODE));
	printf("Enter the data to be inserted :: ");
	scanf("%d", &temp->data);

	if(start == NULL){
		temp->ptr = NULL;
		start = temp;
	}else{
		temp->ptr = start;
		start = temp;
	}
	
	return 0;
}
