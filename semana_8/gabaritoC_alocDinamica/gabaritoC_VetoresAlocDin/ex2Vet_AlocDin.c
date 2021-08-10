#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * alocaVetor(int tam);
void preencheVetor(int v[], int n, int lim);
void imprimeVetor(int v[], int n);
int * realocaVetor(int *v, int novoTam);
int * reduzVetor(int v[], int tam);//recebe atraves de v, o end inicial do bloco, retorna o end do bloco menor realocado

int main (){
    int *valores,t;
    srand(time(NULL));//inicialização da semente
    printf("Entre com a dimensao do vetor a ser preenchido: ");
    scanf("%d",&t);
    // Aloca, preenche e mostra o vetor de tamanho t
    valores = alocaVetor(t);
    preencheVetor(valores,t,10);
    imprimeVetor(valores,t);
    //rezuz o vetor eliminando uma posicao escolhida (realoca o bloco de memoria)
    valores=reduzVetor(valores,t);
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
int * realocaVetor(int *v, int novoTam){
    int *novo_v;
    novo_v= (int *) realloc(v, novoTam*sizeof(int));
    if(novo_v==NULL){
        printf("Erro de realocacao!!!");
        exit(1);
    }
    return novo_v;
}
int * alocaVetor(int tam){
    int *v;
    v= (int *) malloc(tam*sizeof(int));
    if(v==NULL){
        printf("Erro de alocacao!!!");
        exit(1);
    }
    return v;
}
int * reduzVetor(int v[], int tam)//recebe o endereço inicial do bloco, retorna o endereço do bloco menor
{
    int i,pos, *v_reduzido;
    // Pede o índice do valor a remover
    do{
          printf ("Que posicao deseja remover (0 a %d)? ",tam-1);
          scanf ("%d", &pos);
    }while(pos>= tam);
    // Desloca todos os valores a partir da posição dada para a esquerda.
    for (i = pos+1; i < tam; i++)
        v[i-1] = v[i];
   v_reduzido=realocaVetor(v, tam-1);
   return v_reduzido; // poderia nem ter declara v_reduzido e usado direto return realocaVetor(v, tam-1);
}
