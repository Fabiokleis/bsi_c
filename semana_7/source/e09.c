#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int intercalaVetores(int v[], int v2[], int v3[], int n);

int main(){
    int i;
    int v[N], v2[N], v3[N*2];
    srand(time(NULL));

    for(i=0; i < N; i++){
        v[i] = rand() % N+1;
        v2[i] = N + rand() % N+1;
    }
    intercalaVetores(v, v2, v3, N);
    printf("vetor1[]: ");
    for(i=0; i < N; i++){
        printf("%d ", v[i]);
    }
    printf("\nvetor2[]: ");
    for(i=0; i < N; i++){
        printf("%d ", v2[i]);
    }
    printf("\nvetor3[]: ");
    for(i=0; i < N*2; i++){
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}

int intercalaVetores(int v[], int v2[], int v3[], int n){
    int i, j=0, k=0;
    for(i=0; i < n*2; i++){
        if(i % 2 == 0){
            v3[i] = v[j];
            j++;
        }
        if(i % 2){
            v3[i] = v2[k];
            k++;
        }
    }
    return 0;
}


