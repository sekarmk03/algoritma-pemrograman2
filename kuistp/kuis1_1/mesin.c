#include "header.h"

/*=== Prosedur ===*/
void Nol(){
    /*
        * untuk mengenolkan seluruh harga dalam matriks
        * sebennarnya bisa dengan cara array[100][100] = {{0},{0}};
        * namun harus diinisialisasi di file.c
        * dan saya belum tau caranya passing struct di prosedur
    */
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dt[i][j].harga = 0;
        }
    }
}

void Jumlah(int m){
    /*
        * untuk menghitung harga yang harus dibayar
        * satu pemain dalam satu loop
        * jumlah disimpan dalam variabel global total
    */
    int i, j, a, b;
    //--------^--^temporary variabel untuk menyimpan koordinat
    //--^--^variabel iterator
    total1 = 0; //--------------------------------> variabel penyimpan total harga pemain1
    total2 = 0; //--------------------------------> variabel penyimpan total harga pemain2
    for ( i = 0; i < m; i++)
    {
        a = t[i].x1; b = t[i].y1; //--------------> memindah koordinat ke var temporary
        total1 += dt[a][b].harga; //--------------> menambah nilai harga ke total
    }
    for ( i = 0; i < m; i++)
    {
        a = t[i].x2; b = t[i].y2; //--------------> memindah koordinat ke var temporary
        total2 += dt[a][b].harga; //--------------> menambah nilai harga ke total
    }
}

void Cetak(){
    /*
        * prosedur mencetak hasil akhir
        * pemenang adalah pemain dengan total harga terendah
        * jika total harga sama makan tidak ada pemenang
    */
    printf("pemain pertama %d\n", total1); //-----> mencetak total harga pemain pertama
    printf("pemain kedua %d\n", total2); //-------> mencetak total harga pemain kedua
    // mencetak pemenang
    if (total1 < total2)
    {
        printf("pemenangnya pemain pertama\n");
    }
    else if(total1 > total2)
    {
        printf("pemenangnya pemain kedua\n");
    } else
    {
        printf("tidak ada pemenang\n");
    }
}