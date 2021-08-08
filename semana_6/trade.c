#include <stdio.h>

void invertValues(int *a, int *b){
    
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

    printf("a = %d, b = %d\n", *a, *b);
}

int main(){
    int a, b;
    printf("a e b: ");
    scanf("%d %d", &a, &b);
    invertValues(&a, &b);

    return 0;
}
