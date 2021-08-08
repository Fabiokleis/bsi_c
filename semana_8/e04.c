#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int dd);
void preencheMatriz(int **mt, int dd);
void alocaVetor(int *vetor, int dd);
int custo_cidades(int *cidades, int n_cidades, int **m);

int main(){
    int i, dd=0, it=0;
    int **mt, *vetor;
    printf("dimensão da matriz de custo: ");
    scanf("%d", &dd);
    mt = alocaMatriz(dd);
    preencheMatriz(mt, dd);
    printf("tamanho do itinerario: ");
    scanf("%d", &it);
    alocaVetor(vetor, it); 
    for(i=0; i < dd; i++){
        free(mt[i]);
    }
    free(mt);
    return 0;
}

int **alocaMatriz(int dd){
    int i, **mt;
    mt = (int**) malloc(dd * sizeof(int*));
    if(mt == NULL){
        printf("ERROR\n");
        exit(1);
    }
    for(i=0; i < dd; i++){
        mt[i] = (int*) malloc(dd * sizeof(int));
    }
    return mt;
}

void alocaVetor(int *vetor, int dd){
    vetor = (int *) malloc(dd * sizeof(int));
    if(vetor == NULL){
        printf("ERROR\n");
        exit(1);
    }
}

void preencheMatriz(int **mt, int dd){
    int i, j, ctr=0;
    for(i=0; i < dd; i++){
        for(j=0; j < dd; j++){
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &ctr);
            mt[i][j] = ctr;
        }
    }
    printf("\nMatriz alocado e preenchida.\n\n");
    for(i=0; i < dd; i++){
        for(j=0; j < dd; j++){
            printf("|%.2d", mt[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

}
