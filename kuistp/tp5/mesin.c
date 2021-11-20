#include "header.h"

void swap(pecahan *awal, pecahan *akhir){
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam bubble sort dan quick sort
    */
    pecahan temp; //----> penampung sementara
    temp = *awal; //----> data 1 ditampung
    *awal = *akhir; //--> data 2 dipindah ke data 1
    *akhir = temp; //---> data tampungan dipindah ke data 2
}

void bubbleSort(pecahan frac[], int n, char by){
    /*
        * prosedur bubble sort
        * cara kerjanya dengan mengecek dua elemen yg bersebelahan
        * jika lebih besar/kecil (tergantung kondisi), maka
          akan ditukar posisinya
        * KOMENTAR PENJELASAN HANYA ADA DI BLOK ASCENDING
    */
    int i, temp, tukar;
    //-----------^penanda terjadi pertukaran
    //-----^penampung sementara
    do{
        tukar = 0;
        // pengecekan seluruh pasangan elemen dalam data
        for ( i = 0; i < n-1; i++){
            if(by == 'a'){
                // pengecekan kondisi
                // jika data kiri lebih besar dari data kanan
                if (frac[i].hasil > frac[i+1].hasil){
                    // posisi ditukar
                    swap(&frac[i], &frac[i+1]);
                    // tandai bahwa sudah terjadi pertukaran
                    tukar = 1;
                }
            } else {
                // jika data kiri lebih kecil dari data kanan
                if (frac[i].hasil < frac[i+1].hasil){
                    swap(&frac[i], &frac[i+1]);
                    tukar = 1;
                }
            }
        }
        // akan terus diulang selama masih terjadi pertukaran
    } while (tukar == 1);
}

void qsTengah(pecahan frac[], int kiri, int kanan, char by){
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
    int i = kiri, j = kanan;
    //--^---------^inisalisasi nilai penanda i dan j dengan data paling kiri dan paling kanan
    double pivot = frac[(kanan + kiri) / 2].hasil;
    //-----^inisialisasi nilai pivot dengan data tengah
    do{
        // diulang selama i < j
        if(by == 'a'){
            // jika user memilih ascending ('a')
            while (frac[i].hasil < pivot && i <= j){
                // penanda i maju selama data ke-i kurang dari pivot
                // dan nilai i kurang dari j
                i++;
            }
            while (frac[j].hasil > pivot && i <= j){
                // penanda j mundur selama data ke-j lebih dari pivot
                // dan nilai i kurang dari j
                j--;
            }
        } else {
            // jika user memilih descending ('d')
            while (frac[i].hasil > pivot && i <= j){
                // penanda i maju selama data ke-i lebih dari pivot
                // dan nilai i kurang dari j
                i++;
            }
            while (frac[j].hasil < pivot && i <= j){
                // penanda j mundur selama data ke-j kurang dari pivot
                // dan nilai i kurang dari j
                j--;
            }
        }
        // jika penanda i dan j sudah berhenti, tukar kedua data
        if(i < j){
            swap(&frac[i], &frac[j]);
            // penanda maju/mundur lagi
            i++; j--;
        }
    } while (i < j);
    // pembelahan list data
    // terjadi jika nilai i = j
    if((kiri < j) && (j < kanan)){
        // jika nilai batas kiri < nilai penanda j
        // dan nilai j kurang dari batas kanan
        qsTengah(frac, kiri, j, by);
        // ganti nilai batas kanan menjadi j
    }
    if((i < kanan) && (i > kiri)){
        // jika nilai i < nilai penanda i
        // dan nilai i > batas kiri
        qsTengah(frac, i, kanan, by);
        // ganti nilai batas kiri menjadi i
    }
}

void cetak(pecahan frac[], int n){
    /*
        * prosedur mencetak sesuai permintaan soal
        * input
                5
                2 6
                3 6
                3 7
                3 1
                8 4
                b
                a
        * output
                2   3   3   8   3
                - , - , - , - , -
                6   7   6   4   1
    */
    for (int i = 0; i < n; i++){
        printf("%.0lf", frac[i].num);
        if(i < n-1)
            printf("   ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("-");
        if(i < n-1)
            printf(" , ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%.0lf", frac[i].den);
        if(i < n-1)
            printf("   ");
    }
    printf("\n");
}