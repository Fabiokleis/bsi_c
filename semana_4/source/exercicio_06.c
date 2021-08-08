#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int random, tt, j=0;
    srand(time(NULL));
    random = rand() % 500;
    do{
        printf("adivinhe o número mágico entre 1 e 500: ");
        scanf("%d", &tt);
        if(tt > random){
            printf("Sua tentativa é maior que o número mágico.\n");
        }
        if(tt < random){
            printf("Sua tentativa é menor que o número mágico.\n");
        }
        
        j++;

    }while(random != tt);


    if(j <= 3){
        printf("(a) 1 - 3 tentativas. \\o/ \n");
    }else if(j <= 6){
        printf("(b) 4 - 6 tentativas.\n");
    }else if(j <= 10){
        printf("(c) 7 - 10 tentativas.\n");
    }else if(j > 10){
        printf("(d) Mais que 10 tentativas :-\\ \n");
    }
 
    return 0;
}
