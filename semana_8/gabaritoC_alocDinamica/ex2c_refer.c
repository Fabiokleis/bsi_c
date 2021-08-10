#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM 10

/* Essa solucao considera fun��es para criar os vetores por refer�ncia:
A fun��o: l� o tamanho de um vetor, aloca dinamicamente, e preenche com valores aleat�rios.
Devolve por refer�ncia o ponteiro para o bloco alocado. Lembre-se de desalocar o vetor depois!
Note que a fun��o informar o tamanho do vetor pois este eh retornado por return*/

int  preparaVetor (int** p_vetor);
void imprimeVetor(int *v, int tam);
int criaImprimeVetorMult (int *v1, int *v2, int **p_v3, int tam1, int tam2);


int main ()
{
    int i, j, tamanho1, tamanho2, tam_mult;
    int *vetor1, *vetor2, *vetor_mul;

    tamanho1 = preparaVetor (&vetor1);
    tamanho2 = preparaVetor (&vetor2);

    tam_mult = criaImprimeVetorMult (vetor1, vetor2, &vetor_mul, tamanho1,tamanho2);

    printf("vetor1: "); imprimeVetor(vetor1, tamanho1);
    printf("vetor2: "); imprimeVetor(vetor2, tamanho2);
    printf("vetor Mult: ");imprimeVetor(vetor_mul, tam_mult);


    free (vetor1);
    free (vetor2);
    free (vetor_mul);
    return (0);
}


int  preparaVetor (int** p_vetor)
{
    int i, tamanho;

    printf ("Digite o numero de valores do vetor: ");
    scanf ("%d", &tamanho);
    *p_vetor = (int*) malloc (tamanho * sizeof (int));

    for (i = 0; i < tamanho; i++)
        (*p_vetor) [i] = rand () % (LIM+1);

    return (tamanho);
}

void imprimeVetor(int *v, int tam)
{

     int i;
     for (i = 0; i < tam; i++)
        printf("  %d  ",v[i]);
     printf("\n");

}

int criaImprimeVetorMult (int *v1, int *v2, int **p_v3, int tam1, int tam2)
{
    int i,j,pos_mult;

     /* S�o tamanho1 * tamanho2 elementos. */
    *p_v3 = (int*) malloc ( (tam1*tam2) * sizeof (int));

    /* Para cada valor no vetor1... */
    for (i = 0; i < tam1; i++)
    {
        /* ... e cada valor no vetor2... */
        for (j = 0; j < tam2; j++)
        {
            /* A posi��o em vetor_mul � dada pelo n�mero de vezes que j�
               percorremos o vetor2 + a posi��o atual no vetor2. */
            int pos_mul = i*tam2 + j;

            /* Calcula e mostra. */
            (*p_v3) [pos_mul] = v1 [i] * v2 [j];
            printf ("%d * %d = %d\n", v1[i], v2[j], (*p_v3)[pos_mul]);
        }
    }

    return (tam1*tam2);
}
