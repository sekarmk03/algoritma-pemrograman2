#include <stdio.h>

int power(int x, int y){
    int hasil;
    if(y == 0){
        printf("y = 0, return 1\n");
        return 1;
    } else {
        printf("x : %d, y : %d\n", x, y);
        hasil = x * power(x, y-1);
        printf("hasil : %d\n", hasil);
    }
    return hasil;
}

int main(){
    int hasil = power(2, 3);
    printf("hasil akhir : %d\n", hasil);
    return 0;
}