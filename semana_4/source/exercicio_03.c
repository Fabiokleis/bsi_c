#include <stdio.h>
#define PASS 2002

int main(){
    
    int passwd;

    while(passwd != PASS){
        printf("digite a senha: ");
        scanf("%d", &passwd);
        if(passwd == PASS){
            printf("Acesso Permitido\n");
        }else{
            printf("Senha Invalida\n");
        }
    }


    return 0;
}
