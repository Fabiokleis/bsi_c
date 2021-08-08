#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 3

void preencheMatriz(int m[][TAM], int nl, int nc, int lim);
int somaDiag(int m[][TAM], int tam,  int dir);
int somaLinha(int m[][TAM], int nc, int lin);
int somaColuna(int m[][TAM], int nl, int col);
int ehQuadradoMagico(int m[][TAM], int tam);

int main(){
    /*
    int matriz[TAM][TAM];
    srand(time(NULL));
    preencheMatriz(matriz, TAM, TAM, 2);
    */

    int matriz[TAM][TAM] = {{8, 0, 7},{4, 5, 6},{3, 10, 2}};//essa eh quadrado mágico

    imprimeMatriz(matriz, TAM, TAM);

    if(ehQuadradoMagico(matriz, TAM)) printf("A matriz eh quadrado magico!");
    else printf("A matriz NAO eh quadrado magico!");
    return 0;
}
void preencheMatriz(int m[][TAM], int nl, int nc, int lim){
    int i, j;

    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            m[i][j] = rand()%lim+1;
    }
}
void imprimeMatriz(int m[][TAM], int nl, int nc){
    int i, j;

    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

int ehQuadradoMagico(int m[][TAM], int tam){
    int i, j,
        valorReferencia;

    //soma o conteúdo da diagonal principal
    //para criar um valor de referência
    valorReferencia=somaDiag(m,TAM,1);

    /*Compara Soma da diagonal secundaria*/
    if(somaDiag(m,TAM,-1)!=valorReferencia)
        return 0;

    /*Soma cada linha*/
    for(i=0; i<tam; i++){
        if(somaLinha(m,tam,i)!=valorReferencia)
            return 0;
    }

    /*Soma cada coluna*/
    for(j=0; j<tam; j++){
        if(somaColuna(m,tam,j)!=valorReferencia)
            return 0;
    }
    // se chegou aqui, é porque todas as somas são iguais
    return 1;
}
int somaDiag(int m[][TAM], int tam,  int dir){
    int i,j,soma=0,inic;

    if (dir==1)//soma diagonal princial
       inic=0;
    else
      if(dir==-1) //soma diagonal secundária
        inic=tam-1;

    for(i=0,j=inic; i<tam; i++,j=j+dir)
        soma=soma + m[i][j];
    return soma;
}

int somaLinha(int m[][TAM], int nc, int lin){
    int j,soma=0;
    for(j=0; j<nc; j++)
        soma=soma + m[lin][j];
    return soma;
}
int somaColuna(int m[][TAM], int nl, int col){
    int i,soma=0;
    for(i=0; i<nl; i++)
        soma=soma + m[i][col];
    return soma;
}
