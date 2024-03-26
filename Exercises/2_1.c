#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void insereInicio(No **lista, int valor){
    No *novo = (No*) malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
}

void imprimeLista(No *lista){
    No *current = lista;
    while(current != NULL){
        printf(" %d", current->valor);
        current = current->proximo;
    }
    printf("\n");
}

int maiores(No* l, int n){
    No *current = l;
    int count = 0;
    while(current){
        if(current->valor > n){
            count ++;
        }
        current = current->proximo;
    }
    return count;
}

int list_length(No *lista){
    int length = 0;
    No *current = lista;
    while (current != NULL){
        length++;
        current = current->proximo;
    }
    return length;
}

No* ultimo(No* l){
    No*current = l;
    while(current->proximo){
        current = current->proximo;
    }
    return current;
}

No* concatena(No* l1, No* l2){
    No* current = l1;
    No* last = ultimo(l1);
    last->proximo = l2;
    return l1;
}

No* retira_n(No* l1, int n){
    No* current = l1;
    No* previous = NULL;
    while(current){
        if(current->valor == n){
            if(previous){
                previous->proximo = current->proximo;
            } else {
                l1 = current->proximo;
            }
            No* temp = current;
            current = current->proximo;
            free(temp);
        }
        else {
            previous = current;
            current = current->proximo;
        }
    }
    return l1;
}

No* separa(No* l, int n){
    No* current = l;
    while(current){
        if(current->valor == n){
            No* nova = current->proximo;
            return nova;
        }
        current = current->proximo;
    }
    return l;
}

// intercala duas listas l1 l2 l1 l2 l1 l2

No* merge(No* p, No* q){
    No* p_current = p;
    No* q_current = q;
    No* p_next;
    No* q_next;

    No* nova_lista = NULL;
    No* nova_lista_current = NULL;

    while(p_current && q_current){
        p_next = p_current->proximo;
        q_next = q_current->proximo;

        if(nova_lista == NULL){
            nova_lista = p_current;
            nova_lista_current = nova_lista;
        }
        else {
            nova_lista_current->proximo = p_current;
            nova_lista_current = nova_lista_current->proximo;
        }
        nova_lista_current->proximo = q_current;
        nova_lista_current = nova_lista_current->proximo;

        p_current = p_next;
        q_current = q_next;

    }

    if(p_current){
        nova_lista_current->proximo = p_current;
    }
    if(q_current){
        nova_lista_current->proximo = q_current;
    }

    return nova_lista;
}

void adiciona_no_fim(No** l, int num){
    No* novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*l == NULL){
            *l = novo;
        } else{
            No* current = *l;
            while(current->proximo){
                current = current->proximo;
            }
            current->proximo = novo;
        }
    }
}

void remove_do_inicio(No** l){
    if(*l){
        No* temp = *l;
        *l = (*l)->proximo;
        free(temp);
    }
}

void remove_do_final(No** l){
    if(*l){
        if((*l)->proximo == NULL){
            free(*l);
            *l = NULL;
        }
        else {
            No* current = *l;
            No* previous = NULL;
            while(current->proximo){
                previous = current;
                current = current->proximo;
            }
            free(current);
            previous->proximo = NULL;
        }
    }
}

void adiciona_no_meio(No** l, int num, int pos){
    No* novo = (No*) malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(pos == 0){
            novo->proximo = *l;
            *l = novo;
        }
        else {
            No* current = *l;
            No* previous = NULL;
            int i = 0;
            while(current && i < pos){
                previous = current;
                current = current->proximo;
                i++;
            }
            if(current){
                novo->proximo = current;
                previous->proximo = novo;
            }
            else {
                free(novo);
            }
        }
    }
}

No* inverte_lista(No* l){
    No* current = l;
    No* previous = NULL;
    No* next = NULL;
    while(current){
        next = current->proximo;
        current->proximo = previous;
        previous = current;
        current = next;
    }
    return previous;
}

int main(void){

    No *lista = NULL;
    No *lista2 = NULL;
    insereInicio(&lista, 5);
    insereInicio(&lista, 10);
    insereInicio(&lista, 30);
    adiciona_no_fim(&lista, 40);
    adiciona_no_meio(&lista, 20, 2);

    insereInicio(&lista2, 50);
    insereInicio(&lista2, 60);
    insereInicio(&lista2, 70);

    printf("Tamanho da lista 1: %d\n", list_length(lista));
    imprimeLista(lista);
    
    printf("Tamanho da lista 2: %d\n", list_length(lista2));
    imprimeLista(lista2);

    // No* lista_concat = concatena(lista, lista2);
    // printf("Tamanho da lista concatenada: %d\n", list_length(lista_concat));
    // imprimeLista(lista_concat);

    // retira_n(lista, 20);
    // printf("Tamanho da lista 1: %d\n", list_length(lista));
    // imprimeLista(lista);

    // No* lista_separada = separa(lista, 10);
    // printf("Tamanho da lista 1: %d\n", list_length(lista_separada));
    // imprimeLista(lista_separada);

    // printf("Tamanho da lista 1: %d\n", list_length(lista));
    // imprimeLista(lista);

    // No* merged_list = merge(lista, lista2);
    // printf("Tamanho da lista merge: %d\n", list_length(merged_list));
    // imprimeLista(merged_list);

}
