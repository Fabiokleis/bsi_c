#include <stdio.h>

void removeExtremos(int *n, int *pri, int *ult);


int main()
{
   int n, pri, ult, ehPal=1;

   printf("Por favor foneca um número inteiro positivo:");
   scanf("%d",&n);

   while(n>0)
   {
       removeExtremos(&n,&pri,&ult);
       if(pri != ult)  {
            ehPal=0;
            break;
       }
   }

   if(ehPal)
      printf("Eh palindromo!");
   else
      printf("NAO eh palindromo!");

    return 0;

}



void removeExtremos(int *n, int *pri, int *ult)
{
    int tn,pot = 1;
    tn = *n;
// procura qual ordem de grandeza do número (pot): unidade, dezena, centena, .....
    while(tn >= 10)
    {
        tn = tn/10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}
