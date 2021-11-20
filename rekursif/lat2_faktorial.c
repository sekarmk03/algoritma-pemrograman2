#include <stdio.h>

int FakLoop(int n){
    int i, hasil = 1;
    for(i = 2; i <= n; i++){
        hasil *= i;
    }
    return hasil;
}

int FakRek(int n){
    printf("Nilai n = %d\n", n);
    if(n == 0 || n == 1){
        return 1;
    } else {
        printf("%d x %d\n", n, FakRek(n - 1));
        return n * FakRek(n - 1);
    }
}

int main(){
    int n, hasilLoop, hasilRek;
    scanf("%d", &n);
    hasilLoop = FakLoop(n);
    hasilRek = FakRek(n);
    printf("Hasil Looping : %d\n", hasilLoop);
    printf("Hasil Rekursif : %d\n", hasilRek);
    return 0;
}