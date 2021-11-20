#include <stdio.h>

void bubbleSort(int data[], int n){
    int i, temp, pindah;
    // perulangan sampai seluruh data tidak ada yang ditukar
    do
    {
        // tanda terjadi pertukaran data
        pindah = 0;
        // cek semua data
        for ( i = 0; i < n-1; i++)
        {
            // jika data ke-i > data ke-i+1
            if (data[i] > data[i+1])
            {
                // tukar data
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                // tandai pertukaran
                pindah = 1;
            }
        }
    } while (pindah == 1);
}

void printData(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        if(i != n-1)
        {
            printf("%d ", data[i]);
        }
        else
        {
            printf("%d\n", data[i]);
        }
    }   
}

int main(){
    int data[] = {64, 34, 25, 12, 22, 90, 11};
    int n = 7;
    // cetak data awal
    printf("Data Awal\n");
    printData(data, n);
    // panggil prosedur bubble sort
    bubbleSort(data, n);
    // cetak data akhir
    printf("\nData Akhir\n");
    printData(data, n);
    return 0;
}