#include<stdio.h>
#include<stdlib.h>
#define TAM 5 //definição de uma constante

void imprimeVetor(int v[], int n);
int achouElemVetor(int v[], int tam, int num);
int criaVetor(int v[], int tamMax);


int main(){
    //declaração de variáveis
    int vetor[TAM], tam=0;

    tam=criaVetor(vetor,TAM);
    imprimeVetor(vetor,tam);

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

int criaVetor(int v[], int tamMax)
{
    int ind=0, num;

    printf("Digite o valor que deve ser inserido no vetor: ");
    scanf("%d", &num);

    v[ind]= num;
    ind++;

    while(ind<tamMax)
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
}



