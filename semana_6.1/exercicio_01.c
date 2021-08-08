#include <stdio.h>
#include <stdlib.h>

void questao01(int *a, int *b){
    *a = *a - *b;
    *b = *b - *a;
}

int main(){
    int a, b;
    printf("a b inteiros: ");
    scanf("%d %d", &a, &b);

    questao01(&a, &b);
    
    printf("a e b, %d %d\n", a, b);
    return 0;
}
