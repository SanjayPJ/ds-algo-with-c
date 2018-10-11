#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void read_ll(struct node *n){
	while(n != NULL){
		printf("%d\t", n->data);
		n = n->next;
	}
	printf("\n");
}

int main(){
	
	//start with empty list
	struct node *head = NULL;
	
	//assign values
	struct node *second = NULL;
	struct node *third = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	

	//read the ll
	read_ll(head);

	return 0;
}
