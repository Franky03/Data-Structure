#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int fibo_non_recursive(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int a = 0;
    int b = 1;
    int fibo = 0;
    for(int i = 2; i <= n; i++){
        fibo = a + b;
        a = b;
        b = fibo;
    }
    return fibo;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    // Medição do tempo de execução para fibo(n)
    start = clock();
    printf("Fibonacci of %d is %d\n", n, fibo(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for fibo(): %lf seconds\n", cpu_time_used);

    // Medição do tempo de execução para fibo_non_recursive(n)
    start = clock();
    printf("Fibonacci of %d is %d\n", n, fibo_non_recursive(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for fibo_non_recursive(): %lf seconds\n", cpu_time_used);

    return 0;
}
