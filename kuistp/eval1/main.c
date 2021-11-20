#include "header.h"

int main(){
    int n1, n2; // deklarasi var penanda banyak data

    /*
        * blok masukan
        * meminta masukan banyak data
        * inisialisasi array of struct
        * panggil prosedur input data array
    */
    scanf("%d", &n1); mhs mhs1[n1]; input(mhs1, n1);
    scanf("%d", &n2); mhs mhs2[n2]; input(mhs2, n2);

    // sorting array1 dan array2
    quick(mhs1, 0, n1-1); quick(mhs2, 0, n2-1);

    // inisialisasi array hasil gabungan
    mhs result[n1+n2];

    // menggabungkan dua array terurut
    merge(mhs1, mhs2, n1, n2, result);

    /*
        * blok keluaran
        * argumen yang dimasukkan menyesuaikan spesifikasi soal
        * (nama_array, ukuran_array, index_awal)
    */
    output(result, n1+n2, 0);
    output(result, (n1+n2)/2, 0);
    output(result, n1+n2, (n1+n2)/2);
    return 0;
}