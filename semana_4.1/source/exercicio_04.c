#include <stdio.h>

int main(){
    int n, i, j;
    printf("n interio (maior que 0): ");
    scanf("%d", &n);
   
    for(i=1; i <= n; i++){
        printf("%d ", i);
        for(j=1; j <= i; j++){
            printf("%d ", i*j);
        }
        printf("\n");
    }

    return 0;
}
