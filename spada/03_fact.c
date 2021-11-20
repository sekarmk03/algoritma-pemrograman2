#include <stdio.h>

int faktorial(int n){
    printf("n = %d\n", n);
    if(n == 0 || n == 1){
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}

int main(){
    int hasil = faktorial(5);
    printf("hasil : %d\n", hasil);
    return 0;
}