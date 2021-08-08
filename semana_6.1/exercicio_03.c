#include <stdio.h>
#include <math.h>

void convertHora(int total_segundos, int *hora, int *min, int *seg){
    *hora = (total_segundos/3600);
    *min = (total_segundos/60)%60;
    *seg = (total_segundos%60);
    printf("%02d:%02d:%02d\n", *hora, *min, *seg);
}

int main(){
    int total_segundos, hora, min, seg;
    printf("tempo em segundos: ");
    scanf("%d", &total_segundos);
    
    convertHora(total_segundos, &hora, &min, &seg);


    return 0;
}
