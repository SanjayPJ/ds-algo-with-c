#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void display(struct NODE *head);
void delete_beginning(struct NODE **head_ref);
void delete_end(struct NODE **head_ref);

int main(void){

	struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *second = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *third = (struct NODE*)malloc(sizeof(struct NODE));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = head;

	display(head);
	delete_beginning(&head);
	display(head);
	delete_end(&head);
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

void delete_beginning(struct NODE **head_ref){

	struct NODE *temp = *head_ref;
	struct NODE *last_node;

	if(*head_ref == NULL || (*head_ref)->next == (*head_ref)){
		*head_ref = NULL;
	}else{
		while(last_node->next != *head_ref){
			last_node = last_node->next;
		}
		last_node->next = (*head_ref)->next;
		*head_ref = (*head_ref)->next;
		free(temp);
	}
}

void delete_end(struct NODE **head_ref){

	struct NODE *last_node = *head_ref;
	struct NODE *prev_node;

	if(*head_ref == NULL || (*head_ref)->next == (*head_ref)){
		*head_ref = NULL;
	}else{
		while(last_node->next != *head_ref){
			prev_node = last_node;
			last_node = last_node->next;
		}
		prev_node->next = *head_ref;
		free(last_node);
	}
}