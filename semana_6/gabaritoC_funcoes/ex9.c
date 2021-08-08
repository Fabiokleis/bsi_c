float calculaIMC(float peso, float altura);
void imprimeIMC(float imc);

int main ()
{
    float peso, altura, indice;

    printf ("Peso: ");
    scanf ("%f", &peso);
    printf ("Altura (formato x.xx): ");
    scanf ("%f", &altura);

    indice = calculaIMC(peso, altura);
    imprimeIMC(indice);

    return 0;
}

float calculaIMC(float peso, float altura)
{
    float imc;

    // Aplicação direta da fórmula.
    imc = peso / (altura * altura);

    return imc;

    // lembre-se que poderíamos fazer direto
    //return peso / (altura * altura);
}

void imprimeIMC(float imc)
{
    // Vê em qual dos casos o imc se enquadra e imprime o resultado
    if (imc < 18.5)
        printf ("Voce esta abaixo do peso.\n");
    else if (imc < 25)
        printf ("Voce esta com o peso normal.\n");
    else if (imc < 30)
        printf ("Voce esta acima do peso.\n");
    else
        printf ("Voce esta obesa (o).\n");
}
