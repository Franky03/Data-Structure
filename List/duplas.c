#include <stdio.h>
#include <stdlib.h>

struct no {
    int value;
    struct no *next;
    struct no *prev;
};

typedef struct no No;

struct lista {
    No* inicio;
    No* fim;
    int tam;
};

typedef struct lista Lista;

Lista* list_create(){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void lista_insere(Lista *l, int v){
    No* novo = (No*)malloc(sizeof(No));
    novo->value = v;
    if(l->tam == 0){
        l->inicio = novo;
        l->fim = novo;
        l->tam++;
    }
    else if(l->tam == 1){
        l->inicio->next = novo;
        l->inicio->prev = novo;
        l->fim = novo;
        novo->next = l->inicio;
        novo->prev = l->inicio;

        l->tam++;
    }
    else {
        l->inicio->prev = novo;
        novo->next = l->inicio;
        novo->prev = l->fim;
        l->fim->next = novo;
        l->fim = novo;
        l->tam++;
    }
}

void lista_remove(Lista *l, int v){
    No* p = l->inicio;
    while(p->next != l->inicio){
        if(p->value == v){
            if(p == l->inicio){
                l->inicio = p->next;
                l->inicio->prev = l->fim;
                l->fim->next = l->inicio;
                free(p);
                l->tam--;
                return;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
                l->tam--;
                return;
            }
        }
        p = p->next;
    }
    if(p != NULL && p->value == v){
        if(l->tam == 1){
            free(p);
            l->inicio = NULL;
            l->fim = NULL;
            l->tam--;
            return;
        } else {
            l->fim = p->prev;
            l->fim->next = l->inicio;
            l->inicio->prev = l->fim;
            free(p);
            l->tam--;
            return;
        }
    }

}

void lista_imprime(Lista *l){
    No* p = l->inicio;
    printf("%d ", p->value);
    p = p->next;
    int cont = 0;
    while(1){
        printf("%d ", p->value);
        p = p->next;
        if(p == l->inicio) cont++;
        if(cont == 1) break;
    }
}

No* list_insert(No* l, int v){
    No* novo = (No*)malloc(sizeof(No));
    novo->value = v;
    novo->next = l;
    novo->prev = NULL;

    if(l != NULL){
        l->prev = novo;
    }

    return novo;
}

No* busca_elemento(No* l, int v){
    for(No* p = l; p != NULL; p=p->next){
        if(p->value == v){
            return p;
        }
    }
    return NULL;
}

No* list_remove(No* l, int v){
    No* sai = busca_elemento(l, v);
    if(sai==NULL){
        return l;
    }

    if(l == sai) l = sai->next; // se for o primeiro elemento da lista
    else sai->prev->next = sai->next;

    if(sai->next != NULL) sai->next->prev = sai->prev; // se o próximo elemento não for nulo

    free(sai);

    return l;
}


int main(void){
    Lista *l = list_create();
    for(int i = 0; i < 10; i++){
        lista_insere(l, i);
    }
    lista_imprime(l);
    printf("\n");


    for(int i = 0; i < 10; i++){
        lista_remove(l, i);
        if(l->tam == 0){
            printf("Lista vazia\n");
        } else {
            lista_imprime(l);
            printf("\n");
        }
    }

}