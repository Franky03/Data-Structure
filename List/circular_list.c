#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} CircularList;

void insert_init(CircularList *list, int number){
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->data = number;
    new_node->next = list->head;
    list->head = new_node;
    list->tail->next = list->head;
    list->size++;

}

void insert_final(CircularList *list, int number){
    
}