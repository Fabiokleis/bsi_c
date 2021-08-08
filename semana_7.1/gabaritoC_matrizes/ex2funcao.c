#include <stdio.h>
#define TAM 100

void preencheColuna(int m[][TAM], int col,  int valor, int nl);
void preencheDiagonal(int m[][TAM], int valor, int n);
void imprimeMatrizDiagInf(int m[][TAM], int nl, int nc);
void preencheTrianguloPascal(int m[][TAM], int n);

int main()
{
    int mat[TAM][TAM]; // como não sabemos alocar matrizes dinamicamente, temos que criar uma matriz estática de tamanho máximo
    int n;

    do{
        printf("Digite o valor de n: (maximo 100) ");
        scanf("%d", &n);
    }while(n<=0 || n>100);

    preencheTrianguloPascal(mat, n);

    imprimeMatrizDiagInf(mat,n,n);

    return 0;
}


void preencheColuna(int m[][TAM], int col,  int valor, int nl)
{ //essa funcao serve para qq matriz de no máximo TAM colunas
    int i;
     for(i=0; i<nl; i++)
        m[i][col] = valor;
}

void preencheDiagonal(int m[][TAM], int valor, int n)
{ //essa funcao só serve para matriz quadrada
    int i;
     for(i=0; i<n; i++)
        m[i][i] = valor;
}

void imprimeMatrizDiagInf(int m[][TAM], int nl, int nc)
{ //essa funcao imprime qq matriz com no máximo TAM colunas
    int i, j;
    for(i=0; i<nl; i++)
    {
         for(j=0; j<=i; j++)
            printf("%3d ", m[i][j]);
         printf("\n");
    }
}

void preencheTrianguloPascal(int m[][TAM], int n)
{
    int i,j;

    // preenche a primeira coluna com 1
     preencheColuna(m, 0, 1, n);

     // preenche a diagonal com 1
     preencheDiagonal(m, 1, n);

    //calcula as demais posições não preenchidas  iniciando em 2,1
    for(i=2; i<n; i++)
        for(j=1; j<i; j++)
           m[i][j] = m[i-1][j-1] + m[i-1][j];

}

