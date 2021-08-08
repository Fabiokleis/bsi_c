#include <stdio.h>
#define TAM 100

int main(){
    int m[TAM][TAM]; // como não sabemos alocar matrizes dinamicamente, temos que criar uma matriz estática de tamanho máximo
    int n,i,j;

    do{
        printf("Digite o valor de n: (maximo 100) ");
        scanf("%d", &n);
    }while(n<=0 || n>100);



    // preenche a primeira coluna com 1
    for(i=0; i<n; i++)
        m[i][0] = 1;

     // preenche a diagonal com 1
    for(i=0; i<n; i++)
        m[i][i] = 1;

    //calcula as demais posições não preenchidas  iniciando em 2,1
    for(i=2; i<n; i++)
        for(j=1; j<i; j++)
           m[i][j] = m[i-1][j-1] + m[i-1][j];

    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }

    return 0;
}

