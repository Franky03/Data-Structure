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
} List;

void push(List *list, int number){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = number;
    new_node->next = list->head;// The new node points to the head of the list
    list->head = new_node;// The head of the list is the new node
    list->size++;

}

void append(List *list, int number){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = number;
    new_node->next = NULL;
    if(list->head == NULL){
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
}

void create_list(List *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void print_list(List *list){
    Node *current = list->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void remove_node(List *list, int number){
    Node *current = list->head;
    Node *previous = NULL;
    while(current != NULL && current->data != number){
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        return;
    }
    if(previous == NULL){
        list->head = current->next;
    }
    else{
        previous->next = current->next;
    }
}

int main(){
    List list;
    create_list(&list);
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    push(&list, 5);
    remove_node(&list, 20);
    print_list(&list);

    return 0;
}