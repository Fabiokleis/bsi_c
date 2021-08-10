#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocaVetor(int **v, int tam);//aloca vetor retornar por referencia
void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
void realocaVetor(int **v, int novoTam); //realoca por ref para um bloco menor
void reduzVetor(int **v, int tam);

int main ()
{
    int *valores,t;

    srand(time(NULL));//inicialização da semente

    printf("Entre com a dimensao do vetor a ser preenchido: ");
    scanf("%d",&t);

    // Aloca por ref, preenche e mostra o vetor de tamanho t
    alocaVetor(&valores,t);
    preencheVetor(valores,t,10);
    imprimeVetor(valores,t);

    //rezuz o vetor eliminando uma posicao escolhida (realoca o bloco de memoria)
    reduzVetor(&valores,t);

    // Mostra o vetor resultante
    imprimeVetor(valores,t-1);

    free(valores);
    return 0;
}

void preencheVetor(int v[], int n, int lim){

    int i;

    for(i=0; i<n; i++)
        v[i] = rand()%lim+1;
}


void imprimeVetor(int v[], int n){

    int i;

    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void alocaVetor(int **v, int tam)
{
    *v= (int *) malloc(tam*sizeof(int));
    if(*v==NULL)
    {
        printf("Erro de alocacao!!!");
        exit(1);
    }
}


void realocaVetor(int **v, int novoTam) //*v se refere ao ponteiro  original da funcao que chamou realoca (mexeu aqui em *v altera o ponteiro original)
{
    int *aux;

    aux= (int *) realloc(*v, novoTam*sizeof(int));
    if(aux==NULL)
    {
        printf("Erro de realocacao!!!");
        exit(1);
    }
    *v=aux;
}


void reduzVetor(int **v, int tam)//*v se refere ao ponteiro  original da funcao que chamou realoca (mexeu aqui em *v altera o ponteiro original)
{
    int i,pos;
    // Pede o índice do valor a remover
    do{
          printf ("Que posicao deseja remover (0 a %d)? ",tam-1);
          scanf ("%d", &pos);
    }while(pos>= tam);

    // Desloca todos os valores a partir da posição dada para a esquerda.
    for (i = pos+1; i < tam; i++)
        (*v)[i-1] = (*v)[i]; //aqui precisa do (.) por causa da precedencia de * e [.]

   realocaVetor(v, tam-1);//v guarda o & do ponteiro original então não precisa enviar o & nessa pass por referencia

}
