#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main(){
    int uN, i, j;
    int vetor[N];
    int vetor2[N];
    srand(time(NULL));

    for(i=0; i < N; i++){
        vetor[i] = rand() % N+1;
        vetor2[i] = 10 + rand() % N+1;
    }

    printf("vetor1: ");
    for(i=0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\nvetor2: ");
    for(i=0; i < N; i++){
        printf("%d ", vetor2[i]);
    }
    printf("\nsoma: ");
    j = N;
    for(i=0; i < N; i++){
        j--;
        printf("%d ", vetor[i]+vetor2[j]);
    }

    printf("\n");
    return 0;
}
