#include "header.h"

int main(){
    int n, idxSearch;
    //-----^ penampung index yg dicari
    //--^ penampung jumlah mahasiswa
    scanf("%d", &n); //---------> meminta masukan jumlah mahasiswa
    data mhs[n]; //-------------> inisialisasi array of struct penampung data mahasiswa
    input(mhs, n); //-----------> menginput data mahasiswa ke array of struct mhs
    scanf("%d", &idxSearch); //-> meminta masukan index yg ingin dicari
    selectionSort(mhs, n); //---> mengurutkan data berdasarkan rata-rata nilai
    /* mengecek apakah setelah rata-rata diurutkan, nama mahasiswa terurut juga atau tidak.
       jika terurut, digunakan binary search untuk mencari index nama.
       jika tidak terurut, digunakan sequential search untuk mencari index nama.
       data yang ditemukan, disimpan ke struct result. */
    data result = sorted(mhs, n) == 1 ? binSearch(mhs, 0, n, idxSearch) : seqSearch(mhs, n, idxSearch);
    output(mhs, n, result); //--> menampilkan hasil sesuai spesifikasi soal
    return 0;
}