/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis 2
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];       // menyimpan nama kurma
    int weight;          // menyimpan berat kurma
    int price;           // menyimpan harga kurma
    int status;          // menyimpan status kurma (0/1)
    double pricePerGram; // menyimpan harga kurma per gram
} Kurma;                 // inisialisasi struct

/* fungsi & prosedur */
int binSearch(Kurma d[], int left, int right, double search); // untuk mencari harga per gram yg sesuai
void selection(Kurma arr[], int n);                           // untuk sort harga per gram (ascending)
void swap(Kurma *first, Kurma *last);                         // untuk menukar data dalam proses sort
void inputData(Kurma data[], int n);                          // untuk memasukan data awal dari user
void printData(Kurma found);                                  // untuk mencetak hasil ke konsol