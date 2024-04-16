#include <stdio.h>
#include <stdlib.h>

// fila com vetor
#define MAX 100

struct fila {
    int inicio, n;
    int vet[MAX];
};

typedef struct fila Fila;

Fila* fila_cria(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->n = 0;
    return f;
}

void fila_insere(Fila* f, int v){
    if (f->n == MAX) {
        printf("Capacidade da fila estourou.\n");
        exit(1);
    }
    int fim = (f->inicio + f->n) % MAX;
    f->vet[fim] = v;
    f->n++;
}

int fila_retira(Fila* f){
    if(f->n == 0){
        printf("Fila vazia.\n");
        exit(1);
    }
    int v = f->vet[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    f->n--;
    return v;
}

void fila_libera(Fila* f){
    free(f);
}

// fila com lista

typedef struct no{
    int valor;
    struct no* next;
} Lista;


struct fila {
    Lista* ini;
    Lista* fim;
}

Fila* fila_cria(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, int v){ // para inserir, insere no fim 
    Lista* new = (Lista*) malloc(sizeof(Lista));
    new->valor = v;
    new->next = NULL;
    if(f->fim != NULL) f->fim->next = new;
    else f->inicio = new;
    f->fim = new;
}

int fila_vazia(Fila* f){
    return (f->inicio == NULL);
}

int fila_retira(Fila* f){
    Lista* sai;
    int v;
    if(fila_vazia(f)){
        printf("Fila Vazia\n");
        exit(1);
    }
    sai = f->inicio; // o que sai é o inicio 
    v = sai->valor;
    f->inicio = sai->next;
    if(f->inicio == NULL){
        f->fim == NULL;
    }
    free(sai);
    return v;
}

void fila_libera(Fila* f){
    Lista* q = f->inicio;
    while(q){
        Lista* t = q->next;
        free(q);
        q = t;
    }
    free(f);
}

// Fila duplamente encadeada

struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;


struct fila {
    Lista2* ini;
    Lista2* fim;
};

Fila* fila_cria(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere_ini(Fila2* f, int v){
    Lista2* new = (Lista2*) malloc(sizeof(Lista2));
    new->info = v;
    new->prox = f->ini;
    new->ant = NULL;
    if(f->ini != NULL) f->ini->ant = new;
    else f->fim = new;
    f->ini = new;
}

void fila_insere_fim(Fila2* f, int v){
    Lista2* new = (Lista2*) malloc(sizeof(Lista2));
    new->info = v;
    new->prox = NULL;
    new->ant = f->fim;
    if(f->fim != NULL) f->fim->prox = new;
    else f->ini = new;
    f->fim = new;
}

int fila_retira_inicio(Fila2* f){
    if(f->ini == NULL){
        printf("Fila vazia\n");
        exit(1);
    }
    Fila2* sai = f->ini;
    int v = sai->info;
    f->ini = sai->prox;
    if(f->ini == NULL) f->fim = NULL;   
    free(sai);
    return v;
}

int fila_retira_fim(Fila2* f){
    if(f->fim == NULL){
        printf("Fila vazia\n");
        exit(1);
    }
    Fila2* sai = f->fim;
    int v = sai->info;
    f->fim = sai->ant;
    if(f->fim == NULL) f->ini = NULL;
    free(sai);
    return v;
}

Fila *copia_fila_mantendo_a_original(Fila* f){
    Fila* copia = fila_cria();
    Fila* aux = fila_cria();
    while(!fila_vazia(f)){
        int v = fila_retira(f);
        fila_insere(aux, v);
    }
    while(!fila_vazia(aux)){
        int v = fila_retira(aux);
        fila_insere(f, v);
        fila_insere(copia, v);
    }

    return copia;
}

