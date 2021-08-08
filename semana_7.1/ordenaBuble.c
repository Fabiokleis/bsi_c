#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void ordenaBuble(int n, int v[]);
void troca(int *a, int *b);

int main(){
    int vet[N], i, n;
    srand(time(NULL));
    n = rand() % N+1;
    for(i=0; i < n; i++){
        vet[i] = rand() % 10;
        printf("%d ", vet[i]);
    }
    ordenaBuble(n, vet);
    printf("\n");
    for(i=0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}

void ordenaBuble(int n, int v[]){
    int i, j;
    for(i=1; i < n; i++){
        for(j=0; j < n-i; j++){
            if(v[j] > v[j+1]){
                troca(&v[j], &v[j+1]);
            }
        }
    }
}

void troca(int *a, int *b){
    int tmp;

    if(*a > *b){
        tmp = *b;
        *b=*a;
        *a=tmp;
    }

}
