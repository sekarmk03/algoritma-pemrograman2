/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP1 - MTT121
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*=== Library ===*/
#include "header.h"

/*=== Fungsi Utama ===*/
int main(){
    scanf("%d%d", &baris, &kolom); // -----------------> meminta masukan nilai baris dan kolom
    // variabel lokal
    int matriks[100][100], cek = 0;
    // --------------------^ menampung nilai fungsi Cek
    // -^ menampung matriks awal
    for (int i = 0; i < baris; i++) { // --------------> diulang sebanyak baris
        for (int j = 0; j < kolom; j++) { // ----------> diulang sebanyak kolom
            scanf("%d", &matriks[i][j]); // -----------> meminta masukan elemen pengisi matriks
        }
    }
    // memanggil prosedur pengolah
    Pindah(matriks); // -------------------------------> menyimpan matriks awal ke temp
    RefVer(); // --------------------------------------> refleksi matriks vertikal
    Trans(); // ---------------------------------------> transpose matriks hasil refleksi
    Rotasi(); // --------------------------------------> dirotasi sesuai spesifikasi
    // menampilkan hasil pengolahan
    for (int i = 0; i < baris; i++) { // --------------> diulang sebanyak baris
        for (int j = 0; j < kolom; j++) { // ----------> diulang sebanyak kolom
            printf("%d", hasil[i][j]); // -------------> mencetak elemen matriks hasil
            if(j < kolom-1){ // -----------------------> jika belum mencapai kolom terakhir
                printf(" "); // -----------------------> cetak spasi, pembatas antar elemen dlm baris
            }
        }
        printf("\n"); // ------------------------------> cetak baris baru
    }
    cek = Cek(matriks); // ----------------------------> pengecekan kesamaan elemen, menyimpan nilai fungsi Cek
    if(cek == 0){ // ----------------------------------> jika elemen matriks awal-akhir ada yg berbeda
        printf("Wihh matrix yang seru!\n"); // --------> cetak ini ke layar
    } else { // ---------------------------------------> jika elemen matriks awal-akhir sama semua
        printf("Coba lagi besok!\n"); // --------------> cetak ini ke layar
    }
    return 0; // --------------------------------------> fungsi utama berakhir, program selesai
}