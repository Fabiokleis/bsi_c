#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome;
    int dia;
    int mes;
} Ani;

int main(){
    int i, j, n, k;
    Ani *v;
    printf("numero de aniversariantes: ");
    scanf("%d", &n);
    v = (Ani*) malloc(n * sizeof(Ani));
    if(v == NULL){
        printf("error\n");
        exit(1);
    }

    for(i=0; i < n; i++){
        printf("nome, dia e mes: ");
        scanf(" %c %d %d", &v[i].nome, &v[i].dia, &v[i].mes);
    }

    for(i=0; i < 12; i++){
        printf("%.2d ", i+1);
    }
    printf("\n");
    free(v);
    return 0;
}


