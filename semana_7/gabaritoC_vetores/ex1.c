#include<stdio.h>
#include<stdlib.h>
#define TAM 5 //definição de uma constante

main(){
    //declaração de variáveis
    int v[TAM], ind=0, i, num, valido=1;

    printf("Digite o valor que deve ser inserido no vetor: ");
    scanf("%d", &num);

    v[ind]= num;
    ind++;

    while(ind<TAM)
    {
        valido = 1;
        printf("Digite o valor que deve ser inserido no vetor: ");
        scanf("%d", &num);
        for(i=0;i<ind;i++)
        {
            if(num==v[i])
            {
               valido=0;
               break;
            }
        }
        if(valido==1)
        {
            v[ind]= num;
            ind++;
        }
        else
            printf("Valor repetido!!!\n");
    }
    for(i=0;i<TAM;i++)
      printf("v[%d]=%d\n", i,v[i]);
    return 0;
}






