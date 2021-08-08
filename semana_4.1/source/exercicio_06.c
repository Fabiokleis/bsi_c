#include <stdio.h>

int main(){
    int n, j, max, ctr;
    char f, m;
    printf("n inteiro (maior que 0): ");
    scanf("%d", &n);
    
    for(j=n; j; --j){
        printf("digite um n inteiro: ");
        scanf("%d", &ctr);
        if(j == n){
            max = ctr;
        }
        if(ctr < max){
            f = 'B';
        }else if(ctr > max){
            m = 'A';
        }
        max = ctr;
    }

    if(f && !m){
        printf("Decrescente\n");
    }else if(m && !f){
        printf("Crescente\n");
    }else if(f && m){
        printf("Desordenada\n");         
    }
   

    return 0;    
}
