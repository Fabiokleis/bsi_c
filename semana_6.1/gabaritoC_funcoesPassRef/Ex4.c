#include <stdio.h>

int divide(int *m, int *n, int d);
int mmc (int m, int n);


int main()
{
   int m,n,tn,c;

   do{
    printf("Entre com o total de numeros:");
    scanf("%d",&tn);
   }while(tn<2);

   printf("Entre com o 1o numero:");
   scanf("%d",&m);

   for(c=2;c<=tn;c++)
   {
       printf("Entre com o %do numero:",c);
       scanf("%d",&n);
       m = mmc(m,n); //como eh passagem por valor os valores originais de m e n são preservados
   }
   printf("mmc: %d\n",m);

   return 0;
}

int mmc (int m, int n)//m e n nessa funcao são copias dos originais (então as alteracoes executadas em divide(...) só valem para a funcao mmc (nao para main)
{
    int d=2, prod=1;
    while(m>1 || n> 1)
    {
        if(divide(&m, &n, d)==1)
            prod=prod*d;
        else d++;

    }
    return prod;
}

int divide(int *m, int *n, int d)
{
    int resp=0;

    if(*m%d==0) {
        *m =*m/d;
        resp=1;
    }

    if(*n%d==0) {
        *n =*n/d;
        resp=1;
    }
    return (resp);

}


