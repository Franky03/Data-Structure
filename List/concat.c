#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

Node* criarLista(){
    return NULL;
}

Node* inserir(Node *head, int data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->previous = NULL;
    if(head != NULL) head->previous = newNode;
    return newNode;
}

Node* remover(Node *head, int data){
    Node* sai = NULL;
    for(Node* p = head; p != NULL; p = p->next){
        if(p->data == data){
            sai = p;
        }
    }
    if(sai == NULL) return head;
    if(sai->previous != NULL) sai->previous->next = sai->next;
    if(sai->next != NULL) sai->next->previous = sai->previous;
    if(sai == head) head = sai->next;
    free(sai);
    return head;
}

void imprimir(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void swap(Node *a, Node *b){
    int aux = a->data;
    a->data = b->data;
    b->data = aux;
}

Node* lastNode(Node *l){
    while(l != NULL && l->next != NULL){
        l = l->next;
    }
    return l;
}

Node* partition(Node * a, Node*b){
    int x = b->data;
    Node *i = a->previous;
    Node *k;
    
    for(k = a; k != b; k = k->next){
        if(k->data <= x){
            i = (i == NULL) ? a : i->next;
            swap(i, k);
        }
    }

    i = (i == NULL) ? a : i->next;
    swap(i, b);
    return i;
}

void _quickSort(Node *l, Node *h){
    if(l != NULL && h != NULL && l != h && l != h->next){
        Node *p = partition(l, h);
        _quickSort(l, p->previous);
        _quickSort(p->next, h);
    }
}

void quickSort(Node *head){
    Node *h = lastNode(head);
    _quickSort(head, h);
}

Node* createRandomLists(int n){
    Node *head = criarLista();
    for(int i = 0; i < n; i++){
        head = inserir(head, rand() % 100);
    }
    return head;
}

Node* create_ordered_list(){
    Node* new_list = createRandomLists(10);
    quickSort(new_list);

    return new_list;
}

Node* concat_two_ordered_lists(Node* list1, Node* list2){
    Node* new_list = criarLista();
    Node* last1 = lastNode(list1);
    last1->next = list2;
    list2->previous = last1;

    quickSort(list1);

    return list1;
}

int main(void){
    Node* list1 = create_ordered_list();
    Node* list2 = create_ordered_list();

    imprimir(list1);
    imprimir(list2);

    Node* new_list = concat_two_ordered_lists(list1, list2);

    imprimir(new_list);

    return 0;
}