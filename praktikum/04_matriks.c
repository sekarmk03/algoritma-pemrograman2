#include <stdio.h>

int main(){
    int baris, kolom;
    printf("Baris : "); scanf("%d", &baris);
    printf("Kolom : "); scanf("%d", &kolom);
    int matriks[baris][kolom];
    printf("Masukkan elemen matriks %d x %d :\n", baris, kolom);
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("Refleksi :\n");
    for (int i = 0; i < baris; i++)
    {
        for (int j = kolom - 1; j >= 0; j--)
        {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
    return 0;
}