#include<stdio.h>
#include <stdlib.h>

struct QNODE{
	int item;
	struct QNODE *next;
};

struct QUEUE{
	struct QNODE *front, *rear;
};

void create_queue(struct QUEUE **queue);
void enqueue(struct QUEUE *queue, int new_item);
void dequeue(struct QUEUE *queue);
void display(struct QNODE *front);

int main(void){

	struct QUEUE *queue;

	create_queue(&queue);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	display(queue->front);
	dequeue(queue);
	display(queue->front);
	return 0;
}

void create_queue(struct QUEUE **queue){

	*queue = (struct QUEUE*)malloc(sizeof(struct QUEUE));
	(*queue)->front = (*queue)->rear = NULL;
}

void enqueue(struct QUEUE *queue, int new_item){

	struct QNODE *temp = (struct QNODE *)malloc(sizeof(struct QNODE));

	temp->item = new_item;
	temp->next = NULL;

	if(queue->rear == NULL){
		queue->rear = queue->front = temp;
	}
	queue->rear->next = temp;
	queue->rear = queue->rear->next;
}

void dequeue(struct QUEUE *queue){

	struct QNODE *temp;

	if(queue->rear == NULL){
		printf("Queue underflow\n");
	}else{
		temp = queue->front;
		queue->front = queue->front->next;
		if(queue->front == NULL){
			queue->rear = NULL;
		}
	}
}

void display(struct QNODE *front){
	while(front != NULL){
		printf("%d\t", front->item);
		front = front->next;
	}
	printf("\n");
}