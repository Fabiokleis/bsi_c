#include <stdio.h>

int main(){
    float chico = 1.50;
    float ze = 1.10;
    int j;

    for(j = 0; ze < chico; j++){
        chico = chico + 0.02;
        ze = ze + 0.03;
    }

    printf("Quantidade de anos: %d;\n", j);

    return 0;
}
