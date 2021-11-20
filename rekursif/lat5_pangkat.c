#include <stdio.h>

int Pangkat(int x, int y){
    int hasil;
    if(y == 0) {
        return 1;
    } else {
        hasil = x * Pangkat(x, y - 1);
        return hasil;
    }
}

int main(){
    int bil, pangkat, hasil;
    scanf("%d%d", &bil, &pangkat);
    hasil = Pangkat(bil, pangkat);
    printf("Hasil dari %d^%d adalah %d\n", bil, pangkat, hasil);
    return 0;
}