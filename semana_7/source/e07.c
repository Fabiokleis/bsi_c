#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

float mediaVetor(int v[], int n);

int main(){
    int i, j;
    int vetor[N];
    srand(time(NULL));

    for(i=0; i < N; i++){
        vetor[i] = rand() % N+1;
    }

    for(i=0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("media dos n pares = %f\n", mediaVetor(vetor, N));

    return 0;
}

float mediaVetor(int v[], int n){
    int i, soma=0, pp=0;
    for(i=0; i < n; i++){
        if(v[i] % 2 == 0){
            soma += v[i];
            pp++;
        }
    }

    return ((float) soma/pp);
}


