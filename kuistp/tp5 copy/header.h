#include <stdio.h>

typedef struct {
    double num, den, hasil;
}pecahan;

void swap(pecahan *awal, pecahan *akhir);
void bubbleSort(pecahan frac[], int n, char by);
void qsTengah(pecahan frac[], int kiri, int kanan, char by);
void cetak(pecahan frac[], int n);