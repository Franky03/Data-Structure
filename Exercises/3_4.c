double avalia(double *poli, int grau, double x){
    double result = 0;
    for(int i = 0; i<=grau; ++i){
        result += poli[i] * pow(x, i);
    }
    return result;
}

int main(){
    double poli[3] = {1, 2, 3}; // 1 + 2x + 3x^2
    int grau = 2;
    double x = 2;
    printf("%f\n", avalia(poli, grau, x));
    return 0;
}