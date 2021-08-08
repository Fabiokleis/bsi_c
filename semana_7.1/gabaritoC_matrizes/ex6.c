#include<stdlib.h>

#define N 5 //matriz precisa ser quadrada neste exercício!


void preencheBingo(int m[][N], int nl, int nc);
int estaNaMatriz(int m[][N], int lAtual, int cAtual, int aux);
void imprimeMatriz(int m[][N], int nl, int nc);

int main()
{
    int matriz[N][N]={0}; //o correto é inicializar com -1, para que o zero possa ser sorteado!

    srand(time(NULL));

    preencheBingo(matriz, N, N);
    imprimeMatriz(matriz, N, N);

    return 0;
}



void preencheBingo(int m[][N], int nl, int nc)
{
    int i, j,
        aux;

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
}

int estaNaMatriz(int m[][N], int lAtual, int cAtual, int aux)
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



void imprimeMatriz(int m[][N], int nl, int nc)
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
