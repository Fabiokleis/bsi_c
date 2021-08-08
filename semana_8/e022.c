#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criaVetor(int tam, int **vetor);
int *multV(int **vetor, int **vetor2, int tam);

int main(){
    int i, tam, tam2;
    int *vetor, *vetor2, *vetor3;
    printf("vetor1[] (tamanho): ");
    scanf("%d", &tam);
    printf("vetor2[] (tamanho): ");
    scanf("%d", &tam2);
    criaVetor(tam, &vetor);
    for(i=0; i < tam; i++){
        printf("%d ", vetor3[i]);
    }
    printf("\n");
    free(vetor);
    free(vetor2);
    free(vetor3);
    return 0;
}

void criaVetor(int tam, int **vetor){
    int i;
    *vetor = (int*) malloc(tam * sizeof (int));
    if(*vetor == NULL){
        printf("ERROR\n");
        exit;
    }
    srand(time(NULL));
    for(i=0; i < tam; i++){
        (*vetor)[i] = rand() % 10;
        printf("%d ", *[]);
    }
}
