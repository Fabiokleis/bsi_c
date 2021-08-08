#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void ordem(int v[]);
void rOrdem(int v[]);

int main(){
    int vetor[N];
    int i;
    srand(time(NULL));

    for(i=0; i < N; i++){
        vetor[i] = rand() % N+1;
    }

    ordem(vetor);
    printf("\n");
    rOrdem(vetor);
    printf("\n");
    return 0;
}


void ordem(int v[]){
    int i;

    for(i=0; i < N; i++){
        printf("%d ", v[i]);
    }
}

void rOrdem(int v[]){
    int i;

    for(i=N-1; i >= 0; i--){
        printf("%d ", v[i]);
    }
}

