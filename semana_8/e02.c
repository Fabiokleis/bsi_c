#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// o programa funciona supondo que o tamanho do primeiro vetor sempre é maior que o tamanho do segundo vetor

void alcVetor(int **vetor, int tam);
int *multVetor(int **vetor, int **vetor2, int tam, int tam2);

int main(){
    int *vetor, *vetor2, *vetor3;
    int tam, tam2, i;

    printf("vetor1[] (tamanho): ");
    scanf("%d", &tam);
    printf("vetor1[%d]: ", tam);
    alcVetor(&vetor, tam);

    printf("vetor2[] (tamanho): ");
    scanf("%d", &tam2);
    printf("vetor2[%d]: ", tam2);
    alcVetor(&vetor2, tam2);
    vetor3 = multVetor(&vetor, &vetor2, tam, tam2);
    printf("vmult: ");
    for(i=0; i < (tam*tam2); i++){
        printf("%d ", vetor3[i]);
    }
    printf("\n");

    free(vetor);
    free(vetor2);
    free(vetor3);
    return 0;
}

void alcVetor(int **vetor, int tam){
    int i;
    *vetor = (int*) malloc(tam * sizeof (int));
    if(*vetor == NULL){
        printf("ERRO\n");
        exit(1);
    }
    srand(time(NULL));
    
    for(i=0; i < tam; i++){
        (*vetor)[i] = rand() % 10+1;
        printf("%d ", (*vetor)[i]);
    }
    printf("\n");
}

int *multVetor(int **vetor, int **vetor2, int tam, int tam2){
    int i, *retV, k=0, j=0, ctr;
    int tt = tam*tam2;
    retV = (int*) malloc(tt * sizeof (int));
    if(retV == NULL){
        printf("ERRO\n");
        exit;
    }
    for(i=0; i < tt; i++){
        if(i == tam2){
            k++;
            j=0;
        }
        retV[i] = ((*vetor2)[j]) * ((*vetor)[k]);
        j++;
    }
    return retV;
}
