#include<stdio.h>

int ehRegular(int n);

int main()
{
    int n;       // entrada

    printf("Entrada (maior que 1): "); //o ideal é fazer consistencia de dados com while!!
    scanf("%d", &n);

    if (ehRegular(n)==1)
        printf("Eh regular!");
    else
        printf("NAO eh regular!");

    return 0;
}

int ehRegular(int n)
{
    int fator,   // candidato a fator do numero dado
        controle, // indicadora que diz se é ou não fator
        ehRegular = 1;// indicadora que controla se eh regular (fatores primos são apenas 2, 3 e 5)

    fator = 2; //primeiro candidato a fator
    while (n > 1) // enquanto o numero for maior que 1
    {
        controle = 0; // assime que fator não vai ser fator
        while (n % fator == 0) // se fator for divisor de n
        {
            controle = 1; // eh fator
            n = n / fator; // atualiza n
        }
        if (controle == 1) // se o controle for 1, eh porque era fator
        {
            if (  !(fator==2 || fator ==3 || fator ==5)) // se nao atende aos requisitos...
            {
                ehRegular = 0; //... nao eh regular
                break; //interrompe o lacco
            }
        }
        fator++; //incrementa para testar o proximo candidato a fator
    }

    return ehRegular;
}
