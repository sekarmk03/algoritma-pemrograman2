#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[100];
    char nilai[7];
} mahasiswa;

int index;
int panjangKata;
char currentKata[50];

void startKata(char pita[]);
void resetKata();
void incKata(char pita[]);
char *getPanjangKata();
int eopKata(char pita[]);
void insertData(char pita[], mahasiswa *data);

int main()
{
    int n, i;
    char pita[200];
    printf("Masukkan banyak data :\n");
    scanf("%d", &n);

    mahasiswa dataMhs[n];

    for (i = 0; i < n; i++)
    {
        scanf(" %199[^\n]s", pita);

        insertData(pita, &dataMhs[i]);
    }
    printf("Data Mahasiswa :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. %s %s %s\n", i + 1, dataMhs[i].nim, dataMhs[i].nama, dataMhs[i].nilai);
    }
    return 0;
}

void startKata(char pita[])
{
    index = 0;
    panjangKata = 0;
    while (pita[index])
    {
    }
}