#include<stdio.h>
#include<stdlib.h>

#define NLIN 10
#define NCOL 10


int main()
{
    int i,j,matriz[NLIN][NCOL], minMax, lin, col;

    //preenche a matriz com valores aleatorios (1 a 9)
    for(i=0; i<NLIN; i++)
        for(j=0; j<NCOL; j++)
            matriz[i][j] = rand()%10+1;

    // imprimeMatriz
    for(i=0; i<NLIN; i++)
    {
        for(j=0; j<NCOL; j++)
            printf("%4d", matriz[i][j]);
        printf("\n");
    }

    //acha o maior elemento da matriz e sua linha
    //(minMax vai armazenar temporariamente esse valor)
    minMax=matriz[0][0];
    for (i = 0; i < NLIN; i++)
    {
        for (j = 0; j < NCOL; j++)
        {
            if (matriz[i][j] > minMax)
            {
                lin = i;
                minMax = matriz[i][j];
            }
        }
    }
    //acha o menor elemento da linha lin da matriz
    for (i = 0; i < NCOL; i++)
    {
        if (matriz[lin][i] <= minMax)
        {
            col = i;
            minMax = matriz[lin][i];
        }
    }
    printf("\nminmax: %d \nCoordenada: %d-%d \n", minMax, lin, col);

    return 0;
}
