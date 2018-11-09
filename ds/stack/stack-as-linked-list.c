#include<stdio.h>
#include<stdlib.h>

struct STACK{
	int item;
	struct STACK *next;
};

void push(struct STACK **top, int new_item);
void pop(struct STACK **top);
void display(struct STACK *top);

int main(){

	struct STACK *top = NULL;

	push(&top, 10);
	push(&top, 20);
	top = NULL;
	pop(&top);
	push(&top, 10);
	push(&top, 20);
	pop(&top);
	push(&top, 50);
	push(&top, 60);
	printf("Stack is :: \n");
	display(top);

	return 0;
}

void push(struct STACK **top, int new_item){

	struct STACK *new_node;

	if(*top == NULL){
		*top = (struct STACK*)malloc(sizeof(struct STACK));
		(*top)->item = new_item;
		(*top)->next = NULL;
	}else{
		new_node = (struct STACK*)malloc(sizeof(struct STACK));
		new_node->item = new_item;
		new_node->next = *top;
		*top = new_node;
	}
	printf("%d pushed into stack\n", (*top)->item);
}

void pop(struct STACK **top){

	struct STACK *temp;

	if(*top == NULL){
		*top = NULL;
		printf("Stack underflow\n");
	}else{
		printf("%d popped from stack\n", (*top)->item);
		*top = (*top)->next;
	}
}

void display(struct STACK *top){

	struct STACK *i;

	for(i = top; top != NULL; top = top->next){
		printf("%d\t", top->item);
	}
	printf("\n");
}