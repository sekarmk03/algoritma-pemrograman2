#include <stdio.h>

int main(){
    int baris1 = 0, kolom1 = 0, baris2 = 0, kolom2 = 0;
    printf("Baris dan kolom matriks pertama:\n");
    scanf("%d%d", &baris1, &kolom1);
    int matriks1[baris1][kolom1];
    printf("Elemen matriks pertama:\n");
    for (int i = 0; i < baris1; i++)
    {
        for (int j = 0; j < kolom1; j++)
        {
            scanf("%d", &matriks1[i][j]);
        }
    }
    printf("Baris dan kolom matriks kedua:\n");
    scanf("%d%d", &baris2, &kolom2);
    int matriks2[baris2][kolom2];
    printf("Elemen matriks pertama:\n");
    for (int i = 0; i < baris2; i++)
    {
        for (int j = 0; j < kolom2; j++)
        {
            scanf("%d", &matriks2[i][j]);
        }
    }
    for (int i = 0; i < baris1; i++)
    {
        /* code */
    }
    

    return 0;
}