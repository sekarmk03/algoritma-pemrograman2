#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[100];
    char nilai[7];
} mahasiswa;

int idx;
int pKata;
char cKata[50];

void startKata(char pita[]);
void resetKata();
void incKata(char pita[]);
char *getCKata();
int getPKata();
int eopKata(char pita[]);
void insertData(char pita[], mahasiswa *data);
void deleteData(char pita[], mahasiswa data[]);
int findIdx(char str[], mahasiswa data[]);
void resetData(char str[]);