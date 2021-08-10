#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ** alocaMatriz(int tamL, int tamC);
void desalocaMatriz(int **m, int tamL);

void preencheMatriz(int **m, int nl, int nc, int lim);
void imprimeMatriz(int **m, int nl, int nc);
void encontraMinimax (int **m, int nl, int nc, int *minimax, int *l, int *c);
int menorElemVetor(int *v, int n, int *menor);
void maiorElemMatriz(int **m, int nl, int nc, int *maior, int *lmaior, int *cmaior);


int main()
{
    int **matriz, tamL, tamC, minMax, lin, col;

    printf("Entre com as dimensoes da matriz (total linhas e total colunas): ");
    scanf("%d %d",&tamL,&tamC);

    matriz=alocaMatriz(tamL,tamC);
    preencheMatriz(matriz, tamL,tamC, 10);
    imprimeMatriz(matriz, tamL,tamC);
    encontraMinimax(matriz, tamL,tamC, &minMax, &lin, &col);

    printf("\nminmax: %d \nCoordenada: %d-%d \n", minMax, lin, col);

    desalocaMatriz(matriz, tamL);
    return 0;
}

int ** alocaMatriz(int tamL, int tamC)
{
    int i, **m;

    m = (int **)  malloc(tamL*sizeof(int *)); //aloca um vetor de endereços
    if(m==NULL)
    {
        printf("Erro na alocacao da matriz!!!");
        exit(1);
    }
    for(i=0;i<tamL;i++)
        m[i]= (int *)  malloc(tamC*sizeof(int )); //aloca um bloco de tamC inteiros e faz m[i] apontar para ele

    return m;
}
void desalocaMatriz(int **m, int tamL)
{
    int i;
    for(i=0;i<tamL;i++)
       free(m[i]);
    free(m);
}



void preencheMatriz(int **m, int nl, int nc, int lim)
{
    int i, j;

    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            m[i][j] = rand()%lim+1;
}

void imprimeMatriz(int **m, int nl, int nc)
{
    int i, j;

    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

void maiorElemMatriz(int **m, int nl, int nc, int *maior, int *lmaior, int *cmaior)
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

int menorElemVetor(int *v, int n, int *menor)
{

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

void encontraMinimax (int **m, int nl, int nc, int *minimax, int *l, int *c)
{
    int maior;
    *l=*c=0;

     maiorElemMatriz(m,nl,nc,&maior,l,c);//maior eh variavel simples então manda endereço
    //os ponteiros l e c estão sendo repassar por referencia para a função alterar os valores


    *c=menorElemVetor(m[*l],nc,minimax); //mando o valor da linha onde ocorre o maior
    //e repasso o ponteiro minmax por referencia para a funcao alterar o valor
}

