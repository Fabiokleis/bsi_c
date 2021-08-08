#include <stdio.h>

int testaTipoChar (char c);

int main()
{
    int resp;
    char caracter;

    printf("Digite o caracter: ");
    scanf("%c", &caracter);

    resp = testaTipoChar(caracter);

    if(resp == 1)
        printf("Letra maiuscula!");
    else if(resp == 2)
        printf("Letra minuscula!");
    else if(resp == 3)
        printf("Digito entre 0 e 9!");
    else
        printf("Nao eh possivel determinar");

    return 0;

}

int testaTipoChar (char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else if (c >= 'a' && c <= 'z')
        return 2;
    else if (c >= '0' && c <= '9')
        return 3;
    else
        return 0;



}
