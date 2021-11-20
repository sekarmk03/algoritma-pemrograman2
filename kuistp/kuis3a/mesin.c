#include "header.h"

void inputData(Kurma data[], int n)
{
    /* prosedur input data awal */
    for (int i = 0; i < n; i++)
    {
        char status[20]; // menampung status sementara dari masukan user
        scanf("%s %d %d %s", data[i].name, &data[i].weight, &data[i].price, status);
        // meminta masukan nama, berat, harga, dan statuss
        if (strcmp(status, "premium") == 0)
        {                       // jika user memasukkan premium
            data[i].status = 1; // kodekan status dengan 1
        }
        else
        {                       // selain itu
            data[i].status = 0; // kodekan status dengan 0
        }
        data[i].pricePerGram = (double)(data[i].price / data[i].weight);
        // hitung harga per gram (casting supaya tipe data menjadi double)
    }
}

void swap(Kurma *first, Kurma *last)
{
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam proses sorting
    */
    Kurma temp;     // penampung sementara
    temp = *first;  // data awal ditampung
    *first = *last; // data akhir dipindah ke data awal
    *last = temp;   // data tampungan dipindah ke data akhir
}

void selection(Kurma data[], int n)
{
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar data yang memenuhi kondisi
        * jika data > atau < maka terjadi penukaran nilai
        * kondisi yg dimaksud : - data kiri > data kanan (descending)
    */
    int i, j, idx;
    for (i = 0; i < n - 1; i++)
    {                               // perulangan 0 sampai n-1
        idx = i;                    // inisialisasi idx dengan i
        for (j = i + 1; j < n; j++) // perulangan mengecek data satu persatu
        {
            if (data[idx].pricePerGram > data[j].pricePerGram)
            {            // jika data kiri > data kanan
                idx = j; // inisialisasi idx dengan posisi data kanan
            }
        }
        swap(&data[i], &data[idx]); // tukar data ke i dgn data ke idx
    }
}

int binSearch(Kurma d[], int left, int right, double search)
{
    /*
        * prosedur binary search
        * untuk mencari data yang sudah terurut
        * mencari data dengan urutan descending
    */
    if (right >= left)
    {
        int mid = (right - left) / 2 + left; // cari tengah-tengahnya, simpan di var mid
        if (d[mid].pricePerGram == search)
        {               // jika index tengah sama dengan index yg dicari
            return mid; // return data struct index yg dicari (karena sudah ketemu)
        }
        else if (d[mid].pricePerGram > search)
        {                                               // jika index tengah > index yg dicari
            return binSearch(d, left, mid - 1, search); // bagi dua array, fokus ke pencarian index di array bagian kiri
        }
        else if (d[mid].pricePerGram < search)
        {                                                // jika index tengah < index yg dicari
            return binSearch(d, mid + 1, right, search); // bagi dua array, fokus ke pencarian index di array bagian kanan
        }
    }
    return -1; // jika data tidak ditemukan, kembalikan nilai -1
}

void printData(Kurma found)
{
    printf("nama kurma: %s\n", found.name);                 // cetak nama kurma
    printf("berat: %d gram\n", found.weight);               // cetak berat kurma
    printf("harga: %d\n", found.price);                     // cetak harga kurma
    printf("harga per berat: %0.lf\n", found.pricePerGram); // cetak harga per gram
    printf("status premium: ");                             // cetak status kurma
    if (found.status == 1)                                  // jika kodenya 1 maka statusnya premium
    {
        printf("ya\n");
    }
    else
    {
        printf("tidak\n");
    }
}