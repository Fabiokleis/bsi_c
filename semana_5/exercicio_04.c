#include <stdio.h>

int main(){
    int n, i, ctr, s, k, p=0, j=0, ant=0, flag, flagPI;
    printf("n inteiro maior que 0: ");
    scanf("%d", &n);
    if(n <= 0){
        return 0;
    }
    for(i=0; i < n; i++){
        printf("digite um numero: ");
        scanf("%d", &ctr);
        
        if(ctr % 2 == 0){
            p++;
        }else{
            j++;
        }
        
        if(ant != ctr && j < p){
            k = p;
        }else if(ant != ctr && p > j){
            k = j;
        }

        ant = ctr;
        printf("p = %d e j = %d\n", p, j);
    }
    if(n % 2 == 0 && j != p){
        flag = 0;
    }

    if(flag){
        printf("a sequência é k-alternante, tendo k = %d\n", k);
    }else{
        printf("a sequência não é k-alternante\n");
    }

    return 0;
}
