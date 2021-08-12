#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *criaVetor(int tam, int lim, int **vetor);

int main(){
    int *vetor, i, tam, lim;
    printf("tam e lim: ");
    scanf("%d %d", &tam, &lim);
    criaVetor(tam, lim, &vetor);
    for(i=0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}

void *criaVetor(int tam, int lim, int **vetor){
    int i;

    *vetor = (int*) malloc(tam * sizeof (int));
    if(*vetor == NULL){
        printf("ERRO\n");
        exit;
    }
    srand(time(NULL));

    for(i=0; i < tam; i++){
        (*vetor)[i] = rand() % lim+1;
    }
}
