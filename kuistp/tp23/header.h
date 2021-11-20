#include <stdio.h>
#include <string.h>

typedef struct {
    char *nama[50];
    int *nilai[3];
    float *rataan;
}data;

// data dt[100][100];

int baris, kolom, jumlah, len[100][50], max[100];
char tukar[100][50];

void InputData(data *dt[100][100]);
void InputTukar();
void Swap(char namaKiri[], char namaKanan[], int x1, int y1, int x2, int y2, data *dt[100][100]);
void Cari(data *dt[100][100]);
void Max();
void Print(data *dt[100][100]);