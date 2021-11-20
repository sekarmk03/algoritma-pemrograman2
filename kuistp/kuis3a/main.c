#include "header.h"

int main()
{
    int n = 0;                                           // penampung banyak data
    int priceToFind = 0;                                 // data yang harus dicari (harga per gram)
    scanf("%d", &n);                                     // meminta masukan n dari user
    Kurma dataKurma[n];                                  // deklarasi array penampung data kurma
    inputData(dataKurma, n);                             // meminta masukan data kurma
    scanf("%d", &priceToFind);                           // meminta masukan data yang harus dicari
    selection(dataKurma, n);                             // mengurutkan data harga per gram kurma (descending)
    int found = binSearch(dataKurma, 0, n, priceToFind); // penanda data ditemukan atau tidak
    if (found == -1)                                     // jika nilai penanda -1
    {                                                    // data yang dicari tidak ditemukan
        printf("tidak ditemukan\n");
    }
    else
    {                                // selain itu, jika ditemukan (berupa index)
        printData(dataKurma[found]); // cetak informasi kurma
    }
    return 0;
}