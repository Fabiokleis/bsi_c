#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
void imprimeVetorInverso(int v[], int n);

int main()
{
    int vetor[N],aux,i;

    srand(time(NULL));

    printf("Digite um limite para o valor aleatorio: ");
    scanf("%d", &aux);

    printf("\nPreenchendo o vetor com valores aleatorios entre 1 e %d! \n", aux);
    preencheVetor(vetor, N, aux);

   printf("\nImpressao do vetor na ordem direta e na ordem inversa! \n");
   imprimeVetor(vetor, N);
   imprimeVetorInverso(vetor, N);

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


void imprimeVetorInverso(int v[], int n){

    int i;

    for(i=n-1; i>=0; i--)
        printf("%d ", v[i]);
    printf("\n");
}
