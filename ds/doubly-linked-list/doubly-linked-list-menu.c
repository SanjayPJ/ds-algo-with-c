#include<stdio.h>
#include <stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
	struct NODE *prev;
};

int i;

void display(struct NODE *node);
void insert_beginning(struct NODE **head_ref, int new_data);
void insert_end(struct NODE **head_ref, int new_data);
void insert_pos(struct NODE *pos_node, int new_data, int pos);
void delete_beginning(struct NODE **head_ref);
void delete_end(struct NODE **head_ref);
void delete_pos(struct NODE **head_ref, int pos);

int main(void){

	struct NODE *head = NULL;
	int opt, ele, pos;

	while(1){
		printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at a particular position\n4. Delete from the beginning\n5. Delete from the end\n6. Delete from particular position\n7. Display\n8. Exit\n");
		printf("Choose your option :: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Enter the element to be added :: ");
				scanf("%d", &ele);
				insert_beginning(&head, ele);
				display(head);
				break;
			case 2:
				printf("Enter the element to be added :: ");
				scanf("%d", &ele);
				insert_end(&head, ele);
				display(head);
				break;
			case 3:
				printf("Enter the element to be added :: ");
				scanf("%d", &ele);
				printf("Enter the position of the element to be added :: ");
				scanf("%d", &pos);
				insert_pos(head, ele, pos);
				display(head);
				break;
			case 4:
				delete_beginning(&head);
				display(head);
				break;
			case 5:
				delete_end(&head);
				display(head);
				break;
			case 6:
				printf("Enter the position of the element to be deleted :: ");
				scanf("%d", &pos);
				delete_pos(&head, pos);
				display(head);
				break;
			case 7:
				display(head);
				break;
			case 8:
				return 0;
			default:
				printf("Invalid option\n");
				break;
		}
	}
}

void display(struct NODE *node){

	struct NODE *last_node;

	if(node == NULL){
		printf("Linked List is empty\n");
	}else{
		printf("Linked list in forward direction\n");
		while(node != NULL){
			printf("%d\t", node->data);
			last_node = node;
			node = node->next;
		}
		printf("\n");
		printf("Linked list in reverse direction\n");
		while(last_node != NULL){
			printf("%d\t", last_node->data);
			last_node = last_node->prev;
		}
		printf("\n");
	}
}

void insert_beginning(struct NODE **head_ref, int new_data){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

	new_node->data = new_data;
	new_node->prev = NULL;

	if(*head_ref == NULL){
		new_node->next = NULL;
	}else{
		(*head_ref)->prev = new_node;
		new_node->next = (*head_ref);
	}
	*head_ref = new_node;
}

void insert_end(struct NODE **head_ref, int new_data){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *last_node = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if(*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;
	}else{
		while(last_node->next != NULL){
			last_node = last_node->next;
		}
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void insert_pos(struct NODE *pos_node, int new_data, int pos){

	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

	new_node->data = new_data;
	if(pos_node != NULL){
		for(i = 0; i < pos; i++){
			pos_node = pos_node->next;
		}
		new_node->next = pos_node;
		new_node->prev = pos_node->prev;
		pos_node->prev->next = new_node;
		pos_node->prev = new_node;
	}
}

void delete_beginning(struct NODE **head_ref){

	struct NODE *temp = *head_ref;

	if(*head_ref == NULL || (*head_ref)->next == NULL){
		*head_ref = NULL;
	}else{
		*head_ref = (*head_ref)->next;
		(*head_ref)->prev = NULL;
		printf("Deleted element is %d\n", temp->data);
		free(temp);
	}
}

void delete_end(struct NODE **head_ref){

	struct NODE *last_node = (*head_ref)->next;
	struct NODE *prev_node = *head_ref;

	if(*head_ref == NULL || (*head_ref)->next == NULL){
		*head_ref = NULL;
	}else{
		while(last_node->next != NULL){
			last_node = last_node->next;
			prev_node = prev_node->next;
		}
		prev_node->next = NULL;
		printf("Deleted element is %d\n", last_node->data);
		free(last_node);
	}
}

void delete_pos(struct NODE **head_ref, int pos){

	struct NODE *pos_node = *head_ref;

	if(*head_ref != NULL){
		for(i = 0; i < pos - 1; i++){
			pos_node = pos_node->next;
		}
		pos_node->prev->next = pos_node->next;
		pos_node->next->prev = pos_node->prev;
		printf("Deleted element is %d\n", pos_node->data);
		free(pos_node);
	}
}