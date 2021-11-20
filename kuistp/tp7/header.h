/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP7
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50]; //----> menyimpan data nama mahasiswa
    int m, score[50]; //-> m menyimpan jumlah nilai, score menyimpan data nilai
    double mean; //------> menyimpan rata-rata nilai
}data; //----------------> inisialisasi struct

/* Prosedur & Fungsi */
void input(data d[], int n); //-------------------------------> untuk menginput isi struct
int sorted(data d[], int n); //-------------------------------> untuk mengecek data nama terurut/tidak
data seqSearch(data d[], int n, int search); //---------------> prosedur sequential search (data unsorted)
data binSearch(data d[], int left, int right, int search); //-> prosedur binary search (data sorted)
void swap(data *awal, data *akhir); //------------------------> prosedur penukar data
void selectionSort(data d[], int n); //-----------------------> prosedur mengurutkan data
void output(data d[], int n, data res); //--------------------> prosedur mencetak output