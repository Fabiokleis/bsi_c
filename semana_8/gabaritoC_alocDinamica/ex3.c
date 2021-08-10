/* Precisamos percorrer o vetor original e ir removendo os elementos repetidos.
Um dos problemas é que não podemos modificar o conteúdo do vetor original. Outro
problema é saber o tamanho do vetor final.

Existem várias opções para resolver estes problemas. Aqui, alocamos um vetor
com o mesmo tamanho do original, e vamos jogando nele os valores encontrados.
Pesquisamos os valores já inseridos para ver se não existem repetições. No
final, re-alocamos o vetor, mantendo apenas o número necessário de posições. Não
vimos a função realloc em sala - a próxima versão faz a mesma coisa que esta,
mas sem usar o realloc. */

#include <stdio.h>
#include <stdlib.h>

int removeRepeticoes (int* vetor, int tam_vetor, int** novo_vetor)
{
    int i, j;
    int tam_novo = 0;
    *novo_vetor = (int*) malloc (sizeof (int) * tam_vetor);

    /* Pega cada item do vetor original... */
    for (i = 0; i < tam_vetor; i++)
    {
        int ja_tem = 0; /* Flag que avisa se o vetor novo ja tem o item. */

        /* Verifica se este valor já foi inserido no vetor. */
        for (j = 0; j < tam_novo && !ja_tem; j++)
            if (vetor [i] == (*novo_vetor) [j])
                ja_tem = 1;

        /* Se não achou, insere. */
        if (!ja_tem)
            (*novo_vetor) [tam_novo++] = vetor [i];
    }

    /* Re-aloca. */
    *novo_vetor = (int*) realloc (*novo_vetor, sizeof (int) * tam_novo);

    return (tam_novo);
}

/* Esta versão não usa o realloc. Ela é um pouco menos eficiente, e usa um vetor
auxiliar dentro da função. */

int removeRepeticoes (int* vetor, int tam_vetor, int** novo_vetor)
{
    int i, j;
    int tam_novo = 0;
    int* vetor_aux;

    vetor_aux = (int*) malloc (sizeof (int) * tam_vetor);

    /* Pega cada item do vetor original... */
    for (i = 0; i < tam_vetor; i++)
    {
        int ja_tem = 0; /* Flag que avisa se o vetor novo ja tem o item. */

        /* Verifica se este valor já foi inserido no vetor. */
        for (j = 0; j < tam_novo && !ja_tem; j++)
            if (vetor [i] == vetor_aux [j])
                ja_tem = 1;

        /* Se não achou, insere. */
        if (!ja_tem)
            vetor_aux [tam_novo++] = vetor [i];
    }

    /* Aloca. */
    *novo_vetor = (int*) malloc (sizeof (int) * tam_novo);

    /* Copia */
    for (i = 0; i < tam_novo; i++)
        (*novo_vetor) [i] = vetor_aux [i];
    free (vetor_aux);

    return (tam_novo);
}

/* Uma observação sobre as abordagens acima é que elas funcionam bem apenas
quando o tamanho dos vetores é pequeno em comparação com a faixa de valores
possível. Se a faixa de valores for menor que o número de itens do vetor (por
exemplo, se forem 1000 itens com valor entre 1 e 100), é mais eficiente alocar
um vetor de flags para dizer quais valores aparecem no vetor original. Depois,
alocamos o novo vetor já com o tamanho apropriado, e fazemos uma segunda passada
no vetor original, desta vez copiando os valores para o vetor final. */


//Solução Bogdan
