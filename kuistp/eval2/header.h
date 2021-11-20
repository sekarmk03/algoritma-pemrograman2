/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Evaluasi 2
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[20], nama[100], kelas[50];
} kereta;

int idx;        // penampung index karakter
int pKata;      // penampung panjang setiap kata
char cKata[50]; // penampung kata yang sedang dibaca
int max[4];     // penampung string terpanjang tiap kolom

void startKata(char pita[]);                                                        // prosedur mulai pembacaan kata
void resetKata();                                                                   // prosedur menghapus kata
void incKata(char pita[]);                                                          // prosedur memajukan kata
char *getCKata();                                                                   // fungsi mengambil kata yang sedang dibaca
int getPKata();                                                                     // fungsi mengambil panjang kata
int eopKata(char pita[]);                                                           // fungsi pendeteksi akhir kalimat
int requestQuery(char pita[]);                                                      // fungsi menentukan jenis query
void insertData(char pita[], kereta *dataKereta);                                   // prosedur insert data
void cariData(char pita[], kereta dataKereta[], int n, kereta hasil[], int *found); // prosedur cari data
int binSearch(kereta table[], char search[], int left, int right, char atribut[]);  // binary search
void tampilData(kereta dataKereta[], int n);                                        // prosedur menampilkan data