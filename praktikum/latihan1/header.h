#include <stdio.h>
#include <string.h>

int indeks; //cek indeks dari pita inputan
int panjangkata; //tampungan panjang kata
char currentKata[50]; //tampungan kata yang sedang dicek pada pita

void startKata(char pita[]); //mulai cek pita
void resetKata(); //reset tampungan kata
void incKata(char pita[]); //maju satu kata pada pita
char *getCurrentKata(); //dapatkan kata yang sedang ditampung
int getPanjangKata(); //dapatkan panjang kata yang sedang ditampung
int eopKata(char pita[]); //pengecek apakah pita inputan sudah selesai