#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void display(struct NODE *head);

int main(void){

	struct NODE *head = NULL;

	// struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
	// struct NODE *second = (struct NODE*)malloc(sizeof(struct NODE));
	// struct NODE *third = (struct NODE*)malloc(sizeof(struct NODE));

	// head->data = 1;
	// head->next = second;

	// second->data = 2;
	// second->next = third;

	// third->data = 3;
	// third->next = head;

	display(head);

	return 0;
}

void display(struct NODE *head){

	struct NODE *temp = head;

	if(head != NULL){
		do{
			printf("%d\t", temp->data);
			temp = temp->next;
		}while(temp != head);
		printf("\n");
	}else{
		printf("Linked list is empty\n");
	}
}