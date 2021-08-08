#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
float mediaPares(int v[], int n);

int main()
{
    int vetor[N],aux,i;

    srand(time(NULL));

    printf("Digite um limite para o valor aleatorio: ");
    scanf("%d", &aux);

    printf("\nPreenchendo o vetor com valores aleatorios entre 1 e %d! \n", aux);
    preencheVetor(vetor, N, aux);

   printf("\nImpressao do vetor \n");
   imprimeVetor(vetor, N);

   printf("\nMedia dos pares: %.2f. \n", mediaPares(vetor, N));

    printf("\n");

    return 0;
}


void preencheVetor(int v[], int n, int lim){

    int i;

    for(i=0; i<n; i++)
        v[i] = rand()%lim+1;
}

void imprimeVetor(int v[], int n){

    int i;

    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

float mediaPares(int v[], int n){
    int i,
        soma=0, contPar=0; //inicializa variáveis

    for(i=0; i<n; i++){
        if(v[i]%2 == 0){
            soma = soma + v[i];
            contPar++;
        }
    }
    return (float)soma/contPar; // não se esqueça de fazer o casting: int/int!!
}



