/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP1 - MTT121
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*=== Library ===*/
#include <stdio.h>

/*=== Var Global ===*/
int baris, kolom, jumlah, hasil[100][100], temp[100][100];
// ----------------------------------------^ menyimpan elemen matriks sementara
// -----------------------^ menampung matriks hasil operasi
// ---------------^ hasil penjumlahan elemen matriks kolom terakhir
// --------^ banyak kolom
// -^ banyak baris

/*=== Prosedur & Fungsi ===*/
void Pindah(int matriks[][100]); // ---> Prosedur memindah elemen matriks ke array temp
void RefVer(); // ---------------------> Prosedur refleksi matriks secara vertikal
void RefHor(); // ---------------------> Prosedur refleksi matriks secara horizontal
void Trans(); // ----------------------> Prosedur transpose matriks
void Rotasi(); // ---------------------> Prosedur rotasi matriks
int Hitung(); // ----------------------> Fungsi penjumlahan elemen kolom terakhir
int Cek(int matriks[][100]); // -------> Fungsi mengecek kesamaan matriks awal-akhir