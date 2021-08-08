#include <stdio.h>

int main(){
    
    int k, n, i=0, j=1, d=0;

    printf("k e n: ");
    scanf("%d %d", &k, &n);

    
    if((k > 0) && (n > 0)){
        for(i=k; i <= n; i++){
            d = 0;    
            for(j=1; j <= i; j++){
                if(i % j == 0){
                    d++;
                }
            }
            if(d == 2){
                printf("%d ", i);
            }
     
        }      
        printf("\n");
    }
    return 0;
}
