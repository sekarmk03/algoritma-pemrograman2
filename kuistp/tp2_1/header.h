/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP2 - MBTT20
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
    - 15/02/2021
    Note. pembuatan kerangka perulangan, pengkondisian, dan prosedur fungsi
          berbeda dari biasanya.
          biasanya for(...)                  sekarang for(...) {
                   {                                      ...
                       ...                            }
                   }
          bentuk penulisan komentar juga berbeda dari biasanya
*/

/*=== Library ===*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*=== Struct ===*/
typedef struct {
    /*
        *akan digunakan sebagai elemen pada setiap matriks
        *diinisialisasi secara global
    */
    char nama[50]; //---> menyimpan string nama
    int nilai[3]; //----> menyimpan 3 buah nilai
    float rataan; //----> menghitung rata-rata ke-3 nilai tsb
}data; //---------------> nama alias struct

// inisalisasi struct
data dt[100][100];

/*=== Global Var ===*/
int baris, kolom, len[100][50], max[100];
//------------------------------^ menyimpan nilai maks tiap kolom matriks
//----------------^menyimpan panjang string nama tiap elemen matriks
//---------^kolom matriks
//--^baris matriks
char tukar[100][50];
//---^menyimpan nama yang akan saling ditukar

/*=== Prosedur & Fungsi ===*/
void InputData(); //-------------------------------------------------------------> mesin.c >>   5 - 23
int InputTukar(); //-------------------------------------------------------------> mesin.c >>  25 - 39
void Swap(char namaKiri[], char namaKanan[], float *kiri, float *kanan); //------> mesin.c >>  41 - 58
bool cek(float a, float b); //---------------------------------------------------> mesin.c >>  60 - 70
void Proses(int jumlah); //------------------------------------------------------> mesin.c >>  72 - 118
void Max(); //-------------------------------------------------------------------> mesin.c >> 120 - 140
void Print(); //-----------------------------------------------------------------> mesin.c >> 142 - 168