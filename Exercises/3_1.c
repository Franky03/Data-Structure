int negativos(float *vetor, int n) {
    int i, negativos = 0;
    for (i = 0; i < n; i++) {
        if (vetor[i] < 0) {
            negativos++;
        }
    }
    return negativos;
}

