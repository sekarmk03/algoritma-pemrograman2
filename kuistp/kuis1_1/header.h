/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis soal 1
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*=== Library ===*/
#include <stdio.h>
#include <string.h>

/*=== Struct ===*/
typedef struct 
{
    char nama[50]; //--------------------> menyimpan nama makanan
    int harga, x1, y1, x2, y2;
    //-----------------^---^koordinat masukan pemain kedua
    //---------^---^koordinat masukan pemain pertama
    //--^harga setiap makanan
}list; //--------------------------------> nama struct

/*=== Inisialisasi Struct ===*/
list dt[100][100]; //--------------------> untuk menyimpan matriks daftar makanan
list t[100]; //--------------------------> untuk menyimpan array koordinat

/*=== Var Global ===*/
int baris, kolom, total1, total2;
//----------------^-------^menyimpan harga total pemain1 dan pemain2
//--^------^ukuran matriks

/*=== Deklarasi Prosedur ===*/
void Nol(); //--------------------------> prosedur mengenolkan harga seluruh elemen matriks
void Jumlah(int m); //------------------> prosedur menghitung jumlah
void Cetak(); //-------------------------> prosedur mencetak output