#include <stdio.h>
#include <math.h>

#define NDIG 3

int calculaDigitoVerificador(int num);

int main()
{
    int num, digito;

    printf("Digite o valor que deseja calcular o d�gito verificador (%d digitos): ", NDIG);
    scanf("%d", &num);

    //consist�ncia dos dados de entrada
    while(num < pow(10,NDIG-1) || num >= pow(10,NDIG))
    {
        printf("Digite o valor que deseja calcular o d�gito verificador (tres digitos): ");
        scanf("%d", &num);
    }

    // chamada da fun��o
    digito = calculaDigitoVerificador(num);
    printf("Resposta: %d-%d", num, digito);

    return 0;
}

int calculaDigitoVerificador(int num)
{
    int i, soma=0;

    for(i=3; i>=1; i--) // fazemos um for ao inv�s de while porque o exerc�cio determina que o valor de entrada tem tr�s d�gitos!!
    {
        soma = soma + num%10 * i; // usamos a varia��o decrescente do i para conseguir multiplicar o d�gito pelo valor correspondente
        num = num/10; // atualiza o valor do num
    }

    return ((soma % 11) %10); //retorno da express�o
}
