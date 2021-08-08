#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(){
    int mm[N][N], mmt[N][N];
    int i, j;
    srand(time(NULL));

    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            mm[i][j] = rand() % 10;
        }
    }
    printf("matriz: \n");
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            printf("%d ", mm[i][j]);
        }
        printf("\n");
    }
    printf("matriz transposta: \n");
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            mmt[i][j] = mm[j][i];            
        }
    }
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            printf("%d ", mmt[i][j]);
        }
        printf("\n");
    }

    return 0;
}
