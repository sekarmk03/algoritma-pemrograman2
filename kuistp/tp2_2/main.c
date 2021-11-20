#include "header.h"

int main(){
    // data dt[100][100];
    scanf("%d%d", &baris, &kolom);
    InputData();
    InputTukar();
    printf("Posisi Bangku Awal:\n");
    Print();
    Cari();
    printf("\nPosisi Bangku Setelah Nilai Dicek:\n");
    Print();
    return 0;
}