#include <stdio.h>

int main(){
    int baris, kolom, bilang, brs = 0, klm = 0;
    scanf("%d%d", &baris, &kolom);
    int matriks[baris][kolom];
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("Angka yang dicari : ");
    scanf("%d", &bilang);
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            if (matriks[i][j] == bilang)
            {
                klm = j;
                brs = i;
            }
        }
    }
    printf("Baris = %d\nKolom = %d\n", brs, klm);
    return 0;
}