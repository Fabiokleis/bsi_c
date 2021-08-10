#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//nessa versao a matriz alocada eh retornada por ref
void alocaMatriz(int ***m, int tamL, int tamC);
void desalocaMatriz(int **m, int tamL);
void preencheMatriz(int **m, int nl, int nc, int num);
void imprimeMatriz(int **m, int nl, int nc);
void imprimeTranspostaMatriz(int **m, int nl, int nc);

void alocaMatriz(int ***m,int tamL, int tamC)
{
    int i;

    *m = (int **)  malloc(tamL*sizeof(int *)); //aloca um vetor de endereços e armazena na matriz original
    if(*m==NULL)
    {
        printf("Erro na alocacao da matriz!!!");
        exit(1);
    }
    for(i=0;i<tamL;i++)
        (*m)[i]= (int *)  malloc(tamC*sizeof(int )); //aloca um bloco de tamC inteiros e faz m[i] apontar para ele

}
void desalocaMatriz(int **m, int tamL)
{
    int i;
    for(i=0;i<tamL;i++)
       free(m[i]);
    free(m);
}


int main()
{
    int **matriz, tamL, tamC, lim;


    //inicialização da semente do gerador de nros aleatorios
    srand(time(NULL));

    printf("Entre com as dimensoes linhas x colunas da matriz e o limite para cada elemento: ");
    scanf("%d %d %d",&tamL, &tamC, &lim);

    alocaMatriz(&matriz,tamL,tamC);
    preencheMatriz(matriz, tamL, tamC, lim);

    printf("\n\nMatriz original: \n");
    imprimeMatriz(matriz, tamL, tamC);

    printf("\n\nTransposta: \n");
    imprimeTranspostaMatriz(matriz, tamL, tamC);

    desalocaMatriz(matriz,tamL);

    return 0;
}


void preencheMatriz(int **m, int nl, int nc, int num)
{
    int i, j;

    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            m[i][j] = rand()%num+1;
}

void imprimeMatriz(int **m, int nl, int nc)
{
    int i, j;

    for(i=0; i<nl; i++)
    {
         for(j=0; j<nc; j++)
            printf("%3d ", m[i][j]);
         printf("\n");
    }
}

void imprimeTranspostaMatriz(int **m, int nl, int nc)
{
    int i, j;

    for(j=0; j<nc; j++)//coluna vira linha na tela
    {
         for(i=0; i<nl; i++) //linha vira coluna na tela
            printf("%3d ", m[i][j]); //mas na memoria nao muda
         printf("\n");
    }
}
