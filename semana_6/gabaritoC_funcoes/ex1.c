#include <stdio.h>

int ehBissexto(int ano);

int main()
{
    int ano, retorno;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    //invoca a funcao e armazena o retorno
    retorno = ehBissexto(ano);
    //imprime a mensagem adequada
    if(retorno==1)
        printf("Ano eh bissexto\n");
    else
        printf("Ano nao eh bissexto\n");

    //note que nao eh necessario criar uma variavel para o retorno se fizermos:
    /*if(ehBissexto(ano)==1)
        printf("Ano eh bissexto\n");
    else
        printf("Ano nao eh bissexto\n");
    */
    return 0;
}

int ehBissexto(int ano)
{
    //testa condições e imprime mensagem adequada!
    if ((ano%400 == 0)||(ano%4==0 && ano%100!=0))
          return 1;
    else
          return 0;
}
