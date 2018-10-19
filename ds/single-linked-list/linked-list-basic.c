#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void print_list(struct NODE *n);

int main(){
	
	struct NODE *head = NULL;
	struct NODE *second = NULL;
	struct NODE *third = NULL;
	
	printf("before memory allocation\n");
	printf("%p\n", head);
	printf("%p\n", second);
	
	head = (struct NODE*)malloc(sizeof(struct NODE));
	second = (struct NODE*)malloc(sizeof(struct NODE));
	third = (struct NODE*)malloc(sizeof(struct NODE));
	
	printf("after memory allocation\n");
	printf("%p\n", head);
	printf("%p\n", second);
	
	printf("Enter head data :: ");
	scanf("%d", &head->data);
	head->next = second;
	
	printf("Enter second data :: ");
	scanf("%d", &second->data);
	second->next = third;
	
	printf("Enter third data :: ");
	scanf("%d", &third->data);
	third->next = NULL;
	
	//print linked list
	
	printf("Entered Linked list :: \n");
	print_list(head);
	
	return 0;
}

void print_list(struct NODE *n){
	
	while(n != NULL){
		printf("%d\t", n->data);
		n = n->next;
	}
	printf("\n");
}