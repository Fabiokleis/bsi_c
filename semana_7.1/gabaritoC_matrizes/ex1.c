#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAML 5
#define TAMC 5
#define LIM 10



int main()
{
    int m[TAML][TAMC];
    int i, j;

    //inicialização da semente do gerador de nros aleatorios
    srand(time(NULL));

  // preenche Matriz com valores aleatorios (0 a LIM-1)
  for(i=0; i<TAML; i++)
        for(j=0; j<TAMC; j++)
            m[i][j] = rand()%LIM+1;

    printf("\n\nMatriz original: \n");
    for(i=0; i<TAML; i++)
    {
        for(j=0; j<TAMC; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }

    printf("\n\nTransposta: \n");
    for(j=0; j<TAMC; j++)
    {
        for(i=0; i<TAML; i++)
            printf("%4d", m[i][j]);
        printf("\n");
    }

    return 0;
}
