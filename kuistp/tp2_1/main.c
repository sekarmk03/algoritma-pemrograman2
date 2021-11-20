/*=== Library ===*/
#include "header.h"

/*=== Fungsi Utama ===*/
int main(){
    // data dt[100][100];
    scanf("%d%d", &baris, &kolom); //----------------------> meminta 2 inputan tipe integer
    InputData(); //----------------------------------------> memanggil prosedur InputData < mesin.c line 5 - 23 >
    int jumlah = InputTukar(); //--------------------------> menyimpan nilai kembalian fungsi InputTukar < mesin.c line 25 - 39 >
    printf("Posisi Bangku Awal:\n");
    Print(); //--------------------------------------------> memanggil fungsi pencetak isi matriks Print < mesin.c line 142 - 168 >
    Proses(jumlah); //-------------------------------------> memanggil prosedur pemrosesan pertukaran elemen matriks < mesin.c line 72 - 118 >
    printf("\nPosisi Bangku Setelah Nilai Dicek:\n");
    Print(); //--------------------------------------------> memanggil fungsi pencetak isi matriks Print < mesin.c line 142 - 168 >
    return 0;
}