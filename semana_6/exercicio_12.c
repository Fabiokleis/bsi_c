#include <stdio.h>

int dig(int a, int b){
    int u, h, u2, h2, c=0;
    h = a;
    h2 = b;
    while(h && h2){
        u = h % 10;
        u2 = h2 % 10;
        h /= 10;
        h2 /= 10;
        if(u != u2) break;
        c++;
    }
    if(c){
        return 1;
    }

    return 0;
}

int main(){
    int a, b, ret;
    printf("a e b: ");
    scanf("%d %d", &a, &b);
    ret = dig(a, b);

    if(ret){
        printf("sim\n");
    }else{
        printf("nao\n");
    }

    return 0;
}
