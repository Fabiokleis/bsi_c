#include <stdio.h>

int calculaDigitoVerificador(int num){
    int i, u, h, ret=0;
    h = num;
    while(h){
        u = h % 10;
        for(i=0; i < 3; i++){
            ret =  ret + (i * u);
        }
        h /= 10;
    }

    return ((ret % 11)%10);
}

int main(){
    int a, ret;
    printf("n inteiro: ");
    scanf("%d", &a);
    ret = calculaDigitoVerificador(a);
    printf("digito: %d\n", ret);

    return 0;
}
