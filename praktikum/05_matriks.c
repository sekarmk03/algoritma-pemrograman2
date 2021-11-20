#include <stdio.h>

int main(){
    int baris, kolom, arah = 0, putar = 0;
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
    printf("======================================\n");
    printf("1. kanan\n2. kiri\n");
    printf("Tentukan arah (1/2) : ");
    scanf("%d", &arah);
    printf("Berapa putaran (1/2/3/4) : ");
    scanf("%d", &putar);
    printf("Hasil :\n");
    if((arah == 1 && putar == 1) || (arah == 2 && putar == 3)){
        for (int i = 0; i < kolom; i++)
        {
            for (int j = baris-1; j >= 0; j--)
            {
                printf("%d ", matriks[j][i]);
            }
            printf("\n");
        }
    } else if((arah == 1 && putar == 3) || (arah == 2 && putar == 1)){
        for (int i = kolom-1; i >= 0; i--)
        {
            for (int j = 0; j < baris; j++)
            {
                printf("%d ", matriks[j][i]);
            }
            printf("\n");
        }
    } else if(putar == 2){
        for (int i = baris-1; i >= 0; i--)
        {
            for (int j = kolom-1; j >= 0; j--)
            {
                printf("%d ", matriks[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                printf("%d ", matriks[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}