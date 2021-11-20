#include "header.h"

void Hitung(char arah[], int *i, int langkah){
    for (int j = 0; j < langkah; j++)
    {
        scanf("%s%d", arah, &jalan);
        if(strcmp(arah, "horizontal") == 0){
            baris[*i] += jalan;
        } else if(strcmp(arah, "-horizontal") == 0){
            baris[*i] -= jalan;
        } else if(strcmp(arah, "vertikal") == 0){
            kolom[*i] += jalan;
        } else if(strcmp(arah, "-vertikal") == 0){
            kolom[*i] -= jalan;
        } else if(strcmp(arah, "miring") == 0){
            kolom[*i] += jalan;
            baris[*i] += jalan;
        } else {
            kolom[*i] -= jalan;
            baris[*i] -= jalan;
        }
    }
}

void Tampil(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", baris[i], kolom[i]);
    }
}