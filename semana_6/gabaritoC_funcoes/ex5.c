#include <stdio.h>

int retornaMaior(int n1, int n2);

int main()
{
    int num1, num2, num3, maior;

    printf("Digite os tres valores de entrada: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    maior = retornaMaior(num1, retornaMaior(num2, num3));
    printf("O maior eh: %d", maior);

    //lembre-se que poderíamos fazer a chamada à função diretamente a partir do printf
    //printf("O maior eh: %d", retornaMaior(num1, retornaMaior(num2, num3)));

    return 0;
}

int retornaMaior(int n1, int n2)
{
    // assumimos que, se os valores forem iguais, qualquer um é maior!
    if (n1>n2)
          return n1;
    else
          return n2;
}
