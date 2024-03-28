#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *items;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->items = (int*) malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

int isFull(Queue *q){
    return q->rear == q->size - 1;
}

int isEmpty(Queue *q){
    return q->front == -1;
}

void enqueue(Queue *q, int item){
    if(isFull(q)){
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->items[++q->rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->size;
    q->size = q->size - 1;
    return item;
}

int front(Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    return q->items[q->front];
}





    