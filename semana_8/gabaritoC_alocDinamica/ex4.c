#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz(int lin, int col);
void imprimeMatrizCusto(int **matriz, int lin, int col);
void preparaMatrizCusto (int **m, int n);
int custo_cidades (int* cidades, int n_cidades, int** m);

//a funcao main,  deve
//solicitar ao usuario a dimensao da matriz de custo,
//alocar memoria para esta matriz utilizando uma funcao denominada alocaMatriz,
//preencher a matriz com dados digitados pelo usuario,
//solicitar ao usuario o tamanho do itinerario,
//alocar memoria para o vetor que ira armazenar o itinerario usando uma funcao denominada alocaVetor,
//preencher o vetor de itineraarios
//chamar a funcao custo cidades e imprimir na tela o custo.

int main()
{
    int i,n,n_cidades,custo;
    int **m, *cidades;

    printf("Digite a dimensao da matriz de custo: ");
    scanf("%d", &n);
    m = alocaMatriz(n,n);
    preparaMatrizCusto (m, n);//matriz gerada aleatoriamente para facilitar
    imprimeMatrizCusto(m, n,n);

    printf("Digite o tamanho do itinerario: ");
    scanf("%d", &n_cidades);
    cidades =(int *) malloc(n_cidades * sizeof(int));
    for (i = 0; i < n_cidades; i++)
        cidades[i] =  rand () % (n);//itinerario gerado aleatoriamente para facilitar

    custo = custo_cidades (cidades, n_cidades, m);
    printf("Ha um custo de %d para se percorrer o itinerario ", custo);
    for (i = 0; i < n_cidades; i++)
        if (i==0)
         printf("%4d", cidades[i]);
        else
         printf("  ->%4d", cidades[i]);
    return 0;

}

int ** alocaMatriz(int lin, int col)
{   int l;
    int **matriz;
    matriz = (int **) malloc(lin * sizeof(int *)); //primeiro aloca um vetor de ponteiros (cada elemento deste vetor apontará para um bloco de inteiros (linha da matriz))
    for(l=0;l<lin;l++)
        matriz[l]= (int *) malloc(col * sizeof(int));
    return matriz;
}
//essa funcao esta modificaca para imprimir os indices das cidades alem do custo
void imprimeMatrizCusto(int **matriz, int lin, int col)
{   int l,c;

     printf("    ");
    for(c=0;c<col;c++)
        printf("%4d", c);//imprimindo indices das cidades (facilitar a verificacao do itinerario)
    printf("\n\n");
    for(l=0;l<lin;l++,printf("\n\n")){
          printf("%4d", l);
         for(c=0;c<col;c++)
            printf("%4d", matriz[l][c]);
    }

}



void preparaMatrizCusto (int **m, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            if(i==j)
                m[i][j] = 0;
            else
                m[i][j] = rand () % (24);//maximo de 23 horas de deslocamento
}
int custo_cidades (int* cidades, int n_cidades, int** m)
{
   int i,lin,col,custo=0;


   lin=cidades[0];
   printf("custo:");
    for (i = 1; i < n_cidades; i++)
    {
        col = cidades[i];
        custo += m[lin][col];  printf("%d + ",m[lin][col]);
        lin=col;
    }
    printf("\n");
   return custo;
}
