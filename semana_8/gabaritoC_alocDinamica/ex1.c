#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * criaVetor(int tam, int lim);
int * expandeVetor(int *v, int tam, int n, int lim);
void criaVetorPorReferencia(int **p_v, int tam, int lim);
void imprimeVetor(int v[], int n);


int main ()
{
    int *vet, *vetPorRef, tam, n;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    vet=criaVetor (tam, 9);
    printf("Vetor original (criado por return)\n");
    imprimeVetor(vet,tam);

    printf("Entre com o total de novos elementos a serem inseridos no vetor: ");
    scanf("%d", &n);
    vet = expandeVetor(vet, tam, n, 9);
    printf("Vetor expandido\n");
    imprimeVetor(vet,tam+n);

    criaVetorPorReferencia(&vetPorRef,tam, 9);//agora o ponteiro que apontava para o lixo vai apontar para o inicio do bloco alocado
    printf("\n\nVetor 2  (criado por referencia)\n");
    imprimeVetor(vetPorRef,tam);

    free (vet);
    free (vetPorRef);

    return (0);

}

void imprimeVetor(int v[], int n){

    int i;

    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
}


int * criaVetor(int tam, int lim)
{
    int i, *v;

    v = (int *) malloc(tam*sizeof(int));
    if(v==NULL)
    {
        printf("Erro alocacao do vetor");
        exit(1);
    }
    for(i=0;i<tam;i++)
        v[i]=rand()%(lim+1);

    return v;
}

int * expandeVetor(int *v, int tam, int n, int lim)
{
    int i, *vExpandido;

    vExpandido = (int *) realloc(v,(tam+n)*sizeof(int));//aloca um novo bloco de inteiros mas copia o conteudo ja
    //preenchido para o novo bloco alocado (cujo enredeço inicial eh guardado em vExpandido)
    if(vExpandido==NULL)
    {
        printf("Erro alocacao do vetor expandido");
        exit(1);
    }
    for(i=0;i<n;i++)
        vExpandido[tam+i]=rand()%(lim+1); //sorteia um inteiro no range -lim a +lim

    return vExpandido;
}

void criaVetorPorReferencia(int **p_v, int tam, int lim) //*v eh o ponteiro original
//**v eh recebido para que a funcao possa modificar o endereço do ponteiro original (passagem de ponteiro por ref)
{
    int i;

    *p_v = (int *) malloc(tam*sizeof(int));//tentar alocar um bloco de tam inteiros
    //e guarda o endereço do inicio do bloco em *v (que é o ponteiro original da funcao main)
    if(*p_v==NULL)
    {
        printf("Erro alocacao do vetor");
        exit(1);
    }

    for(i=0;i<tam;i++)
        (*p_v)[i]= -lim + rand()%(2*lim+1);  //sorteia um inteiro no range -lim a +lim

}

