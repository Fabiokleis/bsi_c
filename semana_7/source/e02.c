#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main(){
    int uN, i, j;
    int vetor[N];
    srand(time(NULL));

    for(i=0; i < N; i++){
        vetor[i] = rand() % N+1;
    }

    for(i=0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("escolha uma posição do vetor[0-9]: ");
    scanf("%d", &uN);

    
    for(i=uN; i < N; i++){
        vetor[i] = vetor[i+1];
    }
    for(i=0; i < N-1; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
