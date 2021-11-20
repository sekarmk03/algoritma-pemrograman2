#include "header.h"

void swap(mhs *awal, mhs *akhir){
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam setiap metode sorting
    */
    mhs temp; //----> penampung sementara
    temp = *awal; //----> data awal ditampung
    *awal = *akhir; //--> data akhir dipindah ke data awal
    *akhir = temp; //---> data tampungan dipindah ke data akhir
}

void input(mhs arr[], int n){
    /* Prosedur untuk menginput data ke dalam struct mhs */
    for (int i = 0; i < n; i++){
        // loop diulang sebanyak n (banyak data)
        // menerima inputan nama, nilai 1, dan nilai 2
        scanf("%s%d%d", &arr[i].nama, &arr[i].nilai1, &arr[i].nilai2);
    }
}

void quick(mhs arr[], int left, int right){
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
    char pivot[50];
    strcpy(pivot, arr[(right + left) / 2].nama);
    //-----^inisialisasi nilai pivot dengan data tengah
    do{
        while (strcmp(arr[i].nama, pivot) < 0 && i <= j){
            i++;
            // penanda i maju selama data ke-i kurang dari pivot dan nilai i kurang dari j
        }
        while (strcmp(arr[j].nama, pivot) > 0 && i <= j){
            j--;
            // penanda j mundur selama data ke-j lebih dari pivot dan nilai i kurang dari j
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

void merge(mhs arr1[], mhs arr2[], int n, int m, mhs result[]){
    /* prosedur untuk menggabungkan dua array yang sudah terurut */
    int i = 0, j = 0, k = 0, l = 0; //----------------> iterator penanda index
    while ((i < n) && (j < m)){ //--------------------> selama i < panjang array1 dan j < panjang array2
        if (strcmp(arr1[i].nama, arr2[j].nama) <= 0){ //---> jika data array1 kurang dari atau sama dengan data array2
            result[k] = arr1[i]; //-------------------> pindahkan isi struct array1 ke struct hasil(result)
            i++; k++; //------------------------------> increment index kedua array of struct
        }
        if (strcmp(arr2[j].nama, arr1[i].nama) <= 0){ //---> jika data array2 kurang dari atau sama dengan data array1
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

void output(mhs arr[], int n, int start){
    /* prosedur mencetak hasil sesuai spesifikasi */
    printf("================\n");
    // inisialisasi nilai i sesuai nilai start pada parameter
    for(int i = start; i < n; i++){
        printf("%s %d %d\n", arr[i].nama, arr[i].nilai1, arr[i].nilai2);
    }
}