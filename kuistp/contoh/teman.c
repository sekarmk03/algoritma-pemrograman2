#include <stdio.h>
#include <string.h>
typedef struct
{
    int NIM;
    char Nama[50];
    int Usia;
    char Kelas[50];
} Mahasiswa;
int main()
{
    Mahasiswa Aku;
    Mahasiswa Kamu;
    Mahasiswa Dia;

    printf("  Masukan Data Anda \n");
    printf("NIM \t \t : ");
    scanf("%d", &Aku.NIM);
    getchar() != '\n';

    printf("Nama Lengkap \t : ");
    gets(Aku.Nama);

    printf("Usia \t \t : ");
    scanf("%d", &Aku.Usia);
    getchar() != '\n';

    printf("Kelas \t \t : ");
    scanf(" %s", &Aku.Kelas);
    getchar() != '\n';
    printf("\n");

    //------------------------------------

    printf("  Masukan Data Teman Sebelah Kiri dan Kanan anda \n");
    printf("\n");
    printf("    Teman Sebelah Kiri \n");
    printf("NIM \t \t : ");
    scanf("%d", &Kamu.NIM);
    getchar() != '\n';

    printf("Nama Lengkap \t : ");
    gets(Kamu.Nama);

    printf("Usia \t \t : ");
    scanf("%d", &Kamu.Usia);
    getchar() != '\n';

    printf("Kelas \t \t : ");
    scanf(" %s", &Kamu.Kelas);
    getchar() != '\n';
    printf("\n");

    //--------------------------------------

    printf("    Teman Sebelah Kanan \n");
    printf("NIM \t \t : ");
    scanf("%d", &Dia.NIM);
    getchar() != '\n';

    printf("Nama Lengkap \t : ");
    gets(Dia.Nama);

    printf("Usia \t \t : ");
    scanf("%d", &Dia.Usia);
    getchar() != '\n';

    printf("Kelas \t \t : ");
    scanf(" %s", &Dia.Kelas);
    getchar() != '\n';
    printf("\n");

    //-----------------------------------------------
    printf("Berikut Data Mahasiswa Beserta Nama Teman Disebelah Kiri dan Kanannya dengan format = NIM - Nama - Usia - Kelas\n");
    printf("1. %d - %s - %d - %s \n", Aku.NIM, Aku.Nama, Aku.Usia, Aku.Kelas);
    printf("2. %d - %s - %d - %s \n", Kamu.NIM, Kamu.Nama, Kamu.Usia, Kamu.Kelas);
    printf("3. %d - %s - %d - %s \n", Dia.NIM, Dia.Nama, Dia.Usia, Dia.Kelas);

    return 0;
}