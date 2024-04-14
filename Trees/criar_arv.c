#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv* cria_arvore(int info, Arv* esq, Arv* dir){
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->info = info;
    p->esq = esq;
    p->dir = dir;
    return p;
}

void imprime_arvore(Arv* a){
    if(a != NULL){
        printf("%d ", a->info);
        imprime_arvore(a->esq);
        imprime_arvore(a->dir);
    } else {
        return;
    }
}

Arv* limpa_arvore(Arv* raiz){
    if(raiz){
        raiz->esq = limpa_arvore(raiz->esq);
        raiz->dir = limpa_arvore(raiz->dir);
        free(raiz);
        return (0);
    }
    else {
        return 0;
    }
}

int main(){
    Arv* a = cria_arvore(1, cria_arvore(2, NULL, NULL), cria_arvore(3, NULL, NULL));
    a->esq->esq = cria_arvore(4, NULL, NULL);
    a->esq->dir = cria_arvore(5, NULL, NULL);
    imprime_arvore(a);
    limpa_arvore(a);
    printf("%d", a->info);
    return 0;
}