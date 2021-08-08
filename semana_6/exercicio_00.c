#include <stdio.h>

int quadra(int n, int *r);

int main(){
    int n, c, r;
    printf("n: ");
    scanf("%d", &n);
    
    r = quadra(n, &c);
    
    if(r){
        printf("%d^1/2 = %d.\n", n, c);
    }else{
        printf("não é quadrado perfeito.\n");
    }


    return 0;
}

int quadra(int n, int *c){
    int i, s=0;
    *c = 0;
    for(i=1; i <= n; i+=2){
        s += i;
        (*c)++;
        if(s == n){
            return 1;
        }
    }

    return 0;
}

