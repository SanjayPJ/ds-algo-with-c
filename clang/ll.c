#include<stdio.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
};

int main(){

    struct node* head;
    struct node* second;
    struct node* third;
    
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return 0;
}