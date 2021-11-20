#include "header.h"

int main(){
    int n; char type, by;
    //----------------^penanda ascending/descending
    //----------^tipe sorting (bubble/quick)
    //--^banyaknya data
    scanf("%d", &n); // masukan n
    pecahan frac[n];
    //------^array of struct
    for (int i = 0; i < n; i++){
        frac[i].hasil = 0;
        // input data
        scanf(" %lf %lf", &frac[i].num, &frac[i].den);
        // hitung nilai numerator / denominator
        // agar bisa dibandingkan nilainya
        frac[i].hasil = (double)frac[i].num / frac[i].den;
    }
    scanf(" %c %c", &type, &by); // masukan tipe sorting dan a/d
    // pemilihan tipe sorting
    if(type == 'b'){
        // memanggil prosedur bubble sort
        bubbleSort(frac, n, by);
    } else {
        // memanggil prosedur quick sort
        qsTengah(frac, 0, n-1, by);
    }
    // mencetak data setelah diurutkan
    cetak(frac, n);
    return 0;
}