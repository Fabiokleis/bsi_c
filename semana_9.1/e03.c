#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j=0, tmp=0, tmp2=0, k;
    char f1[100];
    char f2[100];
    char intercala[200];

    printf("frase1[%d]: ", 100);
    fgets(f1, 100, stdin);
    printf("frase2[%d]: ", 100);
    fgets(f2, 100, stdin);

    for(i=0; f1[i] != '\0' || f2[i] != '\0'; i++){
       
        if((int)f1[i] == 32 || (int)f1[i+1] == '\0'){
            for(j=j; j < i; j++){
                intercala[j+k] = f1[j];
                printf("%c", intercala[j+k]);
            }
            tmp = j;
        }
        
        if((int)f2[i] == 32 || (int)f2[i+1] == '\0'){
            for(k=k; k < i; k++){
                intercala[j+k] = f2[k];
                printf("%c", intercala[j+k]);
            }
            tmp2 = k;
        }
        printf("%s\n", intercala);
    }

   // printf("%s", f1);
  //  printf("%s", f2);
    printf("\n\n%s", intercala);

    return 0;
}
