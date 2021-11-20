/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP9
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

int idx; // penanda index kalimat
char cc; // penampung current character

void start(char str[]); // untuk menyalakan mesin
void inc(char str[]);   // untuk memajukan kalimat
void adv(char str[]);   // untuk memajukan kalimat melewati karakter spasi
int eop();              // untuk mendeteksi akhir kalimat
char getCC();           // untuk mendapatkan nilai current chacater