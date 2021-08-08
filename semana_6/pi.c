#include <stdio.h>

// Leibniz
// 1 - 1/3 + 1/5 - 1/7 + 1/9 - ... pi/4

double aproximaPi(int nTermos){
    printf("%d\n", nTermos);
    int i, j=0;
    double pi=0, k=0;
   
    for(i=3; j < nTermos; i+=2){
        j++;
        k = (double)1/i;
        if(j % 2){
            k = -1*k;
        }
        pi = pi + k; 
    }
    pi = (pi+1)*4;
    return pi;
}

int main(){
    int nT;
    double ret;
    printf("n termos: ");
    scanf("%d", &nT);
    
    ret = aproximaPi(nT);

    printf("%.15lf\n", ret);

    return 0;
}
