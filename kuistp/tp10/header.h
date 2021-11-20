/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP 10
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

int idx;        // penampung index karakter
int pKata;      // penampung panjang setiap kata
char cKata[50]; // penampung kata yang sedang dibaca

void startKata(char pita[]);                         // prosedur mulai pembacaan kata
void resetKata();                                    // prosedur menghapus kata
void incKata(char pita[]);                           // prosedur memajukan kata
char *getCKata();                                    // prosedur mengambil kata yang sedang dibaca
int getPKata();                                      // prosedur mengambil panjang kata
int eopKata(char pita[]);                            // prosedur pendeteksi akhir kalimat
int asciiCount(char str[]);                          // prosedur penghitung jumlah ascii tiap kata
void quickSort(char str[][50], int left, int right); // prosedur mengurutkan kata (ascending)
void output(char str[][50], int n);                  // prosedur mencetak format keluaran