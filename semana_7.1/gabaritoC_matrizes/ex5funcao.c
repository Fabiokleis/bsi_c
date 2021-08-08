#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAML 3
#define TAMC 3

int ehPermutacao(int m[][TAMC],int nl, int nc);
int somaModuloLinha(int m[][TAMC], int nc, int lin);
int somaModuloCol(int m[][TAMC], int nl, int col);
float modulo(float x);
void imprimeMatriz(int m[][TAMC], int nl, int nc);
void inicializaMatriz(int m[][TAMC], int nl, int nc);
void criaIdentidade(int m[][TAMC], int nl, int nc);
void preencheMatriz(int m[][TAMC], int nl, int nc, int vInic, int vFim);

int main(){
    int matriz[TAML][TAMC];
    //inicialização da semente do gerador de nros a
    srand(time(NULL));

    inicializaMatriz(matriz,TAML,TAMC);//com diferentes opcoes de inicializacao
    imprimeMatriz(matriz,TAML,TAMC);

    if(ehPermutacao(matriz,TAML,TAMC)) printf("A matriz eh de permutacao");
    else printf("A matriz NAO eh de permutacao");
    return 0;
}
void inicializaMatriz(int m[][TAMC], int nl, int nc){
    int opcao;
    printf("Qual opcao de inicializacao voce deseja? \n(1)Identidade \n(2)aleatoria binaria  \n(3)aleatoria com valor negativo \nopcao: ");
    scanf("%d",&opcao);
    if(opcao==1)
        criaIdentidade(m, nl, nc);
    else if(opcao==2)
        preencheMatriz(m, nl, nc, 0, 1);
    else if (opcao==3)
        //preenche a matriz com valores aleatórios -1 ou 1 (para testar o efeito dos negativos
         preencheMatriz(m, nl, nc, -1, 1);
}
void imprimeMatriz(int m[][TAMC], int nl, int nc){
    int i, j;
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}
int ehPermutacao(int m[][TAMC],int nl, int nc){
   int i;
   for(i=0; i<nl; i++){
        if(somaModuloLinha(m,nc,i)!=1)
           return 0;  //não precisa continuar testando...
   }
  for(i=0; i<nc; i++){
        if(somaModuloLinha(m,nl,i)!=1)
           return 0;  //não precisa continuar testando...
   }
    return 1;
}
void preencheMatriz(int m[][TAMC], int nl, int nc, int vInic, int vFim){
    int i, j;
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            m[i][j] = vInic + rand()%(vFim-vInic+1); //gera um numero aleatorio no range  vInic a vFim
    }
}

void criaIdentidade(int m[][TAMC], int nl, int nc){
    int i;
    if(nl!=nc){
        printf("Erro! Matriz nao eh quadrada!!!!");
        return;
    }
     preencheMatriz(m, TAML,TAMC, 0, 0);
     for(i=0;i<nl;i++)
        m[i][i]=1;
}
int somaModuloLinha(int m[][TAMC], int nc, int lin){
    int j,soma=0;
    for(j=0; j<nc; j++)
            soma=soma + (int)modulo(m[lin][j]);
    return soma;
}
int somaModuloCol(int m[][TAMC], int nl, int col){
    int i,soma=0;
    for(i=0; i<nl; i++)
            soma=soma + (int)modulo(m[i][col]);
    return soma;
}
float modulo(float x){
    if(x<0)
        return(-1*x);
    else
        return (x);
}
