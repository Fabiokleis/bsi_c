#include<stdio.h>
#include<stdlib.h>

#define NLIN 10
#define NCOL 10

int preencheMatriz(int m[][NCOL], int nl, int nc, int lim);
void imprimeMatriz(int m[][NCOL], int nl, int nc, char qualMatriz);
void operaMatrizes(int m1[][NCOL], int m2[][NCOL], char operacao, int mResult[][NCOL], int nl, int nc);

int main()
{
    int matriz1[NLIN][NCOL],matriz2[NLIN][NCOL], mResult[NLIN][NCOL], opcao, inicMat1=0, inicMat2=0;
     srand(time(NULL));

    do{
        printf("Entre com a opcao desejada:\n(0)Criar aleatoriamente as duas matriz\n(1)Imprimir as matrizes originais\n(2)Somar as matrizes\n(3)Subtrair a primeira da segunda\n(4)multiplicar uma constante aa primeira matriz\n(-1)Sair do Programa\n");
        scanf("%d",&opcao);
        if(opcao==0){
                inicMat1=preencheMatriz(matriz1, NLIN, NCOL,  9);
                inicMat2=preencheMatriz(matriz2, NLIN, NCOL,  9);
        }
        else if (opcao==1 || opcao ==2 || opcao ==3 || opcao ==4){
                    if(inicMat1 && inicMat2)
                    {
                        if(opcao==1)
                        {
                           imprimeMatriz(matriz1, NLIN, NCOL, '1');
                           imprimeMatriz(matriz2, NLIN, NCOL, '2');
                        }
                        else if(opcao==2)
                        {
                            operaMatrizes(matriz1, matriz2, '+', mResult, NLIN, NCOL);
                            imprimeMatriz(mResult, NLIN, NCOL, '+');
                        }
                        else if(opcao==3)
                        {
                            operaMatrizes(matriz1, matriz2, '-', mResult, NLIN, NCOL);
                            imprimeMatriz(mResult, NLIN, NCOL, '-');
                        }
                        else if(opcao==4)
                        { //essa solucao usa somente funcao operaMatrizes que faz k*m1 + m2
                              preencheMatriz(mResult, NLIN, NCOL,  1);//gera uma matriz preenchida com valores 1
                              operaMatrizes(mResult, mResult, '-', mResult, NLIN, NCOL);//essas duas operacoes são so para gerar uma matriz nula (sem precisar criar uma nova funcao)
                              operaMatrizes(matriz1, mResult, 'k', mResult, NLIN, NCOL);//a matriz nula  nao altera o resultado de m1*k
                              imprimeMatriz(mResult, NLIN, NCOL, 'k');
                        }
                    }
                    else
                    {
                        printf("Erro!!! Matrizes nao inicializadas\n");
                        printf("Escolha opcao (0) primeiro!!!\n");
                    }
            }
            else if (opcao == -1) printf("Fim do programa\n");
            else printf("opcao invalida\n");
    }while(opcao!=-1);
    return 0;
}
int preencheMatriz(int m[][NCOL], int nl, int nc, int lim){
    int i, j, inic=0;

    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            m[i][j] = rand()%lim+1;
    }
    inic = 1;
    return (inic);
}
void imprimeMatriz(int m[][NCOL], int nl, int nc, char qualMatriz){
    int i, j;

     if(qualMatriz=='1' || qualMatriz=='2') printf("Matriz%c\n",qualMatriz);
     else if (qualMatriz=='+') printf("Matriz1 + Matriz2\n");
     else if (qualMatriz=='-')  printf("Matriz1 - Matriz2\n");
     else if (qualMatriz=='k') printf("k * Matriz1\n");
     else printf("indentificador da matriz invalido\n");
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}
void operaMatrizes(int m1[][NCOL], int m2[][NCOL], char operacao, int mResult[][NCOL], int nl, int nc){
    int i, j, k;
    if(operacao=='+') k=1;
    else if(operacao=='-') k=-1;
    else if(operacao=='k') {printf("Entre com o valor de k: "); scanf("%d",&k);}
    else printf("operacao invalida\n");
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            mResult[i][j] = k*m1[i][j] +  m2[i][j] ;
    }
}
