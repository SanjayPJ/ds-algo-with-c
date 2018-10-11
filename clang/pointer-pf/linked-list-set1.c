#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	printf("Enter the First Number :: ");
	scanf("%d", &head->data);
	head->next = second;

	printf("Enter the Second Number :: ");
	scanf("%d", &second->data);
	second->next = third;

	printf("Enter the Third Number :: ");
	scanf("%d", &third->data);
	third->next = NULL;

	printf("%p", third);

	return 0;
}
