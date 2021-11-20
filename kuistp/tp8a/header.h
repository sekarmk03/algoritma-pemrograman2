#include <stdio.h>
#include <string.h>

typedef struct 
{
    char judul[50];
    char sutradara[50];
    char genre[20];
    char bioskop[20];
}dataFilm;

typedef struct 
{
    char kode[10];
    char definisi[30];
}dataKode;

int readFile(FILE *file, dataKode d[]);
void fileOpen(FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop);
int search(char search[], dataKode data[], int n);
void fileClose(FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop);