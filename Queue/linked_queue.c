#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int key;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

QNode *new_node(int k) {
    QNode *temp = (QNode *)malloc(sizeof(QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL; // ! empty queue 
    return q;
} 

void enqueue(Queue *q, int k) {
    QNode *temp = new_node(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp; // ! add new node at the end of queue
    q->rear = temp; // ! update rear
}

QNode *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

int main() {
    Queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    QNode *n = dequeue(q);
    if (n != NULL) printf("Dequeued item is %d\n", n->key);
    return 0;
}