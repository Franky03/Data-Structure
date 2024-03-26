void inverte(int *vector, int n){
    int i, j, temp;
    for (i = 0; j = n - 1; i < j; i++, j--){
        temp = vector[i];
        vector[i] = vector[j];
        vector[j] = temp;
    }
}