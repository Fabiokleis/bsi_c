#include<stdio.h>
#include<math.h>

int calcula_raizes(float a, float b, float c, float *raiz1, float *raiz2);

int main()
{
    float a, b, c,raiz1,raiz2;

    printf("Digite os coeficientes ax^2 + bx + c da equacao de segundo grau: ");
    scanf("%f %f %f", &a,&b,&c);

    printf("%f %f %f\n", a,b,c);

    if(calcula_raizes(a,b,c,&raiz1,&raiz2)==1)
        printf("As raizes da equacao %.2f x^2 + %.2f x + %.2f sao %.2f e %.2f", a,b,c,raiz1, raiz2);
    else
         printf("Nao existem raizes reais");

    return 0;
}

int calcula_raizes(float a, float b, float c, float *raiz1, float *raiz2)
{
    float delta;

    delta = (b*b) - (4*a*c);

    printf("delta: %f",delta);

    if(delta<0)
        return(-1);
    else if(delta==0)
    {
        *raiz1= -b/(2*a);
        *raiz2= *raiz1;
    }
    else
    {
        *raiz1= (-b +  sqrt(delta))/(2*a);
        *raiz2= (-b -  sqrt(delta))/(2*a);
    }
    return(1);//flag indicando que deu certo o calculo
}


