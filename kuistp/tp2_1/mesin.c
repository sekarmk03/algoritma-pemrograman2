/*=== Library ===*/
#include "header.h"

/*=== Prosedur & Fungsi ===*/
void InputData(){
    /*
        * prosedur menginput data untuk mengisi matriks awal
        * data yang diinput bertipe string dan integer
        * perulangan dilakukan sebanyak jumlah baris x kolom
        * line 18 : pengisian array panjang string nama (len)
        * line 22 : pemrosesan rata-rata
    */
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            scanf("%s", dt[i][j].nama);
            len[i][j] = strlen(dt[i][j].nama);
            for (int k = 0; k < 3; k++) {
                scanf("%d", &dt[i][j].nilai[k]);
            }
            dt[i][j].rataan = (float)(dt[i][j].nilai[0] + dt[i][j].nilai[1] + dt[i][j].nilai[2]) / 3;
        }
    }
}

int InputTukar(){
    /*
        * fungsi menginput data array string nama yang di tukar
        * penginputan diulang sampai user memasukkan string "stop"
        * return value berupa jumlah string yang telah diinput
        * return value akan digunakan dalam prosedur lain
    */
    int i = 0;
    int jumlah = 0;
    do {
        scanf("%s", tukar[i]);
        i++; jumlah++;
    } while (strcmp(tukar[i-1], "stop") != 0);
    return jumlah;
}

void Swap(char namaKiri[], char namaKanan[], float *kiri, float *kanan){
    /*
        * prosedur untuk menukar nama kiri dengan nama kanan
        * dan menukar rata-rata kiri dengan rata-rata kanan
        * aktif jika if pada prosedur pemanggil bernilai true
        * syarat true adalah jika rata-rata kiri > rata-rata kanan
    */
    char tempNama[50]; //---------------> untuk menampung nama kiri
    float tempRataan; //----------------> untuk menampung rata-rata kiri
    /* proses penukaran nama */
    strcpy(tempNama, namaKiri);
    strcpy(namaKiri, namaKanan);
    strcpy(namaKanan, tempNama);
    /* proses penukaran nilai rata-rata */
    tempRataan = *kiri;
    *kiri = *kanan;
    *kanan = tempRataan;
}

bool cek(float a, float b){
    /*
        * fungsi untuk mengecek apakah rata-rata kiri > rata-rata kanan
        * jika benar maka akan mengembalikan nilai true
        * jika salah maka akan mengembalikan nilai false
    */
    if (a > b) {
        return true;
    }
    return false;
}

void Proses(int jumlah){
    /*
        * prosedur untuk memproses pertukaran posisi elemen matriks
        * dan untuk menyimpan panjang nama pada matriks akhir
        * melakukan pemanggilan fungsi dan prosedur lain
        * mendeklarasikan beberapa variabel lokal
        * perulangan diulang sebanyak jumlah elemen matriks untuk setiap elemen array tukar
    */
    int idxB[100], idxK[100], sama = 0;
    //------------------------^untuk menyimpan nilai saat string yang dicari ketemu
    //-------------^menyimpan index kolom (saat string yang dicari ketemu)
    //--^menyimpan index baris (saat string yang dicari ketemu)
    /* perulangan proses pencarian dan penukaran */
    for (int a = 0; a < jumlah-1; a++) {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                // pengecekan apakah elemen tukar ke-a = elemen matriks dt ke-ij
                if (strcmp(tukar[a], dt[i][j].nama) == 0) {
                    strcpy(tukar[a], "\0"); //------------> jika ditemukan yang sama, elemen dihapus
                    idxB[a] = i; idxK[a] = j; //----------> indexnya disimpan ke array penyimpan index
                    sama++; //----------------------------> variabel sama di increment
                }
                // jika variabel sama sudah bernilai 2
                // yang artinya sepasang nama berhasil ditemukan di dalam matriks
                if(sama == 2) {
                    sama = 0; //--------------------------> variabel sama di reset
                    // jika nama pertama pada pasangan nama yang ditemukan
                    // memiliki rata-rata > rata-rata nama kedua
                    if (cek(dt[idxB[a-1]][idxK[a-1]].rataan, dt[idxB[a]][idxK[a]].rataan)) {
                        // posisi nama dan nilai rata-rata pada matriks ditukar
                        // memanggil prosedur swap
                        Swap(dt[idxB[a-1]][idxK[a-1]].nama, dt[idxB[a]][idxK[a]].nama,
                        &dt[idxB[a-1]][idxK[a-1]].rataan, &dt[idxB[a]][idxK[a]].rataan);
                    }
                }
            }
        }
    }
    // perulangan menyimpan panjang setiap nama setelah prosisinya diubah
    // diulang sebanyak elemen pada matriks
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            // disimpan dalam variabel len yang merupakan global variabel
            len[i][j] = strlen(dt[i][j].nama);
        }
    }
}

void Max(){
    /*
        * prosedur mencari panjang maksimum pada nama dalam setiap kolom matriks
        * hasil pencarian disimpan dalam variabel global max
        * perulangan pencarian dilakukan sebanyak elemen pada matriks
        * prosedur ini akan digunakan dalam prosedur lain
    */
    for (int i = 0; i < kolom; i++) {
        // nilai matriks elemen pertama disimpan dulu
        max[i] = len[0][i];
        for (int j = 1; j < baris; j++) {
            // pengecekan
            if (max[i] < len[j][i]) {
                // jika nilai yang disimpan lebih kecil
                // maka simpan nilai yang lebih besar
                // menggantikan posisi nilai yang lebih kecil
                max[i] = len[j][i];
            }
        }
    }
}

void Print(){
    /*
        * prosedur untuk mencetak elemen matriks ke layar
        * setiap kolom matriks dibuat rata kiri
        * perulangan diulang sebanyak elemen matriks
    */
    Max(); // memanggil prosedur max untuk menentukan nama terpanjang setiap kolom
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            // mencetak nama dalam 1 baris
            // nama dicetak per karakter
            for (int k = 0; k < strlen(dt[i][j].nama); k++) {
                printf("%c", dt[i][j].nama[k]);
            }
            // mencetak spasi sampai jumlah karakter tercetak = panjang string terpanjang
            if(j < kolom-1) {
                for (int k = 0; k < max[j] - strlen(dt[i][j].nama); k++) {
                    printf(" ");
                }
                // mencetak 2 spasi sebagai pembatas antar kolom
                printf("  ");
            }
        }
        // pindah baris
        printf("\n");
    }
}