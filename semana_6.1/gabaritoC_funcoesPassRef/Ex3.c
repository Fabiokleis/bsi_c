#include<stdio.h>

void converteHora(int total, int *hora, int *min, int *seg);

int main(){

    int input,
        h, m, s;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &input);

    converteHora(input, &h, &m, &s);

    printf("%d segundos correspondem a %d horas, %d minutos e %d segundos", input, h, m, s);

    return 0;
}

void converteHora(int total, int *hora, int *min, int *seg){

    *hora = total / (60*60);
    *min = total % (60*60) / 60;
    *seg = total % (60*60) % 60;
}
