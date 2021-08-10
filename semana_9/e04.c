#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float p[3];
    float M;
}Provas;

typedef struct {
    int ra;
    int frequencia;
    Provas Ps;
}Aluno;

int main(void) {
    int n,i,j;
    float desvios_Ps[3]={0.0, 0.0, 0.0}, medias_Ps[3]={0.0, 0.0, 0.0};
    printf("ENTRADA: ");
    scanf("%d", &n);
    /* COMPLETE AQUI */
    Aluno *vetAlunos = (Aluno*) malloc(n*sizeof(Aluno));
    for(i=0; i < n; i++){
        printf("RA: ");
        scanf("%d", &vetAlunos[i].ra);
        for(j=0; j < 3; j++){
            printf("notas[%d]: ", j);
            scanf("%f", &vetAlunos[i].Ps.p[j]);
            vetAlunos[i].Ps.M += (vetAlunos[i].Ps.p[j]/3);
        }
        for(j=0; j < 3; j++){
            medias_Ps[j] += (vetAlunos[i].Ps.p[j]/3); // m[N] += a[C]p[N]; 
        }
    }
    for(i=0; i < n; i++){
        for(j=0; j < 3; j++){
            desvios_Ps[j] += pow((vetAlunos[i].Ps.p[j]) - medias_Ps[j], 2)/3; // d[N] = ((a[C]p[N] - m[N])^2)/3; ai falta a raiz ^1/2...
        }
    }

    for(i=0; i < 3; i++){
        desvios_Ps[i] = sqrt(desvios_Ps[i]); // raiz
    }

    printf("SAIDA:\n");
    for(i=0; i < n; i++){
        printf("RA: %d\n", vetAlunos[i].ra);
        for(j=0; j < 3; j++){
            printf("Prova[%d]: %f\n", j, vetAlunos[i].Ps.p[j]);
        }
        printf("Média: %f\n", vetAlunos[i].Ps.M);
        printf("------------------\n");
    }

    for(i=0; i < 3; i++){
        printf("Média geral P%d: %f\n", i, medias_Ps[i]);
        printf("Desvio padrão: P%d: %f\n", i, desvios_Ps[i]);
    }

    return 0;
}
