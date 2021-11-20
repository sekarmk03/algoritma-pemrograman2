#include <stdio.h>

int main(){
    int baris, kolom, bilangan;
    scanf("%d%d", &baris, &kolom);
    int matriks[baris][kolom];
    printf("Matriks : \n");
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("Dikali dengan : \n");
    scanf("%d", &bilangan);
    printf("Hasil :\n");
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("%d ", matriks[i][j] * bilangan);
        }
        printf("\n");
    }
    return 0;
}