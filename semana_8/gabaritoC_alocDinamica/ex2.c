#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM 10

void imprimeVetor(int *v, int tam);

// Essa solução nao considera funções para criar os vetores (tudo é feito na função main)

int main ()
{
    int i, j, tamanho1, tamanho2;
    int *vetor1, *vetor2, *vetor_mul;

    printf ("Digite o numero de valores do vetor1: ");
    scanf ("%d", &tamanho1);
    vetor1 = (int*) malloc (tamanho1 * sizeof (int));
    for (i = 0; i < tamanho1; i++)
        vetor1[i] = rand () % (LIM+1);


    printf ("Digite o numero de valores do vetor2: ");
    scanf ("%d", &tamanho2);
    vetor2 = (int*) malloc (tamanho2 * sizeof (int));
    for (i = 0; i < tamanho2; i++)
        vetor2[i] = rand () % (LIM+1);


    imprimeVetor(vetor1, tamanho1);
    imprimeVetor(vetor2, tamanho2);

    /* São tamanho1 * tamanho2 elementos. */
    vetor_mul = (int*) malloc ( (tamanho1*tamanho2) * sizeof (int));

    /* Para cada valor no vetor1... */
    for (i = 0; i < tamanho1; i++)
    {
        /* ... e cada valor no vetor2... */
        for (j = 0; j < tamanho2; j++)
        {
            /* A posição em vetor_mul é dada pelo número de vezes que já
               percorremos o vetor2 (i*tamanho2) + a posição atual no vetor2 (j) */
            int pos_mul = i*tamanho2 + j;

            /* Calcula e mostra. */
            vetor_mul [pos_mul] = vetor1 [i] * vetor2 [j];
            printf ("%d * %d = %d\n", vetor1[i], vetor2[j], vetor_mul[pos_mul]);
        }
    }

    free (vetor1);
    free (vetor2);
    free (vetor_mul);
    return (0);
}

void imprimeVetor(int *v, int tam)
{

     int i;
     for (i = 0; i < tam; i++)
        printf("  %d  ",v[i]);
     printf("\n");

}
