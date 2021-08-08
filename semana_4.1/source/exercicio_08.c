#include <stdio.h>

int main(){
    int n, j, r=0, rn=0;
    char f;
    printf("n inteiro: ");
    scanf("%d", &n);
    rn = n % 10;
    while(n){
        r = n % 10;
        if(r != rn){
            f = 'D';
            break;
        }
        n = n/10;
    }    
    
    if(f == 'D'){
        printf("Nao tem todos os dígitos iguais;\n");
    }else{
        printf("Tem todos os digitos iguais;\n");
    }
    


    return 0;
}
