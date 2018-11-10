#include<stdio.h>
#include<stdlib.h>

struct QUEUE{
	int front, rear;
	unsigned int capacity;
	int *array;
};

int i;

void create_queue(struct QUEUE **queue, unsigned int capacity);
void enqueue(struct QUEUE *queue, int new_item);
void dequeue(struct QUEUE *queue);
void display(struct QUEUE *queue);

int main(void){

	struct QUEUE *queue;

	create_queue(&queue, 10);
	enqueue(queue, 10);
	enqueue(queue, 20);
	display(queue);
	dequeue(queue);
	display(queue);
	return 0;
}

void create_queue(struct QUEUE **queue, unsigned int capacity){

	*queue = (struct QUEUE*)malloc(sizeof(struct QUEUE));
	(*queue)->capacity = capacity;
	(*queue)->front = -1;
	(*queue)->rear = -1;
	(*queue)->array = (int *)malloc(sizeof(int) * (*queue)->capacity);
}

void enqueue(struct QUEUE *queue, int new_item){

	if(queue->rear == queue->capacity - 1){
		printf("Queue overflow\n");
	}else if(queue->front == -1 && queue->rear == -1){
		queue->front = queue->rear = 0;
	}else{
		queue->rear++;
	}
	queue->array[queue->rear] = new_item;
}

void dequeue(struct QUEUE *queue){

	if(queue->front == -1 && queue->rear == -1){
		printf("Queue underflow\n");
	}else if(queue->front == queue->rear){
		queue->front = queue->rear = -1;
	}else{
		queue->front++;
	}
}

void display(struct QUEUE *queue){

	for (i = queue->front; i <= queue->rear; i++){
		printf("%d\t", queue->array[i]);
	}
	printf("\n");
}