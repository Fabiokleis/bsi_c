#include <stdio.h>

int main(){
    
    int ctrValue, gt=0;
    do{
        printf("digite um número: ");
        scanf("%d", &ctrValue);
        if(ctrValue > gt){
            gt = ctrValue;
        } 
    }while(ctrValue >= 0);

    printf("O maior valor digitado é %d;\n", gt);

    return 0;
}
