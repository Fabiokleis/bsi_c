#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, m=0;
    char nome[50];
    char bairro[50];
    char vog[10] = "AEIOUaeiou";
    char *ret = (char*) malloc(100);
        
    printf("nome: ");
    fgets(nome, 50, stdin);
    printf("bairro: ");
    fgets(bairro, 50, stdin);
    
    for(i=0; nome[i] != '\0'; i++){
        for(j=0; j < 10; j++){
            if(nome[i] == vog[j]){
               ret[m] = nome[i];
               m++;
            }
        }
    }

    for(i=0; bairro[i] != '\0'; i++){
        for(j=0; j < 10; j++){
            if(bairro[i] == vog[j]){
                ret[m] = bairro[i];
                m++;
            }
        }
     }

    ret = (char*) realloc(ret,m);

    printf("%s\n", ret);

    return 0;
}

