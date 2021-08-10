#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz(int tamL, int tamC);
void desalocaMatriz(int **m, int tamL);

void preencheColuna(int **m, int col,  int valor, int nl);
void preencheDiagonal(int **m, int valor, int n);
void imprimeMatrizDiagInf(int **m, int nl, int nc);
int ** criaPreencheTrianguloPascal(int n);

int main()
{
    int **mat; // como não sabemos alocar matrizes dinamicamente, temos que criar uma matriz estática de tamanho máximo
    int n;

    do{
        printf("Digite o valor de n (positivo): ");
        scanf("%d", &n);
    }while(n<=0);

    mat=criaPreencheTrianguloPascal(n);

    imprimeMatrizDiagInf(mat,n,n);

    desalocaMatriz(mat,n);

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


void preencheColuna(int **m, int col,  int valor, int nl)
{ //essa funcao serve para qq matriz de no máximo TAM colunas
    int i;
     for(i=0; i<nl; i++)
        m[i][col] = valor;
}

void preencheDiagonal(int **m, int valor, int n)
{ //essa funcao só serve para matriz quadrada
    int i;
     for(i=0; i<n; i++)
        m[i][i] = valor;
}

void imprimeMatrizDiagInf(int **m, int nl, int nc)
{ //essa funcao imprime qq matriz com no máximo TAM colunas
    int i, j;
    for(i=0; i<nl; i++)
    {
         for(j=0; j<=i; j++)
            printf("%3d ", m[i][j]);
         printf("\n");
    }
}


int ** criaPreencheTrianguloPascal(int n)
{
    int i,j, **m;

    m=alocaMatriz(n,n);

    // preenche a primeira coluna com 1
     preencheColuna(m, 0, 1, n);

     // preenche a diagonal com 1
     preencheDiagonal(m, 1, n);

    //calcula as demais posições não preenchidas  iniciando em 2,1
    for(i=2; i<n; i++)
        for(j=1; j<i; j++)
           m[i][j] = m[i-1][j-1] + m[i-1][j];

    return m;

}

