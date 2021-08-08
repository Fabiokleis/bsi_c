#include <stdio.h>
#include <stdlib.h> //funcao abs(..)

int paridade(int k);

int main()
{
    int n,m,pm,pm_ant,alt = 1;
    do{
        printf("Entre com n > 0: ");
        scanf("%d",&n);
    }while(n<=0);

    m = 1;
    pm_ant = bloco(m);//testa a paridade do 1o elemento
    n = n - m;//faltam n-1 para serem lidos

    while(n>0)
    {   m++;
        pm = paridade((m+n-abs(m-n))/2);// equivale a pm = bloco(min(m,n));
        n = n - m;
        if(pm == pm_ant || pm == -1)
            alt = 0;
        pm_ant = pm;
    }
    if(n==0 && alt == 1) //se n for negativo (mesmo que alt seja 1) nao eh m-alternante porque faltou termo na ultima seq
        printf("piramidal %d-alternante\n",m);
    else
        printf("Nao eh piramidal m-alternante \n");
    return 0;
}

/*
Devolve:
0, se os n numeros lidos forem pares;
1, se os n numeros lidos forem impares;
-1, se entre os n numeros lidos ha numeros com paridades diferentes.
*/
int paridade(int k)
{
    int i,num,pari;
    scanf("%d",&num);
    pari = num%2;
    for(i = 2; i <= k; i++)
    {
        scanf("%d",&num);
        if(num%2 != pari)
            pari = -1;
    }
    return pari;
}

