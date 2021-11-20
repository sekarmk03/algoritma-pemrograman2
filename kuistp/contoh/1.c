#include <stdio.h>

typedef struct
{
    int x, y;
} titik;

int segitiga(int *i, titik t[][4])
{
    printf("Masukkan 3 titik ABC (x y) :\n");
    printf("A dan C titik alas, B titik puncak.\n");
    for (int j = 0; j < 3; j++)
    {
        printf("   %d. ", j + 1);
        scanf("%d%d", &t[*i][j].x, &t[*i][j].y);
    }
    return (t[*i][2].x - t[*i][0].x) * (t[*i][1].y - t[*i][0].y) * 0.5;
}

int persegi(int *i, titik t[][4])
{
    printf("Masukkan 2 titik AC (x y) :\n");
    printf("A titik sudut kiri bawah, C titik sudut kanan atas.\n");
    for (int j = 0; j < 2; j++)
    {
        printf("   %d. ", j + 1);
        scanf("%d%d", &t[*i][j].x, &t[*i][j].y);
    }
    t[*i][2].y = t[*i][1].y;
    t[*i][2].x = t[*i][0].x;
    t[*i][3].y = t[*i][0].y;
    t[*i][3].x = t[*i][1].x;
    return (t[*i][1].x - t[*i][0].x) * (t[*i][1].y - t[*i][0].y);
}

int main()
{
    int n, m[100], i, j, pilih = 0;
    // n jumlah bidang
    // m
    printf("Masukkan jumlah bidang : ");
    scanf("%d", &n);
    float luas[n];
    titik t[n][4];
    for (i = 0; i < n; i++)
    {
        printf("Pilih bidang ke-%d :\n", i + 1);
        printf("1. Segitiga\n");
        printf("2. Persegi/persegi panjang\n");
        printf(">> Pilihan anda : ");
        scanf("%d", &pilih);
        luas[i] = 0;
        switch (pilih)
        {
        case 1:
            luas[i] = segitiga(&i, t);
            break;
        case 2:
            luas[i] = persegi(&i, t);
            break;
        default:
            printf("Bidang yang dipilih tidak tersedia.\n");
            break;
        }
    }
    int titik = 65;
    for (i = 0; i < n; i++)
    {
        titik = 65;
        printf("Bangun ke-%d\n", i + 1);
        for (j = 0; j < m[i]; j++)
        {
            printf("* Titik %c : (%d, %d)\n", titik, t[i][j].x, t[i][j].y);
            titik++;
        }
        printf("-> Luas bangun : %0.2f satuan\n", luas[i]);
    }
    return 0;
}