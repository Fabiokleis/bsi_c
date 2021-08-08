#include <stdio.h>

int main()
{

    int n,vant=0,v=1,s,c;

    printf("Entre com um numero (inteiro): ");
    scanf("%d",&n);

    if (n>=3)//minimo de 3 numeros
    {
        printf("%d %d ",vant,v);
        for(c=3;c<=n;c++)  //  a variavel c esta contanto quantos termos estao sendo incluidos na sequencia
        {                  // a partir dos dois primeiros
            s=vant+v;
            printf("%d ",s);
            vant=v;
            v=s;
        }

    }
    else printf("impossivel Serie de Fibonacci com menos de tres termos....");

    return 0;

}
