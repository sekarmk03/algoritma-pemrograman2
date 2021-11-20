/*=== Library ===*/
#include "header.h"

/*=== Fungsi & Prosedur ===*/
int Bakteri(int a, int b, int N){
    /*
        * fungsi untuk menghitung jumlah bakteri pada jam ke-N
        * fungsi rekursif
    */
    // base case
    if(N == 2){
        // mengembalikan nilai (2x jml bakteri jam ke-1) + (kuadrat jml bakteri jam ke-0)
        return ((2 * b) + (a * a));
    } else {
        // menyimpan nilai (2x jml bakteri jam ke-(N-1)) + (kuadrat jml bakteri jam ke-(N-2))
        int temp = (2 * b) + (a * a);
        // mengembalikan nilai fungsi yang dipanggil
        // akan terus memanggil fungsi sampai N == 2 atau mencapai base case
        return Bakteri(b, temp, N-1);
    }
}

void InOut(int n, int a[], int b[], int c[], int hasil[]){
    /*
        * prosedur memasukkan dan mencetak nilai
        * masukan --> a : jml bakteri jam ke-0
        *             b : jml bakteri jam ke-1
        *             c : jam yg ditanyakan
        * keluaran -> hasil : jml bakteri jam ke-c
    */
    // meminta masukan a,b,c
    for (int i = 0; i < n; i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        // memanggil fungsi penghitung jumlah bakteri
        hasil[i] = Bakteri(a[i], b[i], c[i]);
    }
    // mencetak nilai hasil
    for (int i = 0; i < n; i++){
        printf("%d\n", hasil[i]);
    }
}