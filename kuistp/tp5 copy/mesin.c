#include "header.h"

void swap(pecahan *awal, pecahan *akhir){
    pecahan temp;
    temp = *awal;
    *awal = *akhir;
    *akhir = temp;
}

void bubbleSort(pecahan frac[], int n, char by){
    int i, tukar;
    do{
        tukar = 0;
        for ( i = 0; i < n-1; i++){
            if(by == 'a'){
                if (frac[i].hasil > frac[i+1].hasil){
                    swap(&frac[i], &frac[i+1]);
                    tukar = 1;
                }
            } else {
                if (frac[i].hasil < frac[i+1].hasil){
                    swap(&frac[i], &frac[i+1]);
                    tukar = 1;
                }
            }
        }
    } while (tukar == 1);
}

void qsTengah(pecahan frac[], int kiri, int kanan, char by){
    int i = kiri, j = kanan;
    double pivot = frac[(kanan + kiri) / 2].hasil;
    do{
        if(by == 'a'){
            while (frac[i].hasil < pivot && i <= j)
                i++;
            while (frac[j].hasil > pivot && i <= j)
                j--;
        } else {
            while (frac[i].hasil > pivot && i <= j)
                i++;
            while (frac[j].hasil < pivot && i <= j)
                j--;
        }
        if(i < j){
            swap(&frac[i], &frac[j]);
            i++; j--;
        }
    } while (i < j);
    if((kiri < j) && (j < kanan))
        qsTengah(frac, kiri, j, by);
    if((i < kanan) && (i > kiri))
        qsTengah(frac, i, kanan, by);
}

void cetak(pecahan frac[], int n){
    for (int i = 0; i < n; i++){
        printf("%.0lf", frac[i].num);
        if(i < n-1)
            printf("   ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("-");
        if(i < n-1)
            printf(" , ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%.0lf", frac[i].den);
        if(i < n-1)
            printf("   ");
    }
    printf("\n");
}