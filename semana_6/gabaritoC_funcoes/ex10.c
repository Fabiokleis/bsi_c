#include <stdio.h>

int retornaMDC(int num1, int num2);


int main()
{
    int a,b,mdc;

    printf("Por favor forneca dois valores positivos:");
    scanf("%d %d",&a,&b);
    mdc = retornaMDC(a,b);
    printf("MDC = %d\n", mdc);
    return 0;
}

int retornaMDC(int num1, int num2)
{
  while(num1!=num2)
  {

    if(num1>num2)
      num1=num1-num2;
    else
      num2=num2-num1;
  }
  return num1;
}
