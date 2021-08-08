#include <stdio.h>

int arredonda(float valor){
    float res;
    
    res = valor - (int)valor;

    if(res >= 0.5 || res <= -0.5){
        valor = valor + res;
    }

    return valor;
}

int main(){
    float valor;
    int ret;
    printf("valor para ser arredondado: ");
    scanf("%f", &valor);
    ret = arredonda(valor);

    printf("%d\n", ret);

    return 0;
}
