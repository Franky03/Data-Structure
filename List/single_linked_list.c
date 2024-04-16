#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} * list;

void insert(struct Node** head, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void remove(struct Node** head){
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_last(struct Node** head){
    struct Node* temp, *to_remove;
    if(*head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    temp = *head;
    if(temp->next == NULL){
        to_remove = temp;
        *head = NULL;
    }
    else {
        for(temp = *head; temp->next->next ; temp = temp->next);
        to_remove = temp->next;
        temp->next = NULL;
    }
}

void remove_num(struct Node** head, int num){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while(temp != NULL && temp->data != num){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    if(prev == NULL) *head = temp->next;
    else prev->next = temp->next;
}

void initialize(struct Node** head){
    *head = NULL;
}

void print(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void clean(struct Node** head){
    while(*head != NULL){
        remove(head);
    }
}

void recursive_clean(struct Node** head){
    if(*head == NULL) return;
    recursive_clean(&(*head)->next);
    printf("Removing %d\n", (*head)->data);
    free(*head);
    *head = NULL;
}

int main(){
    initialize(&list);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 4);
    insert(&list, 5);
    insert(&list, 0);
    print(list);
    recursive_clean(&list);


    return 0;
}
