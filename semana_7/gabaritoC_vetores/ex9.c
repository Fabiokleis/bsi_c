#include <stdio.h>
#include <stdlib.h>

#define N 10

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
void intercalaVetores(int v1[], int v2[], int v3[], int n);

int main ()
{
    int vetor[N],
        aux, //maior valor a ser inserido no vetor
        maior, menor, //para armazenar o menor e o maior elemento
        vetor2[N], //para o exercício 06
        vetorIntercalado[2*N]; //para o exercício 06

    printf("Digite um limite para o valor aleatorio: ");
    scanf("%d", &aux);

    printf("\nPreenchendo os vetores com valores aleatorios entre 1 e %d! \n", aux);
    preencheVetor(vetor, N, aux);
    preencheVetor(vetor2, N, aux);
    printf("Vetor 1: ");
    imprimeVetor(vetor, N);
    printf("Vetor 2: ");
    imprimeVetor(vetor2, N);
    printf("Vetor Intercalado: ");
    intercalaVetores(vetor, vetor2, vetorIntercalado, N);
    imprimeVetor(vetorIntercalado, 2*N);
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

void intercalaVetores(int v1[], int v2[], int v3[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        v3[2*i]= v1[i];
        v3[2*i+1]= v2[i];
    }
}



