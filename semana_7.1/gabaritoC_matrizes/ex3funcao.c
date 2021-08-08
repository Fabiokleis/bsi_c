#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define NLIN 10
#define NCOL 10

void preencheMatriz(int m[][NCOL], int nl, int nc, int lim);
void imprimeMatriz(int m[][NCOL], int nl, int nc);
void encontraMinimax (int matriz[][NCOL], int nl, int nc, int *minimax, int *l, int *c);
int menorElemVetor(int v[], int n, int *menor);
void maiorElemMatriz(int m[][NCOL], int nl, int nc, int *maior, int *lmaior, int *cmaior);


int main()
{
    int matriz[NLIN][NCOL], minMax, lin, col;

    preencheMatriz(matriz, NLIN, NCOL, 10);
    imprimeMatriz(matriz, NLIN, NCOL);
    encontraMinimax(matriz, NLIN, NCOL, &minMax, &lin, &col);

    printf("\nminmax: %d \nCoordenada: %d-%d \n", minMax, lin, col);

    return 0;
}

void preencheMatriz(int m[][NCOL], int nl, int nc, int lim)
{
    int i, j;

    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            m[i][j] = rand()%lim+1;
}

void imprimeMatriz(int m[][NCOL], int nl, int nc)
{
    int i, j;

    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}
void maiorElemMatriz(int m[][NCOL], int nl, int nc, int *maior, int *lmaior, int *cmaior)
{
    int i, j;
    *maior=m[0][0];
    *lmaior=*cmaior=0;

    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            if (m[i][j] > *maior)
            {

                *maior = m[i][j];
                *lmaior = i;
                *cmaior = j;
            }
        }
    }
}
int menorElemVetor(int v[], int n, int *menor){
   int i, pos=0;
   *menor=v[0];

   for(i=1;i<n;i++)
   {
     if(v[i]<*menor)
     {
          *menor = v[i];
          pos=i;
     }
   }
   return pos;
}
void encontraMinimax (int matriz[][NCOL], int nl, int nc, int *minimax, int *l, int *c){
    int maior;
    *l=*c=0;

     maiorElemMatriz(matriz,nl,nc,&maior,l,c);//maior eh variavel simples então manda endereço
    //os ponteiros l e c estão sendo repassar por referencia para a função alterar os valores

    *c=menorElemVetor(matriz[*l],NCOL,minimax); //mando o valor da linha onde ocorre o maior
    //e repasso o ponteiro minmax por referencia para a funcao alterar o valor
}

