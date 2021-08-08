#include <stdio.h>
#define N 3

int main(){
    int mQ[N][N];
    int soma=0, u=0, flag=0;
    int ctr;
    int i, j;

    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            printf("mQ[%d][%d]: ", i, j);
            scanf("%d", &ctr);
            mQ[i][j] = ctr;
        }
    }

    for(i=0; i < N; i++){
        u = soma;
        soma = 0;
        for(j=0; j < N; j++){
            soma += mQ[i][j];
        }
        if(soma == u){
            flag = 1;
        }
    }
    if(flag){
        printf("é um quadrado mágico\n");
    }else{
        printf("não é um quadrado mágico\n");
    }
    return 0;
}
