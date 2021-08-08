#include <stdio.h>

int main(){
    printf("calculando valor do menor número divisível por cada um dos números de 1 a 20...\n");
    int i=0, j=0, d=0, v=18;

    do{
        d = 0;
        v = v + 2;
        for(i = 1; i <= 20; i++){
            if(v % i == 0){
                d++;
                break;
            }
        }
    }while(d != 20);

    
    printf("valor = %d\n", v);

    return 0;
}
