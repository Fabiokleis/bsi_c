#include <stdio.h>
#include <stdlib.h>
#define NL 3
#define NC 4

int main(){
    int **mat, i;
  
    mat = (int**) malloc(NL * sizeof(int*));

    for(i=0; i < NL; i++){
        mat[i] = (int*) malloc(NC * sizeof(int));
    }

    // ...

    for(i=0; i < NL; i++){
        free(mat[i]);
    }

    free(mat);
    return 0;
}
