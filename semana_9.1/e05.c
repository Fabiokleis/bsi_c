#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j=0;
    char nome[50];
    char *abv = (char*) malloc(50);
    printf("nome: ");
    fgets(nome, 50, stdin);
    
    for(i=0; nome[i] != '\0'; i++){
        if((int)nome[i] == 32 || (int)nome[i] == '\0'){
            abv[j] = nome[i];
            j++;
        }
    }
    printf("%s", abv);

    return 0;
}
