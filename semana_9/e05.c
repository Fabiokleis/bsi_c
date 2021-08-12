#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int mat;
    char nome;
    int sup;
} Funcionario;

int Indice_funcionario(Funcionario *vet, int n, int mat);

int main(){
    int i, n, ret, mat;
    Funcionario *v;

    printf("n funcionarios: ");
    scanf("%d", &n);

    v = (Funcionario*) malloc(n*sizeof(Funcionario));

    if(v == NULL){
        printf("ERROR\n");
        return 1;
    }

    srand(time(NULL));

    for(i=0; i < n; i++){
        v[i].mat = 120+i;
        v[i].sup = 120+(n-1)-i;
        v[i].nome = (char)(rand()%25)+65;

        printf("%c -> mat %d - sup %d\n", v[i].nome, v[i].mat, v[i].sup);
    }

    printf("mat: ");
    scanf("%d", &mat);
    ret = Indice_funcionario(v, n, mat);

    if(ret > -1){
        printf("índice: %d\n", ret);
    }

    return 0;
}

int Indice_funcionario(Funcionario *vet, int n, int mat){
    int i;
    for(i=0; i < n; i++){
        if(vet[i].mat == mat){
            return i;
        }
    }
    return -1;
}
