#include <stdio.h>
#include <math.h>

int main(){
    double pi=0;
    int n, k;
    printf("n: ");
    scanf("%d", &n);

    for(k=0; k <= n; k++){
        pi += (pow(-1, k))/(double)((2*k)+1);
        printf("%f\n", pi);
    }
    
    printf("%.15lf\n", pi*4);

    return 0;
}
