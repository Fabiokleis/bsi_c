#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ** alocaMatriz(int tamL, int tamC);
void desalocaMatriz(int **m, int tamL);

int ** preencheBingo(int nl, int nc);
int estaNaMatriz(int **m, int lAtual, int cAtual, int aux);
void imprimeMatriz(int **m, int nl, int nc);

int main()
{
    int **matriz, tam;

    srand(time(NULL));

    printf("Entre com o tamanho da cartela do bingo: ");
    scanf("%d",&tam);

    matriz=preencheBingo(tam, tam);
    imprimeMatriz(matriz, tam, tam);

    desalocaMatriz(matriz,tam);

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



int ** preencheBingo(int nl, int nc)
{
    int i, j, **m, aux;

    m = alocaMatriz(nl,nc);

    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            aux = rand()%100;
            while(estaNaMatriz(m, nl, nc, aux))
                aux = rand()%100;
            m[i][j] = aux;
            //imprimeMatriz(m,nl,nc); //se quiser ver cada passo da inclusão

        }
    }
    return m;
}

int estaNaMatriz(int **m, int lAtual, int cAtual, int aux)
{
    int i, j;

    for(i=0; i<lAtual; i++)
    {
        for(j=0; j<cAtual; j++)
        {
            if(m[i][j]==aux)
                return 1;
        }
    }
    return 0;
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
    printf("\n");

}
