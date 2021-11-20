/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP4 - ULP21
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// library
#include <stdio.h>
#include <string.h>

// struct data untuk menampung masukan barang
typedef struct
{
    char nama[50];
    int harga;
    float rating;
} data;

// inisialisasi struct data sbg array
data d[100];

// var global
char type[50];   //---------------------------------> menampung tipe sorting (asc/desc)
char method[50]; //---------------------------------> menampung metode sorting (insertion/selection)

// prosedur
void swap(int i, int idx);         //---------------> menukar var dalam parameter
void insert(int n, char sortBy[]); //---------------> sorting metode insertion
void sel(int n, char sortBy[]);    //---------------> sorting metode selection
void cetak(int n);                 //---------------> cetak hasil sorting