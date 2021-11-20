#include "header.h"

int main(){
    int n, langkah;
    char arah[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        baris[i] = 0; kolom[i] = 0;
        scanf("%d%d", &baris[i], &kolom[i]);
        scanf("%d", &langkah);
        Hitung(arah, &i, langkah);
    }
    Tampil(n);
    return 0;
}