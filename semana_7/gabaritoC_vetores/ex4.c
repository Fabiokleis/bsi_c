#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetor(int v[], int n, int lim);


int main()
{
    int vetor[N],aux,i;

    srand(time(NULL));

    printf("Digite um limite para o valor aleatorio: ");
    scanf("%d", &aux);

    printf("\nPreenchendo o vetor com valores aleatorios entre 1 e %d! \n", aux);
    preencheVetor(vetor, N, aux);

    for(i=0;i<N;i++)
        printf("%d  ",vetor[i]);

    printf("\n");

    return 0;
}


void preencheVetor(int v[], int n, int lim){

    int i;

    for(i=0; i<n; i++)
        v[i] = rand()%lim+1;
}
