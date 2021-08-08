#include <stdio.h>

int main(){
    int i, n, s=0;

    printf("n inteiro: ");
    scanf("%d", &n);

    for(i = 1; (i*(i+1)*(i+2)) < n; i++);


    if((i*(i+1)*(i+2) == n)){
        printf("%d é triangular, pois %d*%d*%d = %d\n", n, i, i+1, i+2, n);
    }else{
        printf("%d nao é triangular\n", n);
    }


    return 0;
}
