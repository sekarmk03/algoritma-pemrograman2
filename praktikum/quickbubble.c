#include <stdio.h>
typedef struct 
{
    int no;
    char nama[50], tipe[20];
}daftar;

void swap(daftar *awal, daftar *akhir){
    daftar temp;
    temp = *awal;
    *awal = *akhir;
    *akhir = temp;
}

void bubbleSort(daftar data[], int n){
    int i, temp, pindah;
    do{
        pindah = 0;
        for ( i = 0; i < n-1; i++){
            if (data[i].no > data[i+1].no){
                swap(&data[i], &data[i+1]);
                pindah = 1;
            }
        }
    } while (pindah == 1);
}

void qsTengah(daftar data[], int kiri, int kanan){
    int i, j, temp;
    i = kiri; j = kanan;
    int pivot = data[(kanan + kiri) / 2].no;
    do{
        while (data[i].no < pivot && i <= j){
            i++;
        }
        while (data[j].no > pivot && i <= j){
            j--;
        }
        if(i < j){
            swap(&data[i], &data[j]);
            i++; j--;
        }
    } while (i < j);
    if((kiri < j) && (j < kanan)){
        qsTengah(data, kiri, j);
    }
    if((i < kanan) && (i > kiri)){
        qsTengah(data, i, kanan);
    }
}

int main(){
    int n;
    char sortType;
    scanf(" %c %d", &sortType, &n);
    daftar data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%s", &data[i].no, data[i].nama, data[i].tipe);
    }
    if(sortType == 'B'){
        bubbleSort(data, n);
    } else {
        qsTengah(data, 0, n-1);
    }
    for (int i = 0; i < n; i++){
        printf("No Tempat Duduk : %d\n", data[i].no);
        printf("Nama : %s\n", data[i].nama);
        printf("Tipe : %s\n", data[i].tipe);
        if(i < n-1){
            printf("\n");
        }
    }
    return 0;
}