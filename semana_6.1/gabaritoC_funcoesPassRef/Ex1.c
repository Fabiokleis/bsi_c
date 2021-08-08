#include<stdio.h>
#include<math.h>

void questao01(int *a, int*b);

int main()
{
    int v1,v2;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &v1,&v2);
    questao01(&v1, &v2);
    printf("Os novos valores são: %d %d\n", v1,v2);

       return 0;
}

void questao01(int *a, int*b)
{
    *a = *a - 1; //ou (*a)--;
    *b = *b + 1; //ou (*b)++;
}


