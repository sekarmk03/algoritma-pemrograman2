#include "header.h"

// prosedur menyalakan mesin
void start(char str[])
{
    idxChar = 0;       // inisialisasi index kalimat dengan 0 (awal kalimat)
    cc = str[idxChar]; // karakter pertama
}

// prosedur memajukan kalimat
void inc(char str[])
{
    idxChar++;         // increment index agar kalimat maju
    cc = str[idxChar]; // ambil karakter saat ini
}

// prosedur memajukan kalimat melewati karakter spasi
void adv(char str[])
{
    inc(str);                           // panggil prosedur memajukan kalimat
    while ((cc == ' ') && (eop() == 0)) // jika ditemukan spasi sebelum akhir kata
    {
        inc(str); // panggil prosedur memajukan kalimat
    }
}

// fungsi pendeteksi akhir kalimat
int eop()
{
    if (cc == '.') // jika mencapat batas akhir kalimat (titik)
        return 1;  // kembalikan nilai 1 sebagai penanda
    return 0;      // jika belum mencapai akhir, kembalikan nilai 0
}

// fungsi pengambil nilai current character
char getCC()
{
    return cc; // kembalikan karakter saat ini
}