#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome;
    int sup;
} Funcionario;

Funcionario *determinaSubordinado(Funcionario **vet, int n, int mat, int *pTam);

int main(){
    int n, mat, pTam=0, i;
    Funcionario *v, *f;

    printf("n funcionarios: ");
    scanf("%d", &n);
    printf("mat: ");
    scanf("%d", &mat);

    f = determinaSubordinado(&v, n, mat, &pTam);

    printf("subordinados da matricula %d - vetor[%d]\n", mat, pTam);
    for(i=0; i < pTam; i++){
        printf("%c -> mat %d - sup %d\n", f[i].nome, f[i].mat, f[i].sup);
    }

    free(v);
    free(f);
    return 0;
}

Funcionario *determinaSubordinado(Funcionario **vet, int n, int mat, int *pTam){
    int i;
    Funcionario *nFunc;
    
    *vet = (Funcionario*) malloc(n*sizeof(Funcionario));
    nFunc = (Funcionario*) malloc(n*sizeof(Funcionario));

    if(vet == NULL || nFunc == NULL){
        printf("ERROR\n");
        exit(1);
    }
    

    for(i=0; i < n; i++){
        printf("Nome, Mat e Sup%d: ", i);
        scanf(" %c", &(*vet)[i].nome);
        scanf("%d", &(*vet)[i].mat);
        scanf("%d", &(*vet)[i].sup);
    }

    for(i=0; i < n; i++){
        if((*vet)[i].sup == mat){
            nFunc[*pTam].nome = (*vet)[i].nome;
            nFunc[*pTam].mat = (*vet)[i].mat;
            nFunc[*pTam].sup = (*vet)[i].sup;
            (*pTam)++;
//            printf("%c -> mat %d - sup %d\n", nFunc[i].nome, nFunc[i].mat, nFunc[i].sup);
        }
    }

    nFunc = (Funcionario*) realloc(nFunc, *pTam * sizeof(Funcionario));

    if(nFunc == NULL){
        printf("ERROR\n");
        exit(1);
    }
     

    return nFunc;
}

