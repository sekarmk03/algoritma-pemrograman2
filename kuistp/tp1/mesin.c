/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP1 - MTT121
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*=== Library ===*/
#include "header.h"

/*=== Prosedur & Fungsi ===*/
/*--- Prosedur memindah elemen matriks ke array temp ---*/
void Pindah(int matriks[][100]){ // --------------------------> matriks yg diolah, pass by value
    for (int i = 0; i < baris; i++) { // ---------------------> diulang sebanyak baris
        for (int j = 0; j < kolom; j++) { // -----------------> diulang sebanyak kolom dlm 1 baris
            temp[i][j] = matriks[i][j]; // -------------------> proses memindahkan elemen
        }
    }
}

/*--- Prosedur refleksi matriks secara vertikal ---*/
void RefVer(){
    // variabel lokal
    int idx = 0;
    // -^ inisialisasi index matriks hasil
    for (int i = baris-1; i >= 0; i--) { // ------------------> diulang sebanyak baris
    // dari index baris terakhir, mundur
        for (int j = 0; j < kolom; j++) { // -----------------> diulang sebanyak kolom
            hasil[idx][j] = temp[i][j]; // -------------------> hasil refleksi matriks temp disimpan ke matriks hasil
        }
        idx++; // --------------------------------------------> increment index
    }
    Pindah(hasil); // ----------------------------------------> menyimpan hasil refleksi ke temp (update temp)
}

/*--- Prosedur refleksi matriks secara horizontal ---*/
void RefHor(){
    // variabel lokal
    int idx = 0;
    // -^ inisialisasi index matriks hasil
    for (int i = 0; i < baris; i++) { // ---------------------> diulang sebanyak baris
        idx = 0; // ------------------------------------------> setiap baris dimulai dari kolom index ke-0
        for (int j = kolom-1; j >= 0; j--) { // --------------> diulang sebanyak kolom
        // dari index kolom terakhir, mundur
            hasil[i][idx] = temp[i][j]; // -------------------> hasil refleksi matriks temp disimpan ke matriks hasil
            idx++; // ----------------------------------------> increment index
        }
    }
    Pindah(hasil); // ----------------------------------------> menyimpan hasil refleksi ke temp (update temp)
}

/*--- Prosedur transpose matriks ---*/
void Trans(){
    for (int i = 0; i < kolom; i++) { // ---------------------> diulang sebanyak kolom
        for (int j = 0; j < baris; j++) { // -----------------> diulang sebanyak baris
            hasil[i][j] = temp[j][i]; // ---------------------> transpose dari matriks temp disimpan ke matriks hasil
        }
    }
    // setiap transpose,
    // tukar nilai kolom dgn baris
    int temp = baris;
    baris = kolom;
    kolom = temp;
    Pindah(hasil); // ----------------------------------------> menyimpan hasil transpose ke temp (update temp)
}

/*--- Fungsi penjumlahan elemen kolom terakhir ---*/
int Hitung(){
    // variabel global
    jumlah = 0;
    // variabel lokal
    int idx = kolom-1; // ------------------------------------> index = elemen setiap kolom terakhir dlm matriks
    for (int i = 0; i < baris; i++) { // ---------------------> diulang sebanyak baris
        jumlah += hasil[i][idx]; // --------------------------> jumlahkan elemen kolom terakhir dari setiap baris
    }
    if(jumlah % 2 == 0){ // ----------------------------------> jika hasil penjumlahan genap
        return 0; // -----------------------------------------> kembalikan nilai 0 ke fungsi
    } else { // ----------------------------------------------> selain itu (jika ganjil)
        return 1; // -----------------------------------------> kembalikan nilai 1 ke fungsi
    }
}

/*--- Prosedur rotasi matriks ---*/
void Rotasi(){
    // variabel lokal
    int rot = 0;
    // -^ inisialisasi berapa kali rotasi
    if(Hitung() == 0){ // -----------------------------------> jika fungsi hitung bernilai 0, rotasi ke KIRI
        rot = jumlah % 4; // --------------------------------> banyak rotasi
        if(rot <= 3 && rot != 0){ // ------------------------> jika banyak rotasi antara 1-3
            // rotasi pertama
            RefHor(); // ------------------------------------> di refleksi horizontal
            Trans(); // -------------------------------------> lalu di transpose
            if(rot > 1){ // ---------------------------------> jika banyak rotasi lebih dari satu
                // rotasi kedua
                Trans(); // ---------------------------------> di transpose
                RefVer(); // --------------------------------> lalu di refleksi vertikal
                if(rot > 2){ // -----------------------------> jika banyak rotasi lebih dari dua
                    // rotasi ketiga
                    RefHor(); // ----------------------------> di refleksi horizontal
                    Trans(); // -----------------------------> lalu di transpose
                }
            }
        }
    } else { // ---------------------------------------------> selain itu (bukan bernilai 0), rotasi ke KANAN
        rot = jumlah % 4; // --------------------------------> banyak rotasi
        if(rot <= 3 && rot != 0){ // ------------------------> jika banyak rotasi antara 1-3
            // rotasi pertama
            RefVer(); // ------------------------------------> di refleksi vertikal
            Trans(); // -------------------------------------> lalu di transpose
            if(rot > 1){ // ---------------------------------> jika banyak rotasi lebih dari satu
                // rotasi kedua
                RefVer(); // --------------------------------> di refleksi vertikal
                Trans(); // ---------------------------------> lalu di transpose
                if(rot > 2){ // -----------------------------> jika banyak rotasi lebih dari dua
                    // rotasi ketiga
                    RefVer(); // ----------------------------> di refleksi vertikal
                    Trans(); // -----------------------------> lalu di transpose
                }
            }
        }
    }
    // jika rot = 0 maka tidak di rotasi
}

/*--- Fungsi mengecek kesamaan matriks awal-akhir ---*/
int Cek(int matriks[][100]){ // -----------------------------> matriks yang di cek kesamaannya
    // variable lokal
    int count = 0;
    // -^ penghitung elemen yang sama
    for (int i = 0; i < baris; i++) { // --------------------> diulang sebanyak baris
        for (int j = 0; j < kolom; j++) { // ----------------> diulang sebanyak kolom
            if(matriks[i][j] == hasil[i][j]){ // ------------> pengecekan elemen
                count++; // ---------------------------------> jika sama, variabel count bertambah 1
            }
        }
    }
    if(count == (baris * kolom)) { // -----------------------> jika nilai akhir variabel count = banyaknya elemen
        return 1; // ----------------------------------------> elemen matriks awal-akhir sama semua, kembalikan nilai 1
    } else { // ---------------------------------------------> selain itu
        return 0; // ----------------------------------------> elemen matriks awal-akhir ada yg berbeda, kembalikan nilai 0
    }
}