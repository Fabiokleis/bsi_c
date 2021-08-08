#include <stdio.h>
#include <math.h>

#define NDIG 3

int calculaDigitoVerificador(int num);

int main()
{
    int num, digito;

    printf("Digite o valor que deseja calcular o dígito verificador (%d digitos): ", NDIG);
    scanf("%d", &num);

    //consistência dos dados de entrada
    while(num < pow(10,NDIG-1) || num >= pow(10,NDIG))
    {
        printf("Digite o valor que deseja calcular o dígito verificador (tres digitos): ");
        scanf("%d", &num);
    }

    // chamada da função
    digito = calculaDigitoVerificador(num);
    printf("Resposta: %d-%d", num, digito);

    return 0;
}

int calculaDigitoVerificador(int num)
{
    int i, soma=0;

    for(i=3; i>=1; i--) // fazemos um for ao invés de while porque o exercício determina que o valor de entrada tem três dígitos!!
    {
        soma = soma + num%10 * i; // usamos a variação decrescente do i para conseguir multiplicar o dígito pelo valor correspondente
        num = num/10; // atualiza o valor do num
    }

    return ((soma % 11) %10); //retorno da expressão
}
