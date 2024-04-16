#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} Tree;

Tree* cria_arvore_vazia() {
    return NULL;
}

Tree* insere_arvore(Tree *raiz, int valor){
    if(!raiz){
        Tree *novo = (Tree*) malloc(sizeof(Tree));
        if(!novo) return 0;
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else {
        if(valor < raiz->info) raiz->esq = insere_arvore(raiz->esq, valor);
        
        else raiz->dir = insere_arvore(raiz->dir, valor);
        
        return raiz;
    }
}

void printTree2D(Tree* node, int space, char direction) {
    if (node == NULL) return;
    
    space += 10;
    printTree2D(node->dir, space, 'd'); // 'd' indica direita
    printf("\n");
    
    for (int i = 10; i < space; i++) printf(" ");
    
    // Imprime a seta e o valor do nó
    printf("%c->%d\n", direction, node->info);
    
    printTree2D(node->esq, space, 'e'); // 'e' indica esquerda
}

void printTree(Tree* node){
    printTree2D(node, 0,'r');
}

void mostra_arvore(Tree *raiz){
    if(raiz){
        mostra_arvore(raiz->esq);
        printf("%d ", raiz->info);
        mostra_arvore(raiz->dir);
    }
}

void limpa_arvore(Tree **raiz){
    if(*raiz){
        limpa_arvore(&(*raiz)->esq);
        limpa_arvore(&(*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}

int create_for_loop_with_recursion(int n){
    if(n == 0) return 0;
    return 1 + create_for_loop_with_recursion(n-1);

}

int conta_nos(Tree *raiz){
    if(!raiz) return 0;
    return 1 + conta_nos(raiz->esq) + conta_nos(raiz->dir);
}

int altura_arvore(Tree *raiz){
    if(!raiz) return -1;
    int alt_esq = altura_arvore(raiz->esq);
    int alt_dir = altura_arvore(raiz->dir);
    if(alt_esq > alt_dir) return 1 + alt_esq;
    else return 1 + alt_dir;
}

Tree* inverte_esquerda(Tree* raiz){
    if(raiz){
        Tree* aux = raiz->dir;
        raiz->dir = aux->esq;
        aux->esq = raiz;
        raiz = aux;
    }
    return raiz;
}

Tree* inverte_direita(Tree* raiz){
    if(raiz){
        Tree* aux = raiz->esq;
        raiz->esq = aux->dir;
        aux->dir = raiz;
        raiz = aux;
    }
    return raiz;
}

Tree* balanceamento(Tree* raiz){
    if(!raiz) return raiz;

    raiz->esq = balanceamento(raiz->esq);
    raiz->dir = balanceamento(raiz->dir);

    int altura_esq = altura_arvore(raiz->esq); 
    int altura_dir = altura_arvore(raiz->dir);

    if(altura_esq - altura_dir > 1){
        //Rotação à direita 
        if(altura_arvore(raiz->esq->esq) - altura_arvore(raiz->esq->dir) < 0){
            raiz->esq = inverte_esquerda(raiz->esq);
        }
        raiz = inverte_direita(raiz);
        return raiz;
    }
    else if(altura_esq - altura_dir < -1){
        //Rotação à esquerda
        if(altura_arvore(raiz->dir->esq) - altura_arvore(raiz->dir->dir) > 0){
            raiz->dir = inverte_direita(raiz->dir);
        }
        raiz = inverte_esquerda(raiz);
        return raiz;
    }

    return raiz;
}

void balanceia_arvore(Tree** raiz){
    if(!(*raiz)) return;
    *raiz = balanceamento(*raiz);
}

Tree* insere_com_balanceamento(Tree* raiz, int valor){
    raiz = insere_arvore(raiz, valor);
    raiz = balanceamento(raiz);
    return raiz;
}

int main(void){
    // 9,3,4,1,6,7
    Tree *raiz = cria_arvore_vazia();
    raiz = insere_com_balanceamento(raiz, 9);
    raiz = insere_com_balanceamento(raiz, 3);
    raiz = insere_com_balanceamento(raiz, 4);
    raiz = insere_com_balanceamento(raiz, 1);
    raiz = insere_com_balanceamento(raiz, 6);
    raiz = insere_com_balanceamento(raiz, 7);
    raiz = insere_com_balanceamento(raiz, 10);
    raiz = insere_com_balanceamento(raiz, 8);


    printTree(raiz);

    printf("Número de nós: %d\n", conta_nos(raiz));

    //limpa_arvore(&raiz);

    printf("Número de nós: %d\n", conta_nos(raiz));

    printf("Altura da árvore: %d\n", altura_arvore(raiz));

    // balanceia_arvore(&raiz);

    return 0;
}

// compile: gcc arv_bin.c -o arv_bin