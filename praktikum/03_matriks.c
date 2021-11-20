#include <stdio.h>

int main(){
    int baris, kolom;
    printf("Masukkan baris dan kolom : (baris kolom)\n");
    scanf("%d%d", &baris, &kolom);
    int matriks[baris][kolom];
    printf("Masukkan elemen matriks %d x %d\n", baris, kolom);
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("Hasil transpose :\n");
    for (int i = 0; i < kolom; i++)
    {
        for (int j = 0; j < baris; j++)
        {
            printf("%d ", matriks[j][i]);
        }
        printf("\n");
    }
    return 0;
}