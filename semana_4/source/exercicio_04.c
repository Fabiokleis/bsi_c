#include <stdio.h>

int main(){
    
    int n1, n2, gt, j=1;
    
    printf("Primeiro número: ");
    scanf("%d", &n1);
    printf("Segundo número: ");
    scanf("%d", &n2);

    if(n1 > n2){
        gt = n1;
    }else{
        gt = n2;
    }

    while(j){
        if((gt % n1 == 0) && (gt % n2 == 0)){
            printf("MMC %d;\n", gt);
            j = 0;
        }
        ++gt;
    }

    return 0;
}
