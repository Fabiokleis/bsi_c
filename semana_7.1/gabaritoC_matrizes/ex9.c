#include<stdio.h>
#include<stdlib.h>

#define NLIN 100
#define NCOL 100

void preencheMatrizLetras(int m[][NCOL], int nl, int nc, int num);
void imprimeMatriz(int m[][NCOL], int nl, int nc, char opcao);
void compara(int gabarito[], int respostas[][NCOL], int nl, int nc, int pontua[]);

int main()
{
    int gabarito[NCOL], respostas[NLIN][NCOL], nl, nc, pontua[NLIN];

    srand(time(NULL));

   // printf("Entre com a dimensão da matriz a ser considerada (100x100) ou menor: ");
   // scanf("%dx%d",&nl,&nc);

    preencheMatrizLetras(gabarito, 1, 10,  4);
    preencheMatrizLetras(respostas, 5, 10,  4);
    printf("gabarito\n");
    imprimeMatriz(gabarito,  1, 10,'l');
    printf("respostas\n");
    imprimeMatriz(respostas,  5, 10,'l');
    compara(gabarito,respostas,5,10,pontua);
    printf("pontuacao\n");
    imprimeMatriz(pontua,  1, 5,'n');//cuidado com impressão de matrizes de NCOL diferentes da cte definida no corpo da funcao!!! neste caso funciona poruqe só tem 1 linha...


    return 0;
}



void preencheMatrizLetras(int m[][NCOL], int nl, int nc, int num)
{
    int i, j;

    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
        {
            m[i][j] = 97+(rand()%num);//codigo ascii da letra 'a' eh 97
        }
}

//cuidado com o exercício da impressão da transposta (se a matriz não for quadrada essa funcao nao vale para a transposta!!!
void imprimeMatriz(int m[][NCOL], int nl, int nc, char opcao)
{
    int i, j;

    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
            if(opcao=='n')
               printf("%4d", m[i][j]);
            else if(opcao=='l')
              printf("%4c", m[i][j]);

        printf("\n");
    }

}


void compara(int gabarito[], int respostas[][NCOL], int nl, int nc, int pontua[])
{
    int aluno, questao;

    for(aluno=0; aluno<nl; aluno++)
    {
        pontua[aluno]=0;
        for(questao=0; questao<nc; questao++)
            if(gabarito[questao]==respostas[aluno][questao])
              pontua[aluno]=pontua[aluno]+1;

    }

}
