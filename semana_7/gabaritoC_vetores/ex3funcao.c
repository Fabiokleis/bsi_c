#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10 //definição de uma constante

void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
void imprimeSomaVetores(int v1[], int v2[], int n);

int main(){
    //declaração de variáveis
    int v1[TAM], v2[TAM], i;

    //inicialização da semente para a funcao rand
    srand(time(NULL));

    //preenchimento dos vetores
     preencheVetor(v1,TAM,10);
     preencheVetor(v2,TAM,10);


    printf("Primeiro vetor: ");
    imprimeVetor(v1,TAM);

    printf("\nSegundo vetor: ");
    imprimeVetor(v2,TAM);

    //como é preciso apenas mostrar a soma, não será criado um novo vetor
    //para armazenar o resultado
    printf("\nSoma: ");
    imprimeSomaVetores(v1,v2,TAM);

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

void imprimeSomaVetores(int v1[], int v2[], int n)
{
      int i;

    for(i=0; i<n; i++)
        printf("%3d ", v1[i] + v2[n-i-1]);
    printf("\n");

}
