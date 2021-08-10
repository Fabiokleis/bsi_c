#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[5] = { 0 };
    int i, j;
    char str[50];
    char vogais[10] = "aeiouAEIOU";
    fgets(str, 50, stdin);
    
    for(i=0; str[i] != '\0'; i++){
        for(j=0; j < 10; j++){
             if(vogais[j] == str[i]){
                if(vogais[j] == 'a' || vogais[j] == 'A'){
                    v[0]++;
                }else if(vogais[j] == 'e' || vogais[j] == 'E'){
                    v[1]++;
                }else if(vogais[j] == 'i' || vogais[j] == 'I'){
                    v[2]++;
                }else if(vogais[j] == 'o' || vogais[j] == 'O'){
                    v[3]++;
                }else if(vogais[j] == 'u' || vogais[j] == 'U'){
                    v[4]++;
                }
             }
        }
    }

    for(i=0; i < 5; i++){
        printf("%c: ", vogais[i]);
        for(j=0; j < v[i]; j++){
            printf("*");
        }
        printf(" (%d)\n", v[i]);
    }
    return 0;
}
