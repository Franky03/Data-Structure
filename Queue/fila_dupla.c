#include <stdio.h>
#include <stdlib.h>

// Fila dupla 

typedef struct no {
    int dado;
    struct no *prox;
    struct no *ant;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

Fila *criarFila(){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar_final(Fila *f, int dado){ // função para adicionar um elemento no final da fila dupla 
    No *novo = (No *)malloc(sizeof(No)); // aloca memória para o novo nó
    novo->dado = dado;
    novo->prox = NULL; // o novo nó será o último, então o próximo dele é NULL
    novo->ant = f->fim; // o novo nó será o último, então o anterior dele é o antigo último
    if(f->fim != NULL){ // se o fim não for NULL, então a fila não está vazia
        f->fim->prox = novo; // o próximo do antigo último nó será o novo nó
    }
    f->fim = novo; // o novo nó será o último
    if(f->inicio == NULL){ // se o início for NULL, então a fila está vazia
        f->inicio = novo; // o novo nó será o primeiro
    }
}

void enfileirar_inicio(Fila *f, int dado){
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = f->inicio; // o próximo do novo nó será o antigo primeiro
    novo->ant = NULL; // o novo nó será o primeiro, então o anterior dele é NULL
    if(f->inicio != NULL){ // se o início não for NULL, então a fila não está vazia
        f->inicio->ant = novo; // o anterior do antigo primeiro nó será o novo nó
        // por exemplo, se a fila está 1-2-3, e o novo nó é 0, o anterior do inicio (1) será o novo nó (0) 
    }
    f->inicio = novo; // o novo nó será o primeiro
    if(f->fim == NULL){
        f->fim = novo;
    }
}

    void remover_inicio(Fila *f){
        if(f->inicio != NULL){
            No* removido = f->inicio;
            f->inicio = f->inicio->prox;
            if(f->inicio != NULL){
                f->inicio->ant = NULL;
            }
            free(removido);
        }
    }

    void remover_fim(Fila *f){
        if(f->fim != NULL){
            No* removido = f->fim;
            f->fim = f->fim->ant;
            if(f->fim != NULL){
                f->fim->prox = NULL;
            }
            free(removido);
        }
    }

// Fila dupla circular

