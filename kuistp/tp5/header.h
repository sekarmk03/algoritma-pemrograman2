/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP5
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>

// struct penampung data yg akan diurutkan
typedef struct {
    double num, den, hasil;
}pecahan;

// prosedur
void swap(pecahan *awal, pecahan *akhir); //--------------------> penukar data dalam struct
void bubbleSort(pecahan frac[], int n, char by); //-------------> bubble sort
void qsTengah(pecahan frac[], int kiri, int kanan, char by); //-> quick sort
void cetak(pecahan frac[], int n); //---------------------------> cetak hasil