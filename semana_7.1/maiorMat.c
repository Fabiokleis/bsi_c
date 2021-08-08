#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int maiorMat(int n, int m, int vet[][N]);

int main(){
    int vet[N][N], i, j, ret, n, m;
    srand(time(NULL));
    n = rand() % N+1;
    m = rand() % N+1;
 
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            vet[i][j] = rand() % 100;
            printf("%2d ",vet[i][j]);
        }
        printf("\n");
    }

    ret = maiorMat(n, m, vet);
    printf("\no maior valor é %d\n", ret);
    return 0;
}

int maiorMat(int n, int m, int vet[][N]){
    int i, j, max=0;

    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            if(vet[i][j] > max){
                max = vet[i][j];
            }
        }
    }

    return max;
}


