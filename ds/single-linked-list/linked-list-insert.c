#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void print_linked_list(struct NODE*);
void push_linked_list(struct NODE** head_ref, int new_data);
void insert_after(struct NODE* prev_node, int new_data);
void append(struct NODE** head_ref, int new_data);

int main(){
	
	struct NODE* head = NULL;
	struct NODE* second = NULL;
	struct NODE* third = NULL;
	
	head = (struct NODE*)malloc(sizeof(struct NODE));
	second = (struct NODE*)malloc(sizeof(struct NODE));
	third = (struct NODE*)malloc(sizeof(struct NODE));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	push_linked_list(&head, 6);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	push_linked_list(&head, 9);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	insert_after(head, 5);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	insert_after(second, 5);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	insert_after(third, 5);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	append(&head, 22);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	append(&head, 23);
	
	printf("Entered Linked List is :: ");
	print_linked_list(head);
	
	return 0;
}

void print_linked_list(struct NODE* n){
	
	while(n != NULL){
		printf("%d\t", n->data);
		n = n->next;
	}
	printf("\n");
}

void push_linked_list(struct NODE** head_ref, int new_data){
	
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void insert_after(struct NODE* prev_node, int new_data){
	
	struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(struct NODE** head_ref, int new_data){
	
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL){
		*head_ref = new_node;
	}else{
		while(last->next != NULL){
			last = last->next;
		}
		last->next = new_node;
	}
}
