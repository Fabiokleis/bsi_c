#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAML 3
#define TAMC 3

float modulo(float x)
{
    if(x<0)
        return(-1*x);
    else
        return (x);
}

int main(){
    int m[TAML][TAMC],
        i, j,
        soma,
        controle = 0;

    //inicialização da semente do gerador de nros a
    srand(time(NULL));

    //preenche a matriz com nros aleatórios
    //for(i=0; i<TAML; i++)
      //  for(j=0; j<TAMC; j++)
     //       m[i][j] = rand()%2;

    //para teste, cria matriz identidade
     for(i=0; i<TAML; i++)
        for(j=0; j<TAMC; j++)
        if (i==j) m[i][j]=1;
        else m[i][j]=0;

  //  for(i=0; i<TAML; i++)
   //     m[i][i]=1;

    //m[0][1] = -1; //para verificar o efeito dos valores negativos
    //m[0][2] = 1;  //para verificar o efeito dos valores negativos


    /*Soma cada linha*/
    for(i=0; i<TAML; i++){
        soma=0; //note que é preciso zerar a cada troca de linha
        for(j=0; j<TAMC; j++)
            //somaLinha+= m[i][j]; para verificar o efeito dos valores negativos descomente essa linha e comente a próxima
            soma+= (int) modulo(m[i][j]);  //soma o modulo para eliminar o efeito dos valores negativos
        if(soma!=1)
        {
            controle=1;
            break;  //não precisa continuar testando...
        }
    }

     /*Soma cada coluna*/
    for(i=0; i<TAMC; i++){
        soma=0; //note que é preciso zerar a cada troca de  coluna
        for(j=0; j<TAML; j++)
            //somaLinha+= m[i][j]; para verificar o efeito dos valores negativos descomente essa linha e comente a próxima
            soma+= (int) modulo(m[j][i]);  //soma o modulo para eliminar o efeito dos valores negativos
        if(soma!=1)
        {
            controle=1;
            break;  //não precisa continuar testando...
        }
    }

    //imprime a matriz
    for(i=0; i<TAML; i++)
    {
        for(j=0; j<TAMC; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
    // testa var controle
    if(controle==0)
        printf("A matriz eh de permutacao");
    else
        printf("A matriz NAO eh de permutacao");

    return 0;
}
