#include <stdio.h>
#include <string.h>

int main(){
    int i, j=0, p=0, c=0; 
    char str[] = "ANA e MARIANA GOSTAM DE BANANA";
    char exp[] = "ANA";
    
    for(i=0; str[i] != '\0'; i++){
        if(str[i] == exp[j]){
            j++;
            if(exp[j+1] == '\0'){
                c++;
                j = 0;
            }
        }else{
            j = 0;
        }
    }

    printf("numero de ocorrencias da palavra ana: %d\n", c);
    return 0;
}


