/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan UTS 1
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    // struct penyimpan data
    char nama[50], negara[50];
    int kal, gram, harga;
    double kalGram;
}dessert;

void swap(dessert *awal, dessert *akhir); //-------------------------------------> prosedur menukar data array
void input(dessert arr[], int n, char negara[]); //------------------------------> prosedur menginput data
void insertion(dessert arr[], int n); //-----------------------------------------> prosedur insertion sort
void selection(dessert arr[], int n); //-----------------------------------------> prosedur selection sort
void quick(dessert arr[], int left, int right); //-------------------------------> prosedur quick sort
void bubble(dessert arr[], int n); //--------------------------------------------> prosedur bubble sort
void merge(dessert arr1[], dessert arr2[], int n, int m, dessert result[]); //---> prosedur merge array
void output(char negara[50], dessert arr[], int n); //---------------------------> prosedur mencetak array