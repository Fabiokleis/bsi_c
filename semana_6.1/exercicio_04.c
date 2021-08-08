#include <stdio.h>

int mmc(int *m, int *n){
    int i, j, gt, s=0, c=0;
    if(*m > *n){
        gt = *m;
    }else{
        gt = *n;
    }
    for(i=2; i <= gt && (*m || *n); i++){
       c = 0;    
       for(j=1; j <= i; j++){
           if(i % j == 0){
               c++;
            }
       }
       if(c == 2){
           *m = *m / i;
           *n = *n / i;
           s = s * i;
           printf("%d %d %d\n", *n, *m, i);
       }
    }      
   
    printf("%d\n", s);
    return 0;
}

int main(){
    int n, m, ret;
    printf("n e m: ");
    scanf("%d %d", &n, &m);

    ret = mmc(&m, &n);

    return 0;
}
