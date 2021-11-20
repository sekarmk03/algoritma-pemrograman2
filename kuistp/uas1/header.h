/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan UAS soal 1
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*-- Library --*/
#include <stdio.h>
#include <string.h>

/*-- Var Global --*/
int idxChar; // untuk menyimpan index karakter yang dibaca
char cc;     // karakter yang dibaca (current)

void start(char str[]); // untuk menyalakan mesin
void inc(char str[]);   // untuk memajukan kalimat
void adv(char str[]);   // untuk memajukan kalimat melewati karakter spasi
int eop();              // untuk mendeteksi akhir kalimat
char getCC();           // untuk mendapatkan nilai current chacater