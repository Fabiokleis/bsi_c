#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

float mediaVetor(int v[], int n, int *max, int *min);

int main(){
    int i, j, min, max;
    int vetor[N];
    float media;

    srand(time(NULL));

    for(i=0; i < N; i++){
        vetor[i] = rand() % N+1;
    }
    for(i=0; i < N; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
    media = mediaVetor(vetor, N, &max, &min);
    printf("media dos n pares = %f\nmax = %d e min = %d\n", media, min, max);

    return 0;
}

float mediaVetor(int v[], int n, int *max, int *min){
    int i, soma=0, pp=0;
    for(i=0; i < n; i++){
        if(v[i] % 2 == 0){
            soma += v[i];
            pp++;
        }
        if(v[i] > *max){
            *max = v[i];
        }
        if(v[i] < *min){
            *min = v[i];
        }
    }

    return (soma/pp);
}


