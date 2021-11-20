#include "header.h"

// prosedur mulai pembacaan kata
void startKata(char pita[])
{
    idx = 0;                 // pembacaan dimulai dari karakter index ke-0
    pKata = 0;               // inisialisasi panjang kata awal (juga sbg penanda index cKata)
    while (pita[idx] == ' ') // selama bertemu karakter spasi
    {                        // increment index sampai mencapai karakter bukan spasi
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {                             // selama bukan karakter spasi dan bukan akhir kalimat
        cKata[pKata] = pita[idx]; // pindahkan karakter ke penampung kata
        idx++;                    // increment karakter kalimat
        pKata++;                  // increment index penampung kata
    }
    cKata[pKata] = '\0'; // akhiri kata
}

// prosedur menghapus kata
void resetKata()
{
    pKata = 0;           // index ke-0 penampung kata
    cKata[pKata] = '\0'; // dibuat tanpa karakter atau diakhiri
}

// prosedur memajukan kata
void incKata(char pita[])
{
    pKata = 0;               // mulai dari index ke-0 penampung kata
    while (pita[idx] == ' ') // selama bertemu karakter spasi
    {                        // increment sampai bertemu karakter bukan spasi
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {                             // selama bukan karakter spasi dan bukan akhir kalimat
        cKata[pKata] = pita[idx]; // pindahkan karakter ke penampung kata
        idx++;                    // increment karakter kalimat
        pKata++;                  // increment index penampung kata
    }
    cKata[pKata] = '\0'; // akhiri kata
}

// prosedur mengambil kata yang sedang dibaca
char *getCKata()
{
    return cKata; // ambil nilai penampung kata saat ini
}

// prosedur mengambil panjang kata
int getPKata()
{
    return pKata; // ambil panjang penampung kata saat ini
}

// prosedur pendeteksi akhir kalimat
int eopKata(char pita[])
{
    if (pita[idx] == '.') // jika bertemu titik
        return 1;         // kembalikan 1 (akhir kalimat)
    else                  // jika tidak // (sebenarnya ngga perlu else lagi, langsung return 0, tapi di vscode error)
        return 0;         // kembalikan 0 (bukan akhir)
}


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
    if (cc == ' ') // jika mencapat batas akhir kalimat (titik)
        return 1;  // kembalikan nilai 1 sebagai penanda
    return 0;      // jika belum mencapai akhir, kembalikan nilai 0
}

// fungsi pengambil nilai current character
char getCC()
{
    return cc; // kembalikan karakter saat ini
}