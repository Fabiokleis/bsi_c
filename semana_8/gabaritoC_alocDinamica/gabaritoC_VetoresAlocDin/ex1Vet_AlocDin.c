#include<stdio.h>
#include<stdlib.h> //header da função malloc

// essa versao considera que o usuário fornece um tamanho para o vetor

void imprimeVetor(int v[], int n);
int achouElemVetor(int v[], int tam, int num);
int criaVetor(int v[], int tamMax);
int* criaVetorAlocDin(int tam);


int main()
{
    int *vetor, tam;

    printf("Digite o tamanho do vetor a ser criado: ");
    scanf("%d", &tam);

    vetor=criaVetorAlocDin(tam);
    imprimeVetor(vetor,tam);

    free(vetor); //desaloca espaço alocado

    return 0;
}


void imprimeVetor(int v[], int n){

    int i;

    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
}


int achouElemVetor(int v[], int tam, int num)
{
    int i;

    for(i=0;i<tam;i++)
    {
         if(num==v[i])
            return 1; //retorna flag indicando que achou elemento
    }
    return 0;
}

int* criaVetorAlocDin(int tam)
{
    int ind=0, num, *v;

    v = (int *) malloc(tam*sizeof(int)); //aloca espaco para tam inteiros na memória
    //e guarda o endereço do inicio do bloco em v

    if(v==NULL)//programa nao conseguiu alocar o espaco solicitdo
    {
         printf("Erro de alocação no vetor v");
         exit(1); //abandona o programa por erro de alocacao
    }

    printf("Digite o valor que deve ser inserido no vetor: ");
    scanf("%d", &num);
    v[ind]= num;
    ind++;

    while(ind<tam)
    {
        printf("Digite o valor que deve ser inserido no vetor: ");
        scanf("%d", &num);
        if(!achouElemVetor(v,ind,num))
        {
            v[ind]= num;
            ind++;
        }
        else printf("Valor repetido!!!\n");
    }
    return v;

}



