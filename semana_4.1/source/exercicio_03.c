#include <stdio.h>

int main(){
    int n, i, j, fdx=0;
    printf("n inteiro (maior que 0): ");
    scanf("%d", &n);

    for(j=-n; j <= n; j++){
        printf("%d", j);
        fdx = (j*j) + j + 1;
        for(i=0; i < fdx; i++){
            printf(".");
        }
        printf("*\n");
    }

    return 0;
}
