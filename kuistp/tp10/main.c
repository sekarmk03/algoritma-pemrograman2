#include "header.h"

int main()
{
    char kamusBaku[100][50];    // penampung kata baku (jumlah ascii genap)
    char kamusTdkBaku[100][50]; // penampung kata tidak baku (jumlah ascii ganjil)
    int i = 0, j = 0;           // inisialisasi iterator (juga untuk menjumlahkan isi array)
    char pita[200];             // penampung pita
    scanf("%199[^\n]s", pita);  // meminta masukan pita
    startKata(pita);            // mulai pembacaan pita
    if (asciiCount(getCKata()) % 2 == 0)
    {                                     // jika kata pertama jumlah ascii nya genap
        strcpy(kamusBaku[i], getCKata()); // masukkan ke array kamusBaku
        i++;
    }
    else
    {                                        // jika kata pertama jumlah ascii nya ganjil
        strcpy(kamusTdkBaku[j], getCKata()); // masukkan ke array kamusTidakBaku
        j++;
    }
    while (eopKata(pita) == 0) // selama bukan akhir pita/kalimat
    {
        incKata(pita); // majukan kata yang dibaca
        if (asciiCount(getCKata()) % 2 == 0)
        {                                     // jika kata yang sedang dibaca jumlah ascii nya genap
            strcpy(kamusBaku[i], getCKata()); // masukkan ke array kamusBaku
            i++;                              // tambahkan jumlah array
        }
        else
        {                                        // jika kata yang sedang dbaca jumlah ascii nya ganjil
            strcpy(kamusTdkBaku[j], getCKata()); // masukkan ke array kamusTidakBaku
            j++;                                 // tambahkan jumlah array
        }
    }
    quickSort(kamusBaku, 0, i - 1);    // sorting array kamusBaku (ascending)
    quickSort(kamusTdkBaku, 0, j - 1); // sorting array kamusTidakBaku (ascending)

    // output sesuai permintaan
    printf("KATA BAKU:\n");       //.
    output(kamusBaku, i);         // cetak isi array kamusBaku ke layar
    printf("\nKATA NON BAKU:\n"); //.
    output(kamusTdkBaku, j);      // cetak isi array kamusTidakBaku ke layar
    return 0;
};