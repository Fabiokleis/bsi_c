#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome;
    int dia;
    int mes;
} Ani;

int main(){
    int i, n;
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
        scanf("%c %d %d", &v[i].nome, &v[i].dia, &v[i].mes);
    }

    for(i=0; i < n; i++){
        printf("%c %d %d\n", v[i].nome, v[i].dia, v[i].mes);
    }
    free(v);
    return 0;
}


