#include <stdio.h>
#include <stdlib.h>
#define D 15

int main(){
    int v[D];

    int *v2; // aponta para um lixo na memória.

    v2 = (int*) malloc(10*sizeof(int));

    free(v2);
    
}
