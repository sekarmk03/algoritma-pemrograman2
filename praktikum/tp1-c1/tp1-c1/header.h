#include <stdio.h>

int baris, kolom, arah;

void refleksi_kanan(int hasil[30][30]);
void refleksi_atas(int hasil[30][30]);
void transpose(int hasil[30][30]);
void putar_2(int hasil[30][30]);
int hitung(int hasil[30][30]);
void rotasi(int putar, int hasil[30][30]);
int ket(int awal[30][30], int hasil[30][30]);