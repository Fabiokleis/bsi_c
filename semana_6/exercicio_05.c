#include <stdio.h>

int retornaMaior(int a, int b){
    int maior=0;
    if(a > b){
        maior = a;
    }else{
        maior = b;
    }

    return maior;
}

int main(){
    int a, b, c, ret;

    printf("n1, n2 e n3: ");
    scanf("%d %d %d", &a, &b, &c);
    ret = retornaMaior(a, b);
    ret = retornaMaior(ret, c);

    printf("%d\n", ret);

    return 0;
}
