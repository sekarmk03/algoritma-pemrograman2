#include "header.h"

int main(){
    /*=== Var Lokal ===*/
    int n, m, i, j, a = 0, b = 0;
    //--------------^------^variabel temporary untuk mengidentifikasi koordinat matriks
    //--------^--^variabel iterator
    //-----^banyak makanan yang dibeli
    //--^banyak makanan yang dimasukan
    scanf("%d%d%d", &baris, &kolom, &n); //-------------------> meminta inputan baris, kolom, jumlah makanan
    list dt[baris][kolom]; //---------------------------------> inisialisasi matriks bungkusan
    Nol(dt); //-----------------------------------------------> memanggil prosedur Nol untuk mengenolkan
    scanf("%d%d", &a, &b); //---------------------------------> meminta masukan koordinat pertama
    for ( j = 0; j < n; j++)
    {
        scanf("%s%d", &dt[a][b].nama, &dt[a][b].harga); //----> meminta masukan nama makanan dan harga
        if(j < n-1){
            scanf("%d%d", &a, &b); //-------------------------> meminta masukan koordinat pertama++
        }
    }
    scanf("%d", &m); //---------------------------------------> meminta masukan banyak makanan yang dibeli
    list t[m]; //---------------------------------------------> inisialisasi array bungkusan
    /* kedua looping dibawah diulang sebanyak m,
       menandakan masukan pemain 1 dan 2 sebanyak m
    */
    for ( i = 0; i < m; i++)
    {
        scanf("%d%d", &t[i].x1, &t[i].y1); //-----------------> meminta masukan koordinat
    }
    for ( i = 0; i < m; i++)
    {
        scanf("%d%d", &t[i].x2, &t[i].y2); //-----------------> meminta masukan koordinat
    }
    Jumlah(m, dt, t); //--------------------------------------> memanggil prosedur jumlah
    Cetak(); //-----------------------------------------------> mencetak hasil
    return 0;
}