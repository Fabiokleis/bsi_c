#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmAlloc(int ***mt, int d, int d2);
void expandMm(int ***mt, int d, int d2);
void showMm(int **mt, int d, int d2);
void dAloc(int ***mt, int d);


int main(){
    int **mm, d, d2;
    printf("numero de linhas: ");
    scanf("%d", &d);
    printf("numero de colunas: ");
    scanf("%d", &d2);
    mmAlloc(&mm, d, d2);
    showMm(mm, d, d2);
    dAloc(&mm, d);
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
            (*mt)[i][j] = rand() % 10+1;
        }
    }
}
