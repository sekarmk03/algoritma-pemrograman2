/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP5
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

// struct penampung data lagu
typedef struct {
    float duration; //-----> tampungan durasi
    char title[30], id; //-> tampungan judul lagu dan id lagu (lagu milik siapa)
} arrlist;

void input(arrlist song[], int n, char id); //----------------------------------------------> prosedur input data lagu
void insertion(arrlist song[], int n, char type); //----------------------------------------> prosedur insertion sort
void bubble(arrlist song[], int n, char type); //-------------------------------------------> prosedur bubble sort
void quick(arrlist song[], int kiri, int kanan, char type); //------------------------------> prosedur quick sort
void selection(arrlist song[], int n, char type); //----------------------------------------> prosedur selection sort
void swap(arrlist *awal, arrlist *akhir); //------------------------------------------------> prosedur menukar data
void merge(arrlist song1[], arrlist song2[], int n, int m, arrlist result[], char type); //-> prosedur menggabungkan data terurut
void output(arrlist result[], int n, arrlist ibnu[]); //------------------------------------> prosedur mencetak hasil