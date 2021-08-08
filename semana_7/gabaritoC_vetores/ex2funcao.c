#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
void reduzVetor(int v[], int tam);

int main ()
{
    int valores [N];

    srand(time(NULL));//inicialização da semente

    // Preenche e mostra o vetor.
     preencheVetor(valores,N,10);
     imprimeVetor(valores,N);

     reduzVetor(valores,N);

    // Mostra o vetor resultante
    imprimeVetor(valores,N-1);
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


void reduzVetor(int v[], int tam)
{
    int i,pos;
    // Pede o índice do valor a remover

    do{
          printf ("Que posicao deseja remover (0 a %d)? ",tam-1);
          scanf ("%d", &pos);
    }while(pos>= tam);


    // Desloca todos os valores a partir da posição dada para a esquerda.
    for (i = pos+1; i < tam; i++)
        v[i-1] = v[i];
}
