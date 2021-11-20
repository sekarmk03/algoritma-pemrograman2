#include "header.h"

int main(){
    data dt[100][100];
    scanf("%d%d", &baris, &kolom);
    InputData(&dt);
    InputTukar();
    printf("Posisi Bangku Awal:\n");
    Print(&dt);
    Cari(&dt);
    printf("\nPosisi Bangku Setelah Nilai Dicek:\n");
    Print(&dt);
    return 0;
}