#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void insert_begnning(struct NODE **head_ref, int new_data);
void insert_position(struct NODE *head,int new_data, int pos);
void insert_end(struct NODE **head_ref, int new_data);
void delete_begnning(struct NODE **head_ref);
void delete_position(struct NODE **head_ref, int pos);
void delete_end(struct NODE **head_ref);
void display(struct NODE *head);

int i;

int main(void){
	
	int opt, new_data, pos;
	
	struct NODE *head = NULL;
	//struct NODE *second, *third;
	
	while(1){
		
		printf("1. Insert at begnning\n2. Insert at particular position\n3. Insert at end\n4. Delete from begnning\n5. Delete from particular position\n6. Delete from end\n7. Display\n8. Exit\nChoose your option :: ");
		scanf("%d", &opt);
		
		//head = (struct NODE *)malloc(sizeof(struct NODE));
		//second = (struct NODE *)malloc(sizeof(struct NODE));
		//third = (struct NODE *)malloc(sizeof(struct NODE));
		
		//head->data = 1;
		//head->next = second;
		
		//second->data = 2;
		//second->next = third;
		
		//third->data = 3;
		//third->next = NULL;
		
		switch(opt){
			case 1:
				printf("Enter element to be added :: ");
				scanf("%d", &new_data);
				insert_begnning(&head, new_data);
				display(head);
				break;
			case 2:
				printf("Enter element to be added :: ");
				scanf("%d", &new_data);
				printf("Enter position of element to be added :: ");
				scanf("%d", &pos);
				insert_position(head, new_data, pos);
				display(head);
				break;
			case 3:
				printf("Enter element to be added :: ");
				scanf("%d", &new_data);
				insert_end(&head, new_data);
				display(head);
				break;
			case 4:
				delete_begnning(&head);
				display(head);
				break;
			case 5:
				printf("Enter position of element to be deleted :: ");
				scanf("%d", &pos);
				delete_position(&head, pos);
				display(head);
				break;
			case 6:
				delete_end(&head);
				display(head);
				break;
			case 7:
				display(head);
				break;
			case 8:
				return 0;
			default:
				printf("Wrong Option.\n");
				break;
		}
	}

	return 0;
}

void display(struct NODE *head){
	
	if(head == NULL){
		printf("Linked List is Empty\n");
	}else{
		printf("Entered linked list :: ");
		while(head != NULL){
			printf("%d\t", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void insert_begnning(struct NODE **head_ref, int new_data){
	
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
	}else{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
}

void insert_position(struct NODE *head, int new_data, int pos){
	
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	
	new_node->data = new_data;
	for(i = 0; i < pos - 1; i++){
		head = head->next;
	}
	new_node->next = head->next;
	head->next = new_node;
}

void insert_end(struct NODE **head_ref, int new_data){
	
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *last_node = *head_ref;
	
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

void delete_begnning(struct NODE **head_ref){
	
	struct NODE *first;
	
	if(*head_ref == NULL){
		printf("Deletion is not possible\n");
	}else{
		first = *head_ref;
		*head_ref = first->next;
		printf("Deleted item is %d\n", first->data);
		free(first);
	}
}

void delete_position(struct NODE **head_ref, int pos){
	
	struct NODE *prev_node = *head_ref;
	struct NODE *curr_node;
	
	for(i = 0; i < pos - 2; i++){
		prev_node = prev_node->next;
	}
	curr_node = prev_node->next;
	prev_node->next = curr_node->next;
	printf("Deleted item is %d\n", curr_node->data);
	free(curr_node);
}

void delete_end(struct NODE **head_ref){
	
	struct NODE *prev_node = *head_ref;
	struct NODE *last_node = prev_node->next;
	
	while(last_node->next != NULL){
		last_node = last_node->next;
		prev_node = prev_node->next;
	}
	prev_node->next = NULL;
	printf("Deleted item is %d\n", last_node->data);
	free(last_node);
}



