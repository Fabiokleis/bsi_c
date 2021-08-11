#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int cod;
    int tel;
    float pc;
} Elc;

int main(){
    int i; 
    float media=0;
    Elc v[15];
    srand(time(NULL));

    for(i=0; i < 15; i++){
        v[i].pc = (rand()% 1000)+1;
        v[i].cod = (rand()%100000000);
        v[i].tel = (rand()%999999999);
        printf("%d - %d - %f\n", v[i].cod, v[i].tel, v[i].pc);
        media += (float) v[i].pc/15;
    }
    printf("\n\n");
    printf("media = %f\n", media);
    printf("Lojas abaixo do preço médio: \n");
    for(i=0; i < 15; i++){
        if(v[i].pc < media){
            printf("tel: %d e preço: %f\n", v[i].tel, v[i].pc);
        }
    }


    return 0;
}

