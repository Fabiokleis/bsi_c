#include<stdio.h>
#include<stdlib.h>
//ex vale para NLIN != NCOL para a multiplicacao de matrizes mas para A^2 a matriz tera que ser quadrada
#define NLIN 100
#define NCOL 100

void preencheMatriz(int m[][NCOL], int nl, int nc, int num);
void imprimeMatriz(int m[][NCOL], int nl, int nc);
void atribuiMatriz(int r[][NCOL], int m[][NCOL], int nl, int nc);
int multiplicaMatrizes(int a[][NCOL],  int nla, int nca,  int b[][NCOL], int nlb, int ncb, int c[][NCOL]);

int main(){
    int A[NLIN][NCOL],B[NLIN][NCOL],C[NLIN][NCOL],mAux[NLIN][NCOL], m, n, p;
    srand(time(NULL));
    printf("Entre com a dimensão m (0<m<=100) das matrizes quadradas a serem consideradas: ");
    scanf("%d",&m);
    preencheMatriz(A, m, m,  3);
    printf("A(%dx%d)\n",m,m); imprimeMatriz(A,  m, m);
    preencheMatriz(B, m, m,  3);
    printf("B(%dx%d)\n",m,m); imprimeMatriz(B,  m, m);
    multiplicaMatrizes(A,m,m,B,m,m,C);
    printf("C(%dx%d)=A*B\n",m,m); imprimeMatriz(C,  m, m);
    multiplicaMatrizes(A,m,m,A,m,m,C);
    printf("C(%dx%d)=A*A\n",m,m); imprimeMatriz(C,  m, m);
    printf("Entre com a potencia n  para o calculo de A^n: ");
    scanf("%d",&n);
    atribuiMatriz(mAux,A,m,m);//mAux=A^1
    for(p=2;p<=n;p++){//ideia eh fazer C = A*A*A*...A(ne vezes) de forma iterativa C=A; C= A*A; C=A*A*A (C=C*A)
        multiplicaMatrizes(mAux,m,m,A,m,m,C);//tem que salvar numa matriz auxiliar porque a funcao mjultiplica modifica a matriz C no calcul entao nao funciona chamar multiplicaMatrizes(C,m,m,A,m,m,C)
        atribuiMatriz(mAux,C,m,m);//atualiza  a matriz mAux com o valor atual da potencia C=A^p
    }
    printf("C(%dx%d)=A^%d\n",m,m,p);
    imprimeMatriz(C,  m, m);
    return 0;
}
int multiplicaMatrizes(int a[][NCOL],  int nla, int nca,  int b[][NCOL], int nlb, int ncb, int c[][NCOL])//assumindo as matrizes quadradas{
    int i, j, k;
    if(nca!=nlb){
       printf("As dimensoes das matrizes nao permitem a operacao de multiplicacao");
       return (-1);
    }
       //Ex c[5x3] = a[5x4]  x  b[4x3]
      //a[0][0]  a[0][1]  a[0][2] a[0][3]      b[0][0] b[0][1] b[0][2]
      //a[1][0]  a[1][1]  a[1][2] a[1][3]      b[1][0] b[1][1] b[1][2]
     // a[2][0]  a[2][1]  a[2][2] a[2][3]      b[2][0] b[2][1] b[2][2]
     // a[3][0]  a[3][1]  a[3][2] a[3][3]      b[3][0] b[3][1] b[3][2]
     // a[4][0]  a[4][1]  a[4][2] a[4][3]
//c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0] + a[0][3]*b[3][0] ||| c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1] + a[0][3]*b[3][1] ||| c[0][2] = a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2] + a[0][3]*b[3][2]
//c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0] + a[1][3]*b[3][0] ||| c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1] + a[1][3]*b[3][1] ||| c[1][2] = a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2] + a[1][3]*b[3][2]
//c[2][0] = a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0] + a[2][3]*b[3][0] ||| c[2][1] = a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1] + a[2][3]*b[3][1] ||| c[2][2] = a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2] + a[2][3]*b[3][2]
//c[3][0] = a[3][0]*b[0][0] + a[3][1]*b[1][0] + a[3][2]*b[2][0] + a[3][3]*b[3][0] ||| c[3][1] = a[3][0]*b[0][1] + a[3][1]*b[1][1] + a[3][2]*b[2][1] + a[3][3]*b[3][1] ||| c[3][2] = a[3][0]*b[0][2] + a[3][1]*b[1][2] + a[3][2]*b[2][2] + a[3][3]*b[3][2]
//c[4][0] = a[4][0]*b[0][0] + a[4][1]*b[1][0] + a[4][2]*b[2][0] + a[4][3]*b[3][0] ||| c[4][1] = a[4][0]*b[0][1] + a[4][1]*b[1][1] + a[4][2]*b[2][1] + a[4][3]*b[3][1] ||| c[4][2] = a[4][0]*b[0][2] + a[4][1]*b[1][2] + a[4][2]*b[2][2] + a[4][3]*b[3][2]

//Ex c[5x3] = a[5x4]  x  b[4x3]
    for(i=0; i<nla; i++){
        for(j=0; j<ncb; j++){
            c[i][j] = 0;
            for(k=0;k<nlb;k++){//nca == nlb
               c[i][j] = c[i][j]  + (a[i][k]*b[k][j]);//observe que a matriz c esta sendo alterada (entao ao chamar a funcao mutiplicaMatrizes(C,m,m,A,m.m,C) nao ira funcionar (por isso main usa mAux)
            }
        }
    }
}
void preencheMatriz(int m[][NCOL], int nl, int nc, int num){
    int i, j;
    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            m[i][j] = rand()%num+1;
}
//cuidado com o exercício da impressão da transposta (se a matriz não for quadrada essa funcao nao vale para a transposta!!!
void imprimeMatriz(int m[][NCOL], int nl, int nc){
    int i, j;
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}
void atribuiMatriz(int r[][NCOL], int m[][NCOL], int nl, int nc){
    int i, j;
    for(i=0; i<nl; i++)
        for(j=0; j<nc; j++)
            r[i][j] =  m[i][j];
}
