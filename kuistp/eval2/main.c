#include "header.h"

int main()
{
    kereta dataKereta[200], dataTampil[100];
    //-----^data awal       ^data hasil pencarian
    char pita[200]; // deklarasi pita
    int q = -1, i = 0, dataFound = 0;
    //-----------------^jumlah data yg ditemukan
    //--^penanda jenis query
    while (q != 0) // selama nilai query bukan 0 (TAMPILKAN)
    {
        scanf(" %199[^\n]s", pita); // meminta masukan pita
        q = requestQuery(pita);     // pengecekan nilai query
        if (q == 1)                 // jika bernilai 1, maka insert data
        {
            insertData(pita, &dataKereta[i]);
            i++;
        }
        else if (q == 2) // jika bernilai 2, maka cari data
        {
            cariData(pita, dataKereta, i, dataTampil, &dataFound);
        }
    }
    tampilData(dataTampil, dataFound); // tampilkan seluruh data hasil pencarian
    return 0;
}