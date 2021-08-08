#include <stdio.h>

float calculaIMC(float altura, float peso);
void imprimeMsgIMC(float imc);

int main(){
    float alt, peso, ret;
    printf("digite altura e o peso: ");
    scanf("%f %f", &alt, &peso);

    ret = calculaIMC(alt, peso);

    printf("O IMC é: %f\n", ret);
    imprimeMsgIMC(ret);

    return 0;
}

float calculaIMC(float altura, float peso){
    return (peso/(altura*altura));
}

void imprimeMsgIMC(float imc){
    if(imc < 18.5){
        printf("Voce esta abaixo do peso.\n");
    }else if(imc < 25){
        printf("Voce esta com peso normal.\n");
    }else if(imc < 30){
        printf("Voce esta acima do peso.\n");
    }else{
        printf("Voce esta obeso.\n");
    }
}
