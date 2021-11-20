#include "header.h"

void swap(int i, int idx) {
    if (strcmp(method, "selection") == 0) {
        /*
            * prosedur menukar nilai parameter
            * digunakan dalam sorting metode selection
        */
        // temporary struct
        data temp;
        // menukar nama
        strcpy(temp.nama, d[i].nama);
        strcpy(d[i].nama, d[idx].nama);
        strcpy(d[idx].nama, temp.nama);
        // menukar harga
        temp.harga = d[i].harga;
        d[i].harga = d[idx].harga;
        d[idx].harga = temp.harga;
        // menukar rating
        temp.rating = d[i].rating;
        d[i].rating = d[idx].rating;
        d[idx].rating = temp.rating;
    } else {
        /*
            * prosedur memindahkan nilai berdasarkan parameter
            * digunakan dalam sorting metode insertion
        */
        d[i].harga = d[idx].harga;
        d[i].rating = d[idx].rating;
        strcpy(d[i].nama, d[idx].nama);
    }
}

void insert(int n, char sortBy[]) {
    /*
        * prosedur insertion sort
        * cara kerjanya adalah menyimpan data yang di sorot
          ke dalam var data sisip
        * jika data > atau < maka terjadi pergeseran data lain
        * pergeseran terjadi selama kondisi terpenuhi
        * kondisi yg dimaksud : - daya yg disorot < data sisip atau
                                - data yg disorot > data sisip
    */
    // var lokal prosedur (iterator & data sisip)
    int i, j, keyHarga; float keyRating; char key[50];
    /*
        * pengurutan dibagi menjadi 3, berdasarkan nama, harga, atau barang
        * setiap pengurutan terbagi menjadi 2, ascending atau descending
        * pengurutan dilakukan dengan menggeser data yang memenuhi syarat ke arah kanan
        * data sisip yang dijadikan sebagai pembanding/syarat diletakkan di indeks
          paling kiri ketika syarat sudah tidak terpenuhi
        * penjelasan sintaks hanya ada di blok pengkondisian "nama", selebihnya sama
    */
    if (strcmp(type, "asc") == 0) {
        // jika user memilih ascending sort
        for (i = 1; i < n; i++) {
            keyHarga = d[i].harga;
            keyRating = d[i].rating;
            strcpy(key, d[i].nama);
            j = i - 1;
            if (strcmp(sortBy, "nama") == 0) {
            // jika user memilih sort by "nama"
                while (j >= 0 && (strcmp(key, d[j].nama) < 0)) {
                    // perulangan selama j >= 0 dan data sisip < data nama ke-j (i-1)
                    // geser semua data ke kanan
                    swap(j + 1, j);
                    // decrement j sampai mencapai j = -1 (agar keluar dari perulangan)
                    j--;
                }
            } else if (strcmp(sortBy, "harga") == 0) {
                // jika user memilih sort by "harga"
                while (j >= 0 && keyHarga < d[j].harga) {
                    swap(j + 1, j);
                    j--;
                }
            } else {
                // jika user memilih sort by "penilaian"
                while (j >= 0 && keyRating < d[j].rating) {
                    swap(j + 1, j);
                    j--;
                }
            }
            strcpy(d[j + 1].nama, key);
            d[j + 1].harga = keyHarga;
            d[j + 1].rating = keyRating;
        }
    }
    if (strcmp(type, "desc") == 0) {
        // jika user memilih ascending sort
        for (i = 1; i < n; i++) {
            strcpy(key, d[i].nama);
            keyHarga = d[i].harga;
            keyRating = d[i].rating;
            j = i - 1;
            if (strcmp(sortBy, "nama") == 0) {
                // jika user memilih sort by "nama"
                while (j >= 0 && (strcmp(key, d[j].nama) > 0)) {
                    swap(j + 1, j);
                    j--;
                }
            } else if (strcmp(sortBy, "harga") == 0) {
                // jika user memilih sort by "harga"
                while (j >= 0 && keyHarga >= d[j].harga) {
                    swap(j + 1, j);
                    j--;
                }
            } else {
                // jika user memilih sort by "penilaian"
                while (j >= 0 && keyRating >= d[j].rating) {
                    swap(j + 1, j);
                    j--;
                }
            }
            strcpy(d[j + 1].nama, key);
            d[j + 1].harga = keyHarga;
            d[j + 1].rating = keyRating;
        }
    }
}

void sel(int n, char sortBy[]) {
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar data yang memenuhi kondisi
        * jika data > atau < maka terjadi penukaran nilai
        * kondisi yg dimaksud : - daya kiri < data kanan
                                - data kiri > data kanan
    */
    // var lokal prosedur (iterator & data sisip)
    int i, j, idx, tempHarga; float tempRating; char tempNama[50];
    for (i = 0; i < n - 1; i++) {
        // inisialisasi idx dgn i
        idx = i;
        // perulangan pengecekan data per data
        for (j = i + 1; j < n; j++) {
            /*
                * pengurutan dibagi menjadi 3, berdasarkan nama, harga, atau barang
                * setiap pengurutan terbagi menjadi 2, ascending atau descending
                * pengurutan dilakukan dengan menukar data apabila memenuhi syarat pengondisian
                * data yang telah ditukar tetap akan di cek kembali di perulangan berikutnya
                * penjelasan sintaks hanya ada di blok pengkondisian "nama", selebihnya sama
            */
            if (strcmp(sortBy, "nama") == 0) {
                // jika user memilih sort by "nama"
                if (strcmp(type, "asc") == 0) {
                    // jika user memilih ascending sort
                    if ((strcmp(d[idx].nama, d[j].nama) > 0)) {
                        // jika data nama ke-idx > data nama ke-j
                        // maka inisialisasi nilai j ke idx
                        idx = j;
                    }
                } else {
                    // jika user memilih descending sort
                    if ((strcmp(d[idx].nama, d[j].nama) < 0)) {
                        // jika data nama ke-idx < data nama ke-j
                        // maka inisialisasi nilai j ke idx
                        idx = j;
                    }
                }
            } else if (strcmp(sortBy, "harga") == 0) {
                if (strcmp(type, "asc") == 0) {
                    if (d[idx].harga >= d[j].harga) {
                        idx = j;
                    }
                } else {
                    if (d[idx].harga < d[j].harga) {
                        idx = j;
                    }
                }
            } else {
                if (strcmp(type, "asc") == 0) {
                    if (d[idx].rating >= d[j].rating) {
                        idx = j;
                    }
                } else {
                    if (d[idx].rating < d[j].rating) {
                        idx = j;
                    }
                }
            }
        }
        // tukar nilai data ke-i dengan data ke-idx
        // nilai dari idx dapat berubah menjadi j
        // jika salah satu kondisi di atas terpenuhi
        // jika tidak, idx tetap bernilai sama dengan i
        swap(i, idx);
    }
}

void cetak(int n) {
    // prosedur mencetak data terurut
    for (int i = 0; i < n; i++) {
        printf("%s %d %0.1f\n", d[i].nama, d[i].harga, d[i].rating);
    }
}