#include <stdio.h>

int Sum(int n){
    printf("n = %d\n", n);
    if(n == 1) {
        return 1;
    } else {
        return n + Sum(n - 1);
    }
}

int main(){
    int n, hasil;
    scanf("%d", &n);
    hasil = Sum(n);
    printf("Hasil penjumlahan = %d\n", hasil);
    return 0;
}