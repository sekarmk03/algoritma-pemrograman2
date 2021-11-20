#include "header.h"

void swap(dessert *awal, dessert *akhir){
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam setiap metode sorting
    */
    dessert temp; //----> penampung sementara
    temp = *awal; //----> data awal ditampung
    *awal = *akhir; //--> data akhir dipindah ke data awal
    *akhir = temp; //---> data tampungan dipindah ke data akhir
}

void input(dessert arr[], int n, char negara[]){
    /* Prosedur untuk menginput data ke dalam struct dessert */
    for (int i = 0; i < n; i++){
        // loop diulang sebanyak n (banyak data)
        // menerima inputan nama, kalori, gram, harga
        scanf("%s%d%d%d", &arr[i].nama, &arr[i].kal, &arr[i].gram, &arr[i].harga);
        arr[i].kalGram = (double)arr[i].kal / arr[i].gram; // menyimpan nilai kalori per gram
        strcpy(arr[i].negara, negara); // menyimpan data negara
    }
}

void insertion(dessert arr[], int n){
    /*
        * prosedur insertion sort
        * cara kerjanya adalah menyimpan data yang di sorot
          ke dalam var data sisip (key)
        * pergeseran posisi data terjadi selama kondisi terpenuhi
    */
    int i, j;
    dessert key; //----------------------------------------> deklarasi struct key sebagai penampung data sisip
    for (i = 1; i < n; i++) { //---------------------------> perulangan sebanyak n-2
        key = arr[i]; //-----------------------------------> data sisip dimulai dari elemen ke 1
        j = i - 1; //--------------------------------------> j dimulai dari 0
        while (j >= 0 && key.kalGram > arr[j].kalGram) { //> selama data sisip > data yg disorot dan penyorot tidak negatif
            swap(&arr[j+1], &arr[j]); //-------------------> tukar tempat (geser data ke kanan)
            j--; //----------------------------------------> decrement sampai -1 agar keluar dari loop
        }
        arr[j + 1] = key;
    }
}

void selection(dessert arr[], int n){
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar data yang memenuhi kondisi
        * jika data > atau < maka terjadi penukaran nilai
        * kondisi yg dimaksud : - data kiri < data kanan
    */
    int i, j, idx;
    for (i = 0; i < n - 1; i++) { //-----------------------> perulangan 0 sampai n-1
        idx = i; //----------------------------------------> inisialisasi idx dengan i
        for (j = i + 1; j < n; j++) { //-------------------> perulangan mengecek data satu persatu
            if (arr[idx].kalGram < arr[j].kalGram) { //----> jika data kiri < data kanan
                idx = j; //--------------------------------> inisialisasi idx dengan posisi data kanan
            }
        }
        swap(&arr[i], &arr[idx]); //-----------------------> tukar data ke i dgn data ke idx
    }
}

void quick(dessert arr[], int left, int right){
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
    double pivot = arr[(right + left) / 2].kalGram;
    //-----^inisialisasi nilai pivot dengan data tengah
    do{
        while (arr[i].kalGram > pivot && i <= j){
            i++;
            // penanda i maju selama data ke-i lebih dari pivot dan nilai i kurang dari j
        }
        while (arr[j].kalGram < pivot && i <= j){
            j--;
            // penanda j mundur selama data ke-j kurang dari pivot dan nilai i kurang dari j
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
            // jika penanda i dan j sudah berhenti, tukar kedua data
            i++; j--; // penanda maju/mundur lagi
        }
    } while (i < j);
    // pembelahan list data terjadi jika nilai i = j
    if((left < j) && (j < right)){
        quick(arr, left, j);
    }
    if((i < right) && (i > left)){
        quick(arr, i, right);
    }
}

void bubble(dessert arr[], int n){
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
        for ( i = 0; i < n-1; i++){ //-----------------> pengecekan seluruh pasangan elemen dalam data
            if (arr[i].kalGram < arr[i+1].kalGram){ //-> jika data kiri lebih kecil dari data kanan
                swap(&arr[i], &arr[i+1]); //-----------> posisi ditukar
                tukar = 1; //--------------------------> tandai bahwa sudah terjadi pertukaran
            }
        }
    } while (tukar == 1); //---------------------------> diulang selama masih terjadi pertukaran data
}

void merge(dessert arr1[], dessert arr2[], int n, int m, dessert result[]){
    /* prosedur untuk menggabungkan dua array yang sudah terurut */
    int i = 0, j = 0, k = 0, l = 0; //----------------> iterator penanda index
    while ((i < n) && (j < m)){ //--------------------> selama i < panjang array1 dan j < panjang array2
        if (arr1[i].kalGram >= arr2[j].kalGram){ //---> jika data array1 lebih dari atau sama dengan data array2
            result[k] = arr1[i]; //-------------------> pindahkan isi struct array1 ke struct hasil(result)
            i++; k++; //------------------------------> increment index kedua array of struct
        }
        if (arr2[j].kalGram >= arr1[i].kalGram){ //---> jika data array2 lebih dari atau sama dengan data array1
            result[k] = arr2[j]; //-------------------> pindahkan isi struct array2 ke struct hasil(result)
            j++; k++; //------------------------------> increment index kedua array of struct
        }
    }
    // jika masih ada sisa data dari pengisian array hasil sebelumnya
    if (i < n){ //------------------------------------> jika sisanya di array1
        for ( l = i; l < n; l++){
            result[k] = arr1[l]; //-------------------> masukkan data sisa ke array hasil
            k++;
        }
    }
    if (j < m){ //------------------------------------> jika sisanya di array2
        for ( l = j; l < m; l++){
            result[k] = arr2[l]; //-------------------> masukkan data sisa ke array hasil
            k++;
        }
    }
}

void output(char negara[50], dessert arr[], int n){
    /* Prosedur mengeluarkan isi array */
    for (int i = 0; i < n; i++){ //------------------------------> diulang sebanyak n pada parameter
        printf("- ");
        if(strcmp(negara, "semua") == 0){ //---------------------> jika prosedur digunakan untu mencetak array hasil
            printf("%s ", arr[i].negara); //---------------------> cetak nama negaranya
        }
        // cetak semua isi array hasil
        printf("%s %d %d %d - ", arr[i].nama, arr[i].kal, arr[i].gram, arr[i].harga);
        if(arr[i].kalGram - (int)arr[i].kalGram != 0){ //--------> jika kalori per gram bukan bilangan bulat
            printf("%0.2lf\n", arr[i].kalGram); //---------------> cetak 2 angka di belakang koma
        } else {
            printf("%0.0lf\n", arr[i].kalGram); //---------------> jika bilangan bulat, hanya cetak bilangan depan
        }
    }
    if(strcmp(negara, "semua") != 0){
        printf("\n"); //-----------------------------------------> cetak baris baru jika tidak menampilkan array hasil
    }
}