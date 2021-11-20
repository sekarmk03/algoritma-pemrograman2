#include "header.h"

void input(data d[], int n){
    /* prosedur menginput data mahasiswa */
    for(int i = 0; i < n; i++){
        scanf("%s%d", d[i].nama, &d[i].m); //--------> meminta masukan nama dan jumlah nilai
        int sum = 0; //------------------------------> variabel penghitung total nilai
        for(int j = 0; j < d[i].m; j++){
            scanf("%d", &d[i].score[j]); //----------> memasukkan nilai sebanyak jumlah yg ditentukan
            sum += d[i].score[j]; //-----------------> menjumlahkan seluruh nilai
        }
        d[i].mean = (double)sum / d[i].m; //---------> menghitung rata-rata nilai
    }
}

int sorted(data d[], int n){
    /* prosedur pengecekan nama sorted/unsorted */
    int i = 0, mark = 1;
    //---------^ penanda nilai masih terurut (kiri < kanan)
    //--^ iterator & index
    while(i < n && mark == 1 && i+1 < n){ //---------> diulang sampai ada nama yg tidak terurut
        if(strcmp(d[i].nama, d[i+1].nama) < 0){ //---> pengecekan apakah nama saat ini (i) < nama setelahnya (i+1)
            mark = 1; //-----------------------------> jika iya maka terurut
        } else {
            mark = 0; //-----------------------------> jika tidak, maka tidak terurut, perulangan berhenti
        }
        i++;
    }
    return mark; //----------------------------------> terurut : return 1, tidak terurut : return 0 (dari var mark)
}

data seqSearch(data d[], int n, int search){
    /* prosedur sequential search */
    /* untuk pencarian data unsorted */
    int i = 0;
    while(i != search && i < n){ //------------------> selama index yg dicari belum ketemu
        i++; //--------------------------------------> increment index
    }
    return d[i]; //----------------------------------> return data struct index yg dicari jika indexnya ketemu (loop berhenti)
}

data binSearch(data d[], int left, int right, int search){
    /* prosedur binary search */
    /* untuk pencarian data sorted */
    int mid = (right - left) / 2 + left; //----------> cari tengah-tengahnya, simpan di var mid
    if(mid == search){ //----------------------------> jika index tengah sama dengan index yg dicari
        return d[mid]; //----------------------------> return data struct index yg dicari (karena sudah ketemu)
    } else if(mid > search){ //----------------------> jika index tengah < index yg dicari
        return binSearch(d, left, mid-1, search); //-> bagi dua array, fokus ke pencarian index di array bagian kiri
    } else { //--------------------------------------> jika index tengah > index yg dicari
        return binSearch(d, mid+1, right, search); //> bagi dua array, fokus ke pencarian index di array bagian kanan
    }
}

void swap(data *awal, data *akhir){
    /*
        * prosedur untuk menukar data dalam struct
        * digunakan dalam prosedur sorting
    */
    data temp; //------------------------------------> penampung sementara
    temp = *awal; //---------------------------------> data awal ditampung
    *awal = *akhir; //-------------------------------> data akhir dipindah ke data awal
    *akhir = temp; //--------------------------------> data tampungan dipindah ke data akhir
}

void selectionSort(data d[], int n){
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar data yang memenuhi kondisi
        * jika data idx > data ke-j maka terjadi penukaran nilai
    */
    int i, j, idx;
    //--------^ penanda index yg dicek
    //--^--^ iterator
    for (i = 0; i < n - 1; i++) {
        idx = i; //----------------------------------> inisialisasi nilai idx dengan i
        for (j = i + 1; j < n; j++) {
            if (d[idx].mean > d[j].mean) { //--------> jika data kiri > data kanan
                idx = j; //--------------------------> inisialisasi idx dengan posisi data kanan
            }
        }
        swap(&d[i], &d[idx]); //---------------------> tukar data ke-i dengan data ke-idx
    }
}

void output(data d[], int n, data res){
    /* prosedur mencetak output */
    for(int i = 0; i < n; i++){
        printf("%s\n", d[i].nama); //----------------> mencetak urutan nama berdasarkan rata-rata nilai (ascending)
    }
    printf("\nYang Diminta : %s\n", res.nama); //----> mencetak nama yg indexnya dicari
}