/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan soal evaluasi GNK20
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

// struct penampung data nama dan nilai mahasiswa
typedef struct {
    char nama[50];
    int nilai1, nilai2;
}mhs;

void swap(mhs *awal, mhs *akhir); //-------------------------------> prosedur menukar isi data array
void input(mhs arr[], int n); //-----------------------------------> prosedur mengisi array
void quick(mhs arr[], int left, int right); //---------------------> prosedur sorting (quick sort)
void merge(mhs arr1[], mhs arr2[], int n, int m, mhs result[]); //-> prosedur penggabungan array
void output(mhs arr[], int n, int start); //-----------------------> prosedur mencetak isi array