#include <stdio.h>

int sum(int n){
    printf("n = %d\n", n);
    if(n == 1){
        return 1;
    } else {
        printf("-> sum(%d)\n", n-1);
        return n + sum(n-1);
    }
}

int main(){
    int hasil = sum(5);
    printf("hasil : %d\n", hasil);
    return 0;
}