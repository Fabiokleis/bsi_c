#include <stdio.h>

int main(){
    int m, s=1, j=0, k=0;

    printf("insira um valor inteiro: ");
    scanf("%d", &m);

    for(j=1; j <= m; j++){
        printf("%d^3 = ", j);
        for(k=0; k < j; k++){
            printf("+%d", s);
            s = s + 2;
        }
        printf(",\n");
    }

    return 0;
}
