#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetor(int tam, int lim);

int main(){
    int *vetor, i;
    vetor = criaVetor(10, 100);
    for(i=0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}

int *criaVetor(int tam, int lim){
    int *vetor, i;

    vetor = (int*) malloc(tam * sizeof (int));
    if(vetor == NULL){
        printf("ERRO\n");
        exit;
    }
    srand(time(NULL));

    for(i=0; i < tam; i++){
        vetor[i] = rand() % lim+1;
    }

    return vetor;
}
