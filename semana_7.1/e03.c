#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int main(){
    // minimax -> o menor elemento da linha em que se encontra o maior elemento da matriz.
    int m[N][N];
    int i, j, max=0, ctrL, ctrC;
    srand(time(NULL));

    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            m[i][j] = rand() % 11;
        }
    }

    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            if(max < m[i][j]){
                max = m[i][j];
                ctrC = j;
                ctrL = i;
            }
        }
    }

    return 0;
}
