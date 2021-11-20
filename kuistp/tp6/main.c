#include "header.h"

int main(){
    int n1, n2, n3; // tampungan jumlah lagu dalam setiap daftar lagu

    /*
        * blok inputan
        * menginput jumlah lagu, deklarasi daftar lagu, memanggil prosedur input data lagu
        * ket. id lagu : lagu ibnu (x), lagu adik (y), lagu ayah (z)
    */
    scanf("%d", &n1); arrlist ibnu[n1]; input(ibnu, n1, 'x');
    scanf("%d", &n2); arrlist adik[n2]; input(adik, n2, 'y');
    scanf("%d", &n3); arrlist ayah[n3]; input(ayah, n3, 'z');

    arrlist result[n1+n2], final[n1+n2+n3]; // deklarasi array hasil penggabungan 1 dan 2

    // blok inputan metode sorting dan tipe sorting
    char method, type;
    scanf(" %c %c", &method, &type);

    /*
        * pengkondisian berdasarkan metode sort yang dipilih
        * ket. metode : insertion sort (i), selection sort (s), quick sort (q), bubble sort (b)
        * setiap metode sorting memiliki tipe sorting ascending (a) & descending (d)
        * langkah2 : - sorting data1 dan data2
                     - gabungkan data1 dengan data2, simpan ke array result
                     - sorting data3
                     - gabungkan data 3 dengan array result, simpan ke array final
    */
    if(method == 'i'){
        // jika memilih insertion sort
        insertion(ibnu, n1, type); insertion(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        insertion(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    } else if(method == 's'){
        // jika memilih selection sort
        selection(ibnu, n1, type); selection(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        selection(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    } else if(method == 'q'){
        // jika memilih quick sort
        quick(ibnu, 0, n1-1, type); quick(adik, 0, n2-1, type);
        merge(ibnu, adik, n1, n2, result, type);
        quick(ayah, 0, n3-1, type); merge(result, ayah, n1+n2, n3, final, type);
    } else{
        // jika memilih bubble sort
        bubble(ibnu, n1, type); bubble(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        bubble(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    }

    // mencetak hasil data terurut(array final) dan lagu ibnu yang diputar
    // sesuai spesifikasi soal
    output(final, n1+n2+n3, ibnu);
    return 0;
}