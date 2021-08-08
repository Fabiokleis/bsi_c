#include <stdio.h>
#include <math.h>
#define N 5
// triangulo de pascal - binomio de newton
int main(){
    int i, j;
    int mm[N][N];
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            mm[i][j] = i*j
        }
    }
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            printf("%d ", mm[i][j]);
        }
        printf("\n");
    }

    return 0;
}
