#include <stdio.h>
#include <string.h>

int idx;        // penampung index karakter
int pKata;      // penampung panjang setiap kata
char cKata[50]; // penampung kata yang sedang dibaca
int idxChar; // penanda index kalimat
char cc; // penampung current character

void startKata(char pita[]);                         // prosedur mulai pembacaan kata
void resetKata();                                    // prosedur menghapus kata
void incKata(char pita[]);                           // prosedur memajukan kata
char *getCKata();                                    // prosedur mengambil kata yang sedang dibaca
int getPKata();                                      // prosedur mengambil panjang kata
int eopKata(char pita[]);                            // prosedur pendeteksi akhir kalimat
void start(char str[]); // untuk menyalakan mesin
void inc(char str[]);   // untuk memajukan kalimat
void adv(char str[]);   // untuk memajukan kalimat melewati karakter spasi
int eop();              // untuk mendeteksi akhir kalimat
char getCC();           // untuk mendapatkan nilai current chacater