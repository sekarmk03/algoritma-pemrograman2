#include "header.h"

void swap(arrlist *awal, arrlist *akhir){
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam setiap metode sorting
    */
    arrlist temp; //----> penampung sementara
    temp = *awal; //----> data awal ditampung
    *awal = *akhir; //--> data akhir dipindah ke data awal
    *akhir = temp; //---> data tampungan dipindah ke data akhir
}

void input(arrlist song[], int n, char id){
    /* Prosedur untuk menginput data ke dalam struct arrlist */
    for (int i = 0; i < n; i++){
        // loop diulang sebanyak n (banyak data)
        // menerima inputan durasi dan judul lagu
        scanf("%f%s", &song[i].duration, &song[i].title);
        song[i].id = id; // menyimpan data id setiap lagu
    }
}

void insertion(arrlist song[], int n, char type){
    /*
        * prosedur insertion sort
        * cara kerjanya adalah menyimpan data yang di sorot
          ke dalam var data sisip (key)
        * pergeseran posisi data terjadi selama kondisi terpenuhi
    */
    int i, j;
    arrlist key; // deklarasi struct key sebagai penampung data sisip
    if (type == 'a') {
        // ascending
        for (i = 1; i < n; i++) {
            key = song[i]; // menyimpan nilai data ke-i sebagai key
            j = i - 1;
            while (j >= 0 && key.duration < song[j].duration) {
                // selama durasi key < durasi data ke-j,
                // tukar posisi data ke-j dengan data ke-j+1
                swap(&song[j+1], &song[j]);
                j--;
            }
            // menyimpan nilai key pada data ke-j+1
            song[j+1] = key;
        }
    } else {
        // descending
        // alur proses sama dengan blok ascending
        for (i = 1; i < n; i++) {
            key = song[i];
            j = i - 1;
            while (j >= 0 && key.duration > song[j].duration) {
                // selama durasi key > durasi data ke-j,
                // tukar posisi data ke-j dengan data ke-j+1
                swap(&song[j+1], &song[j]);
                j--;
            }
            song[j+1] = key;
        }
    }
}

void selection(arrlist song[], int n, char type){
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar data yang memenuhi kondisi
        * jika data > atau < maka terjadi penukaran nilai
    */
    int i, j, idx; // penanda iterator dan indeks
    for (i = 0; i < n - 1; i++) {
        idx = i; // simpan nilai i ke var idx
        for (j = i + 1; j < n; j++) {
            if (type == 'a') {
                // ascending
                if (song[idx].duration > song[j].duration) {
                    // jika data kiri > data kanan, inisialisasi idx dengan posisi data kanan
                    idx = j;
                }
            } else {
                // descending
                if (song[idx].duration < song[j].duration) {
                    // jika data kiri < data kanan, inisialisasi idx dengan posisi data kanan
                    idx = j;
                }
            }
        }
        swap(&song[i], &song[idx]); // tukar data ke i dgn data ke idx
    }
}

void quick(arrlist song[], int left, int right, char type){
    /*
        * prosedur quick sort
        * cara kerjanya dengan menukar posisi data
        * kondisi data dibandingkan dengan pivot
        * pivot pada prosedur ini merupakan data tengah
        * i dan j sebagai penanda berjalan
        * jika kondisi yang ditentukan terpenuhi, i atau j akan berhenti
        * sebaliknya, i atau j akan maju
        * jika penanda i dan j berhenti, kedua data ditukar posisi
        * jika i = j, data dibagi 2 dan diulangi proses seperti sebelumnya (rekursif)
    */
    int i = left, j = right;
    //--^---------^inisalisasi nilai penanda i dan j dengan data paling kiri dan paling kanan
    float pivot = song[(right + left) / 2].duration;
    //-----^inisialisasi nilai pivot dengan data tengah
    do{
        if(type == 'a'){
            // ascending
            while (song[i].duration < pivot && i <= j)
                i++;
                // penanda i maju selama data ke-i kurang dari pivot dan nilai i kurang dari j
            while (song[j].duration > pivot && i <= j)
                j--;
                // penanda j mundur selama data ke-j lebih dari pivot dan nilai i kurang dari j
        } else {
            // descending
            while (song[i].duration > pivot && i <= j)
                i++;
                // penanda i maju selama data ke-i lebih dari pivot dan nilai i kurang dari j
            while (song[j].duration < pivot && i <= j)
                j--;
                // penanda j mundur selama data ke-j kurang dari pivot dan nilai i kurang dari j
        }
        if(i < j){
            swap(&song[i], &song[j]);
            // jika penanda i dan j sudah berhenti, tukar kedua data
            i++; j--; // penanda maju/mundur lagi
        }
    } while (i < j);
    // pembelahan list data terjadi jika nilai i = j
    if((left < j) && (j < right))
        quick(song, left, j, type);
    if((i < right) && (i > left))
        quick(song, i, right, type);
}

