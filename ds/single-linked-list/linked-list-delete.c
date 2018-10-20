#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int data;
	struct NODE* next;
};

void push(struct NODE** head_ref, int new_data);
void display(struct NODE* head);
void delete_using_key(struct NODE** head_ref, int key);

int main(void){
	struct NODE* head = NULL;
	
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	display(head);
	delete_using_key(&head, 1);
	display(head);
	push(&head, 5);
	push(&head, 6);
	display(head);
	delete_using_key(&head, 3);
	display(head);
	return 0;
}

void display(struct NODE* head){
	printf("Entered linked list :: ");
	
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct NODE** head_ref, int new_data){
	struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));
	struct NODE* last_node = *head_ref;
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL){
		*head_ref = new_node;
	}else{
		while(last_node->next != NULL){
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
}

void delete_using_key(struct NODE** head_ref, int key){
	struct NODE *temp = *head_ref;
	struct NODE *prev;
	
	if(temp != NULL){
		if(temp->data == key){
			*head_ref = temp->next;
			free(temp);
		}else{
			while(temp->data != key){
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			free(temp);
		}
	}
}
