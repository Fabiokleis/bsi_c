#include <stdio.h>

int main(){
    int n, j, max=0, ctr;
    char f;
    printf("n inteiro: ");
    scanf("%d", &n);
    
    for(j=0; j < n; j++){
        printf("digite um n inteiro: ");
        scanf("%d", &ctr);
        if(max <= ctr){
            max = ctr;
        }else{
            f = 'N';
        }
    }

    if(f == 'N'){
        printf("Não\n");
    }else{
        printf("Sim\n");
    }

}
