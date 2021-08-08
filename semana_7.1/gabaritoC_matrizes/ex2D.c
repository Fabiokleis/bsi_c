#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmAlloc(int ***mt, int d, int d2);
void pascalMm(int ***mt, int d);
void showMm(int **mt, int d, int d2);
void dAloc(int ***mt, int d);

int main(){
    int **mm, n;
    printf("Digite o valor de n (n > 0): ");
    scanf("%d", &n);
    mmAlloc(&mm, n, n);
    pascalMm(&mm, n);
    showMm(mm, n, n);
    dAloc(&mm, n);
    return 0;
}

void mmAlloc(int ***mt, int d, int d2){
    int i;
    *mt = (int**) malloc(d*sizeof(int**));
    if(*mt == NULL){
        printf("ERROR\n");
        exit(1);
    }
    for(i=0; i < d; i++){
        (*mt)[i] = (int*) malloc(d2*sizeof(int*));
    }
}

void showMm(int **mt, int d, int d2){
    int i, j;
    for(i=0; i < d; i++){
        for(j=0; j < d2; j++){
            printf("%3d ", mt[i][j]);
        }
        printf("\n");
    }
}

void dAloc(int ***mt, int d){
    int i;
    for(i=0; i < d; i++){
        free((*mt)[i]);
    }
    free(*mt);
}

void pascalMm(int ***mt, int d){
    int i, j;
    for(i=0; i < d; i++){
        (*mt)[i][0] = 1;
    }
    for(i=0; i < d; i++){
        (*mt)[i][i] = 1;
    }

    for(i=2; i < d; i++){
        for(j=1; j < d; j++){
            (*mt)[i][j] = (*mt)[i-1][j-1] + (*mt)[i-1][j];
        }
    }
}
