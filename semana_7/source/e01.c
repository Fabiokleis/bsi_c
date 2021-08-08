#include <stdio.h>
#define max 5

int main(){
    int i, ctr, j;
    int vetor[max];

    for(i=0; i < (sizeof vetor/sizeof i); i++){
        printf("vetor[%d]: ", i);
        scanf("%d", &ctr);
        for(j=0; j < i; j++){
            while(vetor[j] == ctr){
                printf("vetor[%d] == %d, entre um novo valor: ", j, ctr);
                scanf("%d", &ctr);
            }
        }
        vetor[i] = ctr;
    }

    for(i=0; i < max; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}
