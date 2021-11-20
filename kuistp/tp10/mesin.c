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

// prosedur penghitung jumlah ascii tiap kata
int asciiCount(char str[])
{
    int total = 0; // inisialisasi total dengan 0
    for (int i = 0; i < strlen(str); i++)
    {
        total += str[i]; // tambahkan ascii setiap karakter dalam kata
    }
    return total; // kembalikan nilai akhir total
}

// prosedur mengurutkan kata (ascending)
void quickSort(char str[][50], int left, int right)
{
    int i = left, j = right;                // inisialisasi i dengan nilai param left dan j dengan nilai param right
    char pivot[50];                         // deklarasi pivot
    strcpy(pivot, str[(right + left) / 2]); // simpan nilai elemen array tengah ke pivot
    do
    {                                               // selama i kurang dari j
        while (strcmp(str[i], pivot) < 0 && i <= j) // jika kata ke-i (di kiri) lebih kecil dari pivot dan i <= j
            i++;                                    // maka maju ke kata selanjutnya (karena kondisi ascending terpenuhi)
        while (strcmp(str[j], pivot) > 0 && i <= j) // jika kata ke-j (di kanan) lebih besar dari pivot dan i <= j
            j--;                                    // maka mundur ke kata sebelumnya (karena kondisi ascending sudah terpenuhi)
        if (i < j)                                  // jika i < j (perulangan berhenti/bertemu kata tidak sesuai kondisi)
        {                                           // tukar kata ke i dengan j
            char temp[50];
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j], temp);
            i++; // maju
            j--; // mundur
        }
    } while (i < j);
    if ((left < j) && (j < right)) // rekursif quicksort bagian kiri array
    {
        quickSort(str, left, j);
    }
    if ((i < right) && (i > left)) // rekursif quicksort bagian kanan array
    {
        quickSort(str, i, right);
    }
}

// prosedur mencetak format keluaran
void output(char str[][50], int n)
{
    if (n > 0) // jika array of string ada isinya
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", str[i]); // print isinya
        }
    }
    else // jika array of string kosong
    {
        printf("TIDAK ADA.\n");
    }
}