#include <stdio.h>

int bin2dec(int num);
int dec2bin(int num);

int main()
{
   int opcao,n,bin,dec;


   do{
      printf("Digite \n(1) para converter binario para base 10  \n(2) para converter base 10 para binario \n(0) para parar\n");
      scanf("%d",&opcao);

      if(opcao==1)
      {
            printf("Digite o numero na base 2: ");
            scanf("%d", &n);
            printf("base2:%d convertido para base10:%d\n\n", n, bin2dec(n));


      }
      else if(opcao==2)
      {
            printf("Entre com o valor de n na base 10:");
            scanf("%d",&n);
            printf("base10:%d convertido para base2:%d", n, dec2bin(n));

      }

   }while(opcao!=0);

   return 0;
}

int dec2bin(int num)
{
    int bin=0,mult=1;
    do{
        bin= bin + (num%2)*mult;
        num = num/2;
        mult = mult*10;
     }while(num!=0);
   return(bin);
}

int bin2dec(int num)
{
    int pot2,       // guarda a potencia de 2 pela qual o valor será multiplicado
        resp; //resposta

    // inicializacoes
    resp = 0;
    pot2  = 1;

    while (num != 0)
    {
        resp = resp + num % 10 * pot2;  // processa um digito binario
        num = num / 10; // atualiza valor
        pot2 = pot2 * 2; // atualiza potencia
    }

    return resp;
}