void bubble(arrlist song[], int n, char type){
    /*
        * prosedur bubble sort
        * cara kerjanya dengan mengecek dua elemen yg bersebelahan
        * jika lebih besar/kecil (tergantung kondisi), maka
          akan ditukar posisinya
    */
    int i, tukar;
    //-----^penanda terjadi pertukaran data
    do{
        tukar = 0;
         // pengecekan seluruh pasangan elemen dalam data
        for ( i = 0; i < n-1; i++){
            if(type == 'a'){
                // ascending
                if (song[i].duration > song[i+1].duration){
                    // jika kondisi terpenuhi, data ditukar
                    swap(&song[i], &song[i+1]);
                    // tandai bahwa terjadi pertukaran
                    tukar = 1;
                }
            } else {
                // descending
                if (song[i].duration < song[i+1].duration){
                    swap(&song[i], &song[i+1]);
                    tukar = 1;
                }
            }
        }
    } while (tukar == 1); // akan terus diulang selama masih terjadi pertukaran
}

void merge(arrlist song1[], arrlist song2[], int n, int m, arrlist result[], char type){
    /* prosedur untuk menggabungkan dua array yang sudah terurut */
    int i = 0, j = 0, k = 0, l = 0; //-----------------------> iterator penanda index
    while ((i < n) && (j < m)){ //---------------------------> selama i < panjang array1 dan j < panjang array2
        if(type == 'a'){
            // ascending
            if (song1[i].duration <= song2[j].duration){ //--> jika data1 kurang dari atau sama dengan data2
                result[k] = song1[i]; //---------------------> pindahkan isi struct data1 ke struct hasil(result)
                i++; k++; //---------------------------------> increment index kedua array data
            }
            if (song2[j].duration <= song1[i].duration){ //---> jika data2 kurang dari atau sama dengan data1
                result[k] = song2[j]; //---------------------> pindahkan isi struct data2 ke struct hasil(result)
                j++; k++; //---------------------------------> increment index kedua array data
            }
        } else {
            // descending
            // alur proses sama dengan ascending, beda di pengkondisian
            if (song1[i].duration >= song2[j].duration){
                result[k] = song1[i];
                i++;
                k++;
            }
            if (song2[j].duration >= song1[i].duration){
                result[k] = song2[j];
                j++;
                k++;
            }
        }
    }
    // jika masih ada sisa data dari pengisian array hasil sebelumnya
    if (i < n){ //-------------------------> jika sisanya di array data1
        for ( l = i; l < n; l++){
            result[k] = song1[l]; //-------> masukkan data sisa ke array hasil
            k++; //------------------------> increment indeks array hasil
        }
    }
    if (j < m){ //-------------------------> jika sisanya di array data2
        for ( l = j; l < m; l++){ //-------> masukkan data sisa ke array hasil
            result[k] = song2[l];
            k++; //------------------------> increment indeks array hasil
        }
    }
}

void output(arrlist result[], int n, arrlist ibnu[]){
    /* Prosedur mengeluarkan isi array */
    int x = 0; //-----------------------------------------------------> penghitung jumlah lagu ibnu
    printf("Daftar Lagu Keluarga:\n");
    for (int i = 0; i < n; i++){ //-----------------------------------> menampilkan seluruh isi array terurut
        printf("%0.2f %s\n", result[i].duration, result[i].title);
        if(i < (int)(ceil(n * 0.5))){ //------------------------------> jika i < separuh atas daftar
        // ceil(digunakan) untuk pembulatan ke atas
            if(result[i].id == 'x') //--------------------------------> jika ada lagunya ibnu
                x++; //-----------------------------------------------> tambahkan ke penghitung
        }
    }
    printf("\nLagunya Ibnu:\n");
    for (int i = 0; i < x; i++){ //-----------------------------------> menampilkan lagu ibnu yang ada di separuh atas daftar
        printf("%s\n", ibnu[i].title); //-----------------------------> lagu ibnu diambil dari playlist pribadi ibnu
    }
    if(x == 0){  //---------------------------------------------------> jika tidak ada lagu ibnu di separuh atas daftar
        printf("Tidak memutar lagu Ibnu\n"); //-----------------------> cetak ini
    }
}