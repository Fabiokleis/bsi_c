#include <stdio.h>

int retornaMDC(int *n1, int *n2){
    int ctr;
    // 18 12
    while(*n1 > 0){

       if(*n1 < *n2){
           *n1 = *n2; // 6 = 12;
           *n2 = ctr; // 12 = 6;
       }
       //printf("n1 = %d; n2 = %d\n", *n1, *n2);

       *n1 = *n1 - *n2; // 18 - 12 = 6; 12 - 6 = 6; 6 - 6 = 0;
       if(*n1 > 0){
           ctr = *n1; // 6; 6;
       }
    }

    return ctr;
}

int main(){
    int a, b, r;
    printf("n1 e n2: ");
    scanf("%d %d", &a, &b);
    
    if(a < b){
        a = a + b;
        b = a - b;
    }

    r = retornaMDC(&a, &b);

    printf("MDC = %d\n", r);

    return 0;
}
