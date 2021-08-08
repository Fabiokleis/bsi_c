#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcula_raizes(float a, float b, float c, float *x1, float *x2){
    double delta=0;

    delta = (b*b)+(-4*a*c);    
    if(delta >= 0){
       *x1 =  (-b+sqrt(delta))/(a*2);
       *x2 = (-b-sqrt(delta))/(a*2);
       printf("x1 = %f, x2 = %f\n", *x1, *x2);
       return 1;
    }

    return 0;
}

int main(){
    float a, b, c, x1, x2;
    int ret;
    printf("a b c: ");
    scanf("%f %f %f", &a, &b, &c);

    ret = calcula_raizes(a, b, c, &x1, &x2);

    if(!ret){
        printf("delta negativo.\n");
    }
    return 0;
}
