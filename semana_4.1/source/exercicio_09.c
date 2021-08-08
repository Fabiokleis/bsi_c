#include <stdio.h>

int main(){

    int n, ctr, j, i, k, s=0;
    printf("t inteiro (maior que 0): ");
    scanf("%d", &n);
   
    for(j=1; j <= n; j++){
        printf("digite um t inteiro: ");
        scanf("%d", &ctr);
        k = 0;
        for(i=1; i <= ctr; i++){
            if(ctr % i == 0){
                k++;
            }
        }

        if(k == 2){
            s = s + ctr;
//            printf("%d\n", s);
        }

    }
   
    printf("a soma dos primos é %d;\n", s);
    return 0;
}
