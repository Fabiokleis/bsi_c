#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 10

int criaOutroVetor(int *vetor, int **vetor2);

int main(){
    int i, *vetor, *vetor2, ret;
    vetor = (int*) malloc(T*sizeof(int));
    if(vetor == NULL){
        printf("ERROR\n");
        exit(1);
    }
    srand(time(NULL));
    printf("vetor1[0-%d]: ", T-1);
    for(i=0; i < T; i++){
        vetor[i] = rand()%T+1;
        printf("%d ", vetor[i]);
    }
    printf("\n");
    ret = criaOutroVetor(vetor, &vetor2);
    printf("total de espaços alocados %d*4 bytes\n", ret);
    free(vetor);
    free(vetor2);
    return 0;
}

int criaOutroVetor(int *vetor, int **vetor2){
    int i, j, tt=T, vetorI[T], flag=0, k=0;
    for(i=0; i < T; i++){
        flag = 0;
        for(j=0; j < i; j++){
            if(vetor[i] == vetor[j]){
                flag = 1;
                tt--;
                break;
            }
        }
        if(!flag){     
            vetorI[k] = vetor[i];
            k++;
        }
    }

    *vetor2 = (int*) malloc(tt*sizeof(int));
    if(*vetor2 == NULL){
        printf("ERRO\n");
        exit(1);
    }
    printf("vetor2[0-%d]: ", tt-1);
    for(i=0; i < tt; i++){
        (*vetor2)[i] = vetorI[i];
        printf("%d ", (*vetor2)[i]);
    }
    printf("\n");
    
    return tt;
}


