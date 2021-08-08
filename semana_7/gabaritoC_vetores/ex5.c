#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencheVetorIntervalo(int v[], int n, int min, int max);


int main()
{
    int vetor[N],minimo, maximo,i;

    srand(time(NULL));

    do{
        printf("Digite dois valores que representam um intervalo  para o valor aleatorio: ");
        scanf("%d %d", &minimo, &maximo);

        if(minimo > maximo)
            printf("o primeiro deve ser menor. Tente novamente...");

    }while(minimo>maximo);

    printf("\nPreenchendo o vetor com valores aleatorios entre %d e %d! \n", minimo, maximo);
    preencheVetorIntervalo(vetor, N, minimo, maximo);

    for(i=0;i<N;i++)
        printf("%d  ",vetor[i]);

    printf("\n");

    return 0;
}


void preencheVetorIntervalo(int v[], int n, int min, int max){

    int i;

    for(i=0; i<n; i++)
        v[i] = min + rand()%(max-min+1);
}
