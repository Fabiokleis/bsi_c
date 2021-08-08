#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criaVetor(int tam, int lim, int **vetor);
int *expandeVetor(int *v, int tam, int n, int lim);

int main(){
    int lim, i, tam, n;
    int *vetor;
    printf("limite: ");
    scanf("%d", &lim);
    printf("tam: ");
    scanf("%d", &tam);
    criaVetor(tam, lim, &vetor);
    printf("vetor[0-%d]: ", tam-1);
    for(i=0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("quantos valores novos: ");
    scanf("%d", &n);
    expandeVetor(vetor, tam, n, lim);
    printf("vetor[0-%d]: ", tam+n-1);
    for(i=0; i < (tam+n); i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}

void criaVetor(int tam, int lim, int **vetor){
    int i;
    *vetor = (int*) malloc(tam * sizeof (int));
    if(*vetor == NULL){
        printf("ERROR\n");
        exit(1);
    }
    srand(time(NULL));
    for(i=0; i < tam; i++){
        (*vetor)[i] = (rand() % ((lim*2)+1)) + (-lim);
    }
}

int *expandeVetor(int *v, int tam, int n, int lim){
    int i;
    srand(time(NULL));
    v = (int*) realloc(v, (tam+n));
    if(v == NULL){
        printf("ERROR\n");
        exit(1);
    }
    for(i=tam; i < (tam+n); i++){
        v[i] = (rand() % ((lim*2)+1)) + (-lim);
    }
}

