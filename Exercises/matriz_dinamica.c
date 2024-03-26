#include <stdio.h>
#include <stdlib.h>

int main(void){
    int **p = (int**) malloc(10 * sizeof(int *));
    for(int i = 0; i < 10; i++){
        p[i] = (int*)malloc(10 * sizeof(int));
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            p[i][j] = (i+1) * (j+1);
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
    printf("4 x 8 = %d", p[3][7]);
    
    printf("\n");

}