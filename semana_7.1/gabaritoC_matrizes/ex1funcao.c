#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAML 5
#define TAMC 5
#define LIM 10

void preencheMatriz(int m[][TAMC], int nl, int nc, int num);
void imprimeMatriz(int m[][TAMC], int nl, int nc);
void imprimeTranspostaMatriz(int m[][TAMC], int nl, int nc);


int main()
{
    int m[TAML][TAMC];


    //inicialização da semente do gerador de nros aleatorios
    srand(time(NULL));
    preencheMatriz(m, TAML, TAMC, LIM); // observe que podemos passar valores de nl e nc diferentes (menores) que NLIN e NCOL

    printf("\n\nMatriz original: \n");
    imprimeMatriz(m, TAML, TAMC);

    printf("\n\nTransposta: \n");
    imprimeTranspostaMatriz(m, TAML, TAMC);

    return 0;
}


void preencheMatriz(int m[][TAMC], int nl, int nc, int num)
{
    int i, j;

    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            m[i][j] = rand()%num+1;
}

void imprimeMatriz(int m[][TAMC], int nl, int nc)
{
    int i, j;

    for(i=0; i<nl; i++)
    {
         for(j=0; j<nc; j++)
            printf("%3d ", m[i][j]);
         printf("\n");
    }
}

void imprimeTranspostaMatriz(int m[][TAMC], int nl, int nc)
{
    int i, j;

    for(j=0; j<nc; j++)//coluna vira linha na tela
    {
         for(i=0; i<nl; i++) //linha vira coluna na tela
            printf("%3d ", m[i][j]); //mas na memoria nao muda
         printf("\n");
    }
}
