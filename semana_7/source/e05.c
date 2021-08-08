#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int v[], int n, int min, int max);

int main(){
    int v[5];
    int n = 5;
    int min, max, i;
    srand(time(NULL));
    printf("min max: ");
    scanf("%d %d", &min, &max);
    preencheVetor(v, n, min, max);
    for(i=0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}


void preencheVetor(int v[], int n, int min, int max){
    int i;
    for(i=0; i < n; i++){
        v[i] = min + rand() % (max-min+1);
    }
}
