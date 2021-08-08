#include<stdio.h>
#include<stdlib.h>
#define TAM 10 //definição de uma constante


int main(){
    //declaração de variáveis
    int v1[TAM], v2[TAM], i;

    //inicialização da semente para a funcao rand
    srand(time(NULL));

    //preenchimento do vetor
    for(i=0; i<TAM; i++)
    {
        v1[i] = rand()%10;
        v2[i] = rand()%10;
    }

    printf("Primeiro vetor: ");
    for(i=0; i<TAM; i++)
        printf("%3d ", v1[i]);

    printf("\nSegundo vetor: ");
    for(i=0; i<TAM; i++)
        printf("%3d ", v2[i]);

    //como é preciso apenas mostrar a soma, não será criado um novo vetor
    //para armazenar o resultado
    printf("\nSoma: ");
    for(i=0; i<TAM; i++)
        printf("%3d ", v1[i] + v2[TAM-i-1]);


    return 0;
}
