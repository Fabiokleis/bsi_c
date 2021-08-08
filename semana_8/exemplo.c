#include <stdio.h>
#include <stdlib.h>
#define BUFLEN 11


void mostra10(double *vetor);

int main(){
    int i;
    double *vetor;
    vetor = (double*) malloc(BUFLEN * sizeof (double));
    if(vetor == NULL){
        printf("ERRO\n");
        return 1;
    }
    for(i=0; i < BUFLEN; i++){
        vetor[i] = i*i;
    }
    mostra10(vetor);
    printf("\n");
    free(vetor);
    return 0;
}

void mostra10(double *vetor){
    int i;
    for(i=0; i < 10; i++){
        printf("%.2lf ", vetor[i]);
    }
}
