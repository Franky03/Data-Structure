#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue *createQueue(unsigned capacity){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = queue->capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue *q){
    return q->size == q->capacity;
}

int isEmpty(Queue *q){
    return q->size == 0;
}

void enqueue(Queue *q, int item){
    if(isFull(q)){
        return;
    }
    q->rear = (q->rear + 1) % q->capacity; //* isso é para garantir que o rear não ultrapasse o limite do array
    q->array[q->rear] = item;
    q->size = q->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity; //* isso coloca o front como sendo o próximo da fila 
    q->size = q->size - 1;
    return item;
}

int front(Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    return q->array[q->front];
}

int rear(Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    return q->array[q->rear];
}

int main(void){
    Queue *my_queue = createQueue(100);
    enqueue(my_queue, 10);
    enqueue(my_queue, 20);
    enqueue(my_queue, 30);
    enqueue(my_queue, 40);

    printf("Front item is %d\n", front(my_queue));
    printf("%d dequeued from queue\n", dequeue(my_queue));
    printf("Front item is %d\n", front(my_queue));

    printf("Rear item is %d\n", rear(my_queue));

    return 0;
}