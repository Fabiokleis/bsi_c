#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 3

int main()
{
    /*
    int matriz[TAM][TAM];
    srand(time(NULL));
    preencheMatriz(matriz, 3, 3, 2);
    */

    int matriz[TAM][TAM] = {{8, 0, 7},{4, 5, 6},{3, 10, 2}};
     int i, j,
        somaLinha,
        somaColuna,
        somaDiagSec,
        valorReferencia = 0,
        ehQmag=1;

     // imprimeMatriz
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
            printf("%4d", matriz[i][j]);
        printf("\n");
    }

    //soma o conteúdo da diagonal principal
    //para criar um valor de referência
    for(i=0; i<TAM; i++)
        valorReferencia += matriz[i][i];

    /*Soma da diagonal secundaria*/
    somaDiagSec=0; //note que é preciso zerar a cada troca de linha
    for(i=0; i<TAM; i++)
        somaDiagSec += matriz[i][TAM-1-i];
    if(somaDiagSec!=valorReferencia)
        ehQmag = 0;
    else
    {
        /*Soma cada linha*/
        for(i=0; i<TAM; i++)
        {
            somaLinha=0; //note que é preciso zerar a cada troca de linha
            for(j=0; j<TAM; j++)
                somaLinha+=matriz[i][j];
            if(somaLinha!=valorReferencia)
            {
                    ehQmag = 0;
                    break;
            }
        }
        if(ehQmag!=0)
        {
            /*Soma cada coluna*/
            for(j=0; j<TAM; j++)
            {
                somaColuna=0; //note que é preciso zerar a cada troca de linha
                for(i=0; i<TAM; i++)
                    somaColuna+=matriz[i][j];
                if(somaColuna!=valorReferencia)
                {
                    ehQmag = 0;
                    break;
                }
            }
        }
    } //fim do else
    if(ehQmag)
        printf("A matriz eh quadrado magico!");
    else
        printf("A matriz NAO eh quadrado magico!");

    return 0;
}




