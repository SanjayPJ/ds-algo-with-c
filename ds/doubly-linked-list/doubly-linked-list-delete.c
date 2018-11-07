#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

void display(struct NODE *node);
void push(struct NODE **head_ref, int new_data);
void delete(struct NODE **head_ref, struct NODE *del_node);

int main(void){
    
    struct NODE *head = NULL;

    display(head);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    display(head);
    delete(&head, head->next);
    display(head);

    return 0;
}

void push(struct NODE **head_ref, int new_data){

    struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if(*head_ref != NULL){
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void delete(struct NODE **head_ref, struct NODE *del_node){

    if(*head_ref == NULL || del_node == NULL){
        printf("Head reference or delete node cant be NULL\n");
        return;
    }
    if(*head_ref == del_node){
        *head_ref = (*head_ref)->next;
    }
    if(del_node->next != NULL){
        del_node->next->prev = del_node->prev;
    }
    if(del_node->prev != NULL){
        del_node->prev->next = del_node->next;
    }
    free(del_node);
}

void display(struct NODE *node){

    if(node == NULL){
        printf("Linked list is empty\n");
        return;
    }
    printf("Traversal in forward direction\n");
    while(node != NULL){
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n");
}