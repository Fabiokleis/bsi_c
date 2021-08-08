#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int v[], int n, int lim);

int main(){
    int v[5];
    int n = 5;
    int lim, i;
    srand(time(NULL));
    printf("limite: ");
    scanf("%d", &lim);
    preencheVetor(v, n, lim);
    for(i=0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}


void preencheVetor(int v[], int n, int lim){
    int i;
    for(i=0; i < n; i++){
        v[i] = rand() % lim+1;
    }
}
