#include <stdio.h>

int verificaAnoBiss(int ano){
    
    if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) return 1;
    return 0;
}

int main(){
    int ano, ret; 
    printf("n inteiro > 0: ");
    scanf("%d", &ano);
    ret = verificaAnoBiss(ano);
    
    printf("%d\n", ret);

    return 0;
}
