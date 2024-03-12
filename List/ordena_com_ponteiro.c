#include <stdio.h>
#include <stdlib.h>

int main(void){
    int v[5] = {31,34,56,21,10};
    int *p[5];

    for(int i = 0; i < 5; i++){
        p[i] = &v[i];
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", *p[i]);
    }

    printf("\n");

    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(*p[i] > *p[j]){
                int *aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    printf("LISTA ORDENADA\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", *p[i]);
    }

    printf("\n");

    printf("LISTA ORIGINAL\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }

    printf("\n");


}