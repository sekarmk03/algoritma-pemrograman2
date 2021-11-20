#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    int harga;
    float rating;
}data;

data d[100];

char type[50];
void swap(int i, int idx);
void insNama(int *j, char temp[]);
void insHarga(int *j, int tempHarga);
void insRating(int *j, float tempRating);
void ins(int n, char sortBy[]);
void sel(int n, char sortBy[]);
void cetak(int n);