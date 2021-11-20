#include <stdio.h>
#include <string.h>

typedef struct
{
    char hari[20];
    int tanggal;
    int bulan;
    int tahun;
} Kalender;

int main()
{
    Kalender Kemarin; // ini variabel
    strcpy(Kemarin.hari, "Senin");
    Kemarin.tanggal = 7;
    Kemarin.bulan = 6;
    Kemarin.tahun = 2021;

    printf("Kalender Kemarin : %s , %d-%d-%d,\n", Kemarin.hari, Kemarin.tanggal, Kemarin.bulan, Kemarin.tahun);

    Kalender Today;
    strcpy(Today.hari, "Selasa");
    Today.tanggal = 8;
    Today.bulan = 6;
    Today.tahun = 2021;
    printf("Kalender Hari ini : ");
    printf("%s, %d-%d-%d\n", Today.hari, Today.tanggal, Today.bulan, Today.tahun);

    Kalender Besok;
    strcpy(Besok.hari, "Rabu");
    Besok.tanggal = 9;
    Besok.bulan = 6;
    Besok.tahun = 2021;
    printf("Kalender Besok : ");
    printf("%s, %d-%d-%d\n", Besok.hari, Besok.tanggal, Besok.bulan, Besok.tahun);
    printf("\n");
    printf("Reginald Piesta Direja - 2006298\n");
    printf("Pendidikan Ilmu Komputer B\n");
    return 0;
}