#include <stdio.h>

int carifpb(int a, int b){
    if(b == 0){
        printf("-> return %d\n", a);
        return a;
    } else {
        int temp = a % b;
        printf("1. a = %d  b = %d\n", a, b);
        printf("2. a = %d  b = %d\n", b, temp);
        return carifpb(b, temp);
    }
}

int main(){
    int hasil = carifpb(18, 12);
    printf("hasil : %d\n", hasil);
    return 0;
}