#include <stdio.h>

int main(){
    
    int j=0;
    float ctrValue, avg;

    do{
        printf("digite um número: ");
        scanf("%f", &ctrValue);
        if(ctrValue > 0){
            j++;
            avg = avg + ctrValue;
        } 
    }while(ctrValue != -1000);

    printf("%d Valores positivos\nMedia: %.1f\n", j, (float)avg/j);

    return 0;
}
