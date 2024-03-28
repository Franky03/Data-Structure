#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Implementação de pilha com vetor 
typedef struct {
    int top;
    int items[MAX];
} Stack;


Stack* cria_pilhas(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = 0;
    return stack;
}

Stack* pilha_push(Stack* stack, int item){
    if(stack->top == MAX){
        printf("Pilha cheia\n");
    } else {
        stack->items[stack->top++] = item;
    }
    return stack;
}

int pilha_pop(Stack* stack){
    int item;
    if(stack->top == 0){
        printf("Pilha vazia\n");
        return -1;
    } else {
        item = stack->items[--stack->top];
    }
    return item;
}

// Pilha com lista

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} StackList;

StackList* cria_pilha_lista(){
    StackList* stack = (StackList*) malloc(sizeof(StackList));
    stack->top = NULL;
    return stack;
}
 
StackList* pilha_push_lista(StackList* stack, int item){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = item;
    node->next = stack->top;
    stack->top = node;
    return stack;
}

int pilha_pop_lista(StackList* stack){
    int item;
    Node* node;
    if(stack->top == NULL){
        printf("Pilha vazia\n");
        return -1;
    } else {
        node = stack->top;
        stack->top = node->next;
        item = node->data;
        free(node);
    }
    return item;
}

int main(){
    StackList* stack = cria_pilha_lista();
    stack = pilha_push_lista(stack, 1);
    stack = pilha_push_lista(stack, 2);
    stack = pilha_push_lista(stack, 3);

    int items[5] = {};
    for(int i = 0; i < 5; i++){
        items[i] = i;
        stack = pilha_push_lista(stack, items[i]);
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d\n", pilha_pop_lista(stack));
    }

    


    return 0;
}
