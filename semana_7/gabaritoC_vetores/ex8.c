#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
float mediaParesMaiorMenor(int v[], int n, int *maior, int *menor);

int main()
{
    int vetor[N],aux,i,
    med, maior, menor; //para armazenar o menor e o maior elemento

    srand(time(NULL));

    printf("Digite um limite para o valor aleatorio: ");
    scanf("%d", &aux);

    printf("\nPreenchendo o vetor com valores aleatorios entre 1 e %d! \n", aux);
    preencheVetor(vetor, N, aux);

    printf("\nImpressao do vetor \n");
    imprimeVetor(vetor, N);

    med = mediaParesMaiorMenor(vetor, N, &maior, &menor);
    printf("\n A media eh %d, O maior elemento do vetor eh %d e o menor eh %d. \n", med, maior, menor);

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

float mediaParesMaiorMenor(int v[], int n, int *maior, int *menor){
    int i,
        soma=0, contPar=0; //inicializa variáveis

    *maior = v[0]; // é preciso inicializar as variáveis menor e maior!
    *menor = v[0]; // atenção!!

    for(i=1; i<n; i++){
        if(v[i]%2 == 0){
            soma = soma + v[i];
            contPar++;
        }

        if(v[i] < *menor)
            *menor = v[i];
        else if(v[i] > *maior)
            *maior = v[i];
    }
    return (float)soma/contPar; // não se esqueça de fazer o casting: int/int!!
}


