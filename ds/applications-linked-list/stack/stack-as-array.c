#include<stdio.h>
#include<stdlib.h>

struct STACK{
	int top;
	unsigned int capacity;
	int *array;
};

int i;

void create_stack(struct STACK **stack, int capacity);
void push(struct STACK *stack, int new_item);
void pop(struct STACK *stack);
void display(struct STACK *stack);

int main(void){

	struct STACK *stack1;

	create_stack(&stack1, 10);
	push(stack1, 10);
	push(stack1, 20);
	push(stack1, 30);
	printf("Stack1 :: ");
	display(stack1);
	pop(stack1);
	printf("Stack1 :: ");
	display(stack1);

	return 0;
}

void create_stack(struct STACK **stack, int capacity){

	*stack = (struct STACK*)malloc(sizeof(struct STACK));
	(*stack)->capacity = capacity;
	(*stack)->top = -1;
	(*stack)->array = (int *)malloc(sizeof(int));
}

void push(struct STACK *stack, int new_item){

	if(stack->top == stack->capacity - 1){
		printf("Stack overflow\n");
	}else{
		stack->array[++stack->top] = new_item;
	}
}

void pop(struct STACK *stack){

	if(stack->top == -1){
		printf("Stack underflow\n");
	}else{
		printf("Deleted element is %d\n", stack->array[stack->top]);
		--stack->top;
	}
}

void display(struct STACK *stack){

	for(i = 0; i < stack->top + 1; i++){
		printf("%d\t", stack->array[i]);
	}
	printf("\n");
}