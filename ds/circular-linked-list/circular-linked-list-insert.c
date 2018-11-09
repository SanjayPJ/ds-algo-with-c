#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

int i;

void display(struct NODE *head);
void push(struct NODE **head_ref, int new_data);
void append(struct NODE **head_ref, int new_data);
void insert_pos(struct NODE *pos_node, int new_data, int pos);

int main(void){

	struct NODE *head = NULL;

	display(head);
	append(&head, 10);
	push(&head, 1);
	display(head);
	push(&head, 2);
	display(head);
	append(&head, 3);
	display(head);
	insert_pos(head, 66, 3);
	display(head);

	return 0;
}

void push(struct NODE **head_ref, int new_data){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *last_node = *head_ref;

	new_node->data = new_data;
	if(*head_ref == NULL){
		*head_ref = new_node;
		new_node->next = new_node;
	}else{
		new_node->next = *head_ref;
		while(last_node->next != *head_ref){
			last_node = last_node->next;
		}
		last_node->next = new_node;
		*head_ref = new_node;
	}
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

void append(struct NODE **head_ref, int new_data){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *last_node = *head_ref;

	new_node->data = new_data;
	if(*head_ref == NULL){
		*head_ref = new_node;
		new_node->next = new_node;
	}else{
		new_node->next = *head_ref;
		while(last_node->next != *head_ref){
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
}

void insert_pos(struct NODE *pos_node, int new_data, int pos){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

	new_node->data = new_data;
	if(pos_node != NULL){
		for(i = 0; i < pos - 2; i++){
			pos_node = pos_node->next;
		}
		new_node->next = pos_node->next;
		pos_node->next = new_node;
	}
}