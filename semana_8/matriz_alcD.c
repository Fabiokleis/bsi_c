#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tipo **nome(..., **matriz); // uma funcao que retorna um ponteiro de ponteiro e recebe um ponteiro de ponteiro.

int main(){
    int **teste, i, j, nl, nc;
    printf("nl e nc: ");
    scanf("%d %d", &nl, &nc);
    srand(time(NULL));
    teste = (int**) malloc(nl * sizeof(int*));

    for(i=0; i < nl; i++){
        teste[i] = (int*) malloc(nc * sizeof(int));
    }
    for(i=0; i < nl; i++){
        for(j=0; j < nc; j++){
            teste[i][j] = rand()%10;
            printf("%d ", teste[i][j]);
        }
        printf("\n");
    }
    for(i=0; i < nl; i++){
        free(teste[i]);
    }

    free(teste);
    return 0;
}
