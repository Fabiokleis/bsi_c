#include <stdio.h>

int contadigitos(int n, int d);
int ehPermutacao(int n1, int n2);

main()
{
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d",&a,&b);

    if (ehPermutacao(a,b) == 1)
        printf("%d e' permutacao de %d\n",a,b);
    else
        printf("%d nao e' permutacao de %d\n",a,b);

}

//Solucao - USP

int contadigitos(int n, int d)
{
    int conta = 0, resto;

    while (n != 0)
    {
        resto = n % 10; //último dígito
        n = n/10; // atualiza o número, de tal forma a "retirar" o último dígito
        if (resto == d) // se o dígito extraído for igual ao procurado, incrementa!
            conta++;
    }
    return conta;
}

int ehPermutacao(int n1, int n2)
{
    int d,
        ehPermut = 1; // cria variavel indicadora

    for (d = 1; d <= 9; d++) //para cada dígito
        if (contadigitos(n1,d) != contadigitos(n2,d)) // se a contagem nos dois números foi diferente...
            ehPermut = 0; //... significa que nao eh permutacao!

    if (ehPermut == 1) // dá o retorno de acordo com o valor da variavel indicadora
        return 1;
    else
        return 0;

}

