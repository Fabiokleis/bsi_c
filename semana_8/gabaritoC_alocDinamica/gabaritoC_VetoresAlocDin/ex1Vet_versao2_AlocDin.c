#include<stdio.h>
#include<stdlib.h> //header da função malloc

// essa versao considera que o usuário vai fornecendo valores até que digite -1
void imprimeVetor(int v[], int n);
int achouElemVetor(int v[], int tam, int num);
int criaVetor(int v[], int tamMax);
int* criaVetorAlocDin(int *tam);

int main()
{
    int *vetor, tam;
    vetor=criaVetorAlocDin(&tam);//tam vai com lixo e volta com o tamanho do vetor criado
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

int* criaVetorAlocDin(int *tam)
{
    int ind=0, num, *v, *aux;

    printf("Digite o valor positivo que deve ser inserido no vetor (-1 para parar): ");
    scanf("%d", &num);//assumindo que serao fornecidos apenas >0 (-1 para)

    while(num!= -1)
    {

        if(ind==0)  //1o elemento a ser inserido
        {
             v = (int *) malloc(1*sizeof(int)); //aloca espaco para 1 inteiro na memória
            //e guarda o endereço  em v
            if(v==NULL)//programa nao conseguiu realocar o espaco solicitdo
            {
                printf("Erro de alocacao no vetor v");
                exit(1); //abandona o programa por erro de alocacao
            }
            v[ind]= num;
            ind++;
        }
        else
        {

            if(!achouElemVetor(v,ind,num))
            {
                aux = (int *) realloc(v,1*sizeof(int));
                if(aux==NULL)//programa nao conseguiu realocar o espaco solicitdo
                {
                    printf("Erro de realocação no vetor");
                    exit(1); //abandona o programa por erro de alocacao
                }
                else v=aux;

                v[ind]= num;
                ind++;
            }
            else printf("Valor repetido!!!\n");
        }

        printf("Digite o valor positivo que deve ser inserido no vetor (-1 para parar): ");
        scanf("%d", &num);//assumindo que serao fornecidos apenas >0 (-1 para)

    } //fim while
    *tam=ind;
    return v;
}



