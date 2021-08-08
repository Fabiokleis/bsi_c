#include <stdio.h>


int main(){
    int n, m, j, k;
    printf("Entre com n e m (maiores que 0): ");
    scanf("%d %d", &n, &m);

    for(j=1; j <= n; j++){
        for(k=1; k <= m; k++){
            printf("%2d ", k*j);
        }
        printf("\n");
    }


    return 0;
}
