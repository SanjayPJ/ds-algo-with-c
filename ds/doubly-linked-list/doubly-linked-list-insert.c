#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

void push(struct NODE **head_ref, int new_data);
void insert_after(struct NODE *prev_node, int new_data);
void insert_before(struct NODE *next_node, int new_data);
void append(struct NODE **head_ref, int new_data);
void display(struct NODE *node);


int main(void){
    
    struct NODE *head = NULL;
    display(head);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    display(head);
    insert_after(head->next, 9);
    display(head);
    insert_before(head->next, 99);
    display(head);
    append(&head, 11);
    append(&head, 22);
    display(head);

    return 0;
}

void push(struct NODE **head_ref, int new_data){

    struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if(*head_ref != NULL){
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void insert_after(struct NODE *prev_node, int new_data){

    struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

    if(prev_node == NULL){
        printf("The given node cannot be NULL\n");
    }else{
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        new_node->prev = prev_node;
        if(new_node->next != NULL){
            new_node->next->prev = new_node;
        }
    }
}

void insert_before(struct NODE *next_node, int new_data){

    struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

    if(next_node == NULL){
        printf("The given next node cannot be NULL\n");
    }else{
        new_node->data = new_data;
        new_node->prev = next_node->prev;
        next_node->prev = new_node;
        new_node->next = next_node;
        if(new_node->prev != NULL){
            new_node->prev->next = new_node;
        }
    }
}

void append(struct NODE **head_ref, int new_data){

    struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
    }else{
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
}

void display(struct NODE *node){

    struct NODE *last;

    if(node == NULL){
        printf("Linked List is empty\n");
        return;
    }
    printf("Traversal in forward direction\n");
    while(node != NULL){
        printf("%d\t", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
    printf("Traversal in reverse direction\n");
    while(last != NULL){
        printf("%d\t", last->data);
        last = last->prev;
    }
    printf("\n");
}