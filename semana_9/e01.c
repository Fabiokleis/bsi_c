#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int horas;
    int minutos;
    int segundos;
} Tempo;

Tempo convert(int seg);

int main(){
    int seg;
    Tempo ret;
    printf("segundos: ");
    scanf("%d", &seg);
    ret = convert(seg);
    printf("\n%.2d:%.2d:%.2d\n", ret.horas, ret.minutos, ret.segundos);
}

Tempo convert(int seg){
    Tempo tt;
    tt.horas = seg/3600;
    tt.minutos = (seg/60)%60;
    tt.segundos = seg%60;
    return tt;
}
