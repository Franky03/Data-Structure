#include <stdio.h>
#define SIZE 11


int main(void){
    int lista_o[SIZE] = {3,5,8,9,15,17,21,34,60,99};
    int value = 18;
    lista_o[SIZE - 1] = value;
    for(int i = SIZE - 1; i > 0; i--){
        if(lista_o[i] > lista_o[i - 1]){
            break;
        }
        int temp = lista_o[i];
        lista_o[i] = lista_o[i - 1];
        lista_o[i - 1] = temp;
    }
    for(int i = 0; i < SIZE; i++){
        printf("%d ", lista_o[i]);
    }
    return 0;
}