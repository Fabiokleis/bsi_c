#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmAlloc(int ***mt, int d, int d2);
void expandMm(int ***mt, int d, int d2);
void mmTgenerate(int **mt, int ***mmt, int d, int d2);
void showMm(int **mt, int d, int d2);
void dAloc(int ***mt, int d);


int main(){
    int **mm, **mmt, d, d2;
    printf("numero de linhas: ");
    scanf("%d", &d);
    printf("numero de colunas: ");
    scanf("%d", &d2);
    mmAlloc(&mm, d, d2);
    expandMm(&mm, d, d2);
    printf("A %dx%d", d, d2);
    showMm(mm, d, d2);
    mmAlloc(&mmt, d2, d);
    mmTgenerate(mm, &mmt, d2, d);
    printf("At %dx%d", d2, d);
    showMm(mmt, d2, d);
    dAloc(&mm, d);
    dAloc(&mmt, d2);
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
    printf("\n");
    for(i=0; i < d; i++){
        for(j=0; j < d2; j++){
            printf("|%d", mt[i][j]);
        }
        printf("|\n");
    }
}

void dAloc(int ***mt, int d){
    int i;
    for(i=0; i < d; i++){
        free((*mt)[i]);
    }
    free(*mt);
}

void expandMm(int ***mt, int d, int d2){
    int i, j;
    srand(time(NULL));
    for(i=0; i < d; i++){
        for(j=0; j < d2; j++){
            (*mt)[i][j] = rand() % 10;
        }
    }
}

void mmTgenerate(int **mt, int ***mmt, int d, int d2){
    int i, j;
    for(i=0; i < d; i++){
        for(j=0; j < d2; j++){
           (*mmt)[i][j] = mt[j][i];
        }
    }
}

