#include <stdio.h>

int ultimoSegmento(int a, int b);

int main()
{
    int a, b, maior, menor;

    printf("Digite dois inteiros positivos: ");
    scanf("%d %d", &a, &b);

    if (a > b) // como a funcao depende que o primeiro argumento passado seja o maior, eh preciso fazer consistencia de dados
    {
        maior = a;
        menor = b;
    }
    else
    {
        maior = b;
        menor = a;
    }

    if (ultimoSegmento(maior,menor) == 1) // se o retorno da funcao for 1...
        printf("%d eh o ultimo segmento de %d\n",b,a);
    else
        printf("%d NAO eh  o ultimo segmento de %d\n",b,a);

    return 0;
}

int ultimoSegmento(int a, int b)
{

    while (b != 0 && a % 10 == b % 10) //enquanto ainda tiver valores de b e os dígitos dos dois numeros forem iguais...
    {
        a = a/10; //atualiza o valor de a, "tirando" o ultimo digito
        b = b/10; //atualiza o valor de b, "tirando" o ultimo digito
    }

    if (b == 0) // se o b chegou ao final, significa que todo o numero b foi percorrido e os digitos sao iguais aos de a
        return 1;
    else
        return 0;

}
