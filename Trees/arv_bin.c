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

void balanceia(Tree* raiz){
    if(raiz){
        if(altura_arvore(raiz->esq) - altura_arvore(raiz->dir) == 2){
            if(altura_arvore(raiz->esq->esq) - altura_arvore(raiz->esq->dir) == -1){
                raiz->esq = inverte_esquerda(raiz->esq);
            }
            raiz = inverte_direita(raiz);
        }
        else if(altura_arvore(raiz->esq) - altura_arvore(raiz->dir) == -2){
            if(altura_arvore(raiz->dir->esq) - altura_arvore(raiz->dir->dir) == 1){
                raiz->dir = inverte_direita(raiz->dir);
            }
            raiz = inverte_esquerda(raiz);
        }
    }
} // verificar isso

int main(void){
    // 9,3,4,1,6,7
    Tree *raiz = cria_arvore_vazia();
    raiz = insere_arvore(raiz, 9);
    raiz = insere_arvore(raiz, 3);
    raiz = insere_arvore(raiz, 4);
    raiz = insere_arvore(raiz, 1);
    raiz = insere_arvore(raiz, 6);
    raiz = insere_arvore(raiz, 7);
    raiz = insere_arvore(raiz, 10);
    raiz = insere_arvore(raiz, 8);


    printTree(raiz);

    printf("Número de nós: %d\n", conta_nos(raiz));

    //limpa_arvore(&raiz);

    printf("Número de nós: %d\n", conta_nos(raiz));

    printf("Altura da árvore: %d\n", altura_arvore(raiz));

    balanceia(raiz);

    printTree(raiz);

    return 0;
}

// compile: gcc arv_bin.c -o arv_bin