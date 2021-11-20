#include "header.h"

// prosedur mulai pembacaan kata
void startKata(char pita[])
{
    idx = 0;                 // pembacaan dimulai dari karakter index ke-0
    pKata = 0;               // inisialisasi panjang kata awal (juga sbg penanda index cKata)
    while (pita[idx] == ' ') // selama bertemu karakter spasi
    {                        // increment index sampai mencapai karakter bukan spasi
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {                             // selama bukan karakter spasi dan bukan akhir kalimat
        cKata[pKata] = pita[idx]; // pindahkan karakter ke penampung kata
        idx++;                    // increment karakter kalimat
        pKata++;                  // increment index penampung kata
    }
    cKata[pKata] = '\0'; // akhiri kata
}

// prosedur menghapus kata
void resetKata()
{
    pKata = 0;           // index ke-0 penampung kata
    cKata[pKata] = '\0'; // dibuat tanpa karakter atau diakhiri
}

// prosedur memajukan kata
void incKata(char pita[])
{
    pKata = 0;               // mulai dari index ke-0 penampung kata
    while (pita[idx] == ' ') // selama bertemu karakter spasi
    {                        // increment sampai bertemu karakter bukan spasi
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {                             // selama bukan karakter spasi dan bukan akhir kalimat
        cKata[pKata] = pita[idx]; // pindahkan karakter ke penampung kata
        idx++;                    // increment karakter kalimat
        pKata++;                  // increment index penampung kata
    }
    cKata[pKata] = '\0'; // akhiri kata
}

// fungsi mengambil kata yang sedang dibaca
char *getCKata()
{
    return cKata; // ambil nilai penampung kata saat ini
}

// fungsi mengambil panjang kata
int getPKata()
{
    return pKata; // ambil panjang penampung kata saat ini
}

// fungsi pendeteksi akhir kalimat
int eopKata(char pita[])
{
    if (pita[idx] == ';') // jika bertemu titik koma
        return 1;         // kembalikan 1 (akhir kalimat)
    else                  // jika tidak // (sebenarnya ngga perlu else lagi, langsung return 0, tapi di vscode error)
        return 0;         // kembalikan 0 (bukan akhir)
}

// fungsi penentu jenis query (insert/cari/tampilkan)
int requestQuery(char pita[])
{
    startKata(pita); // membaca kata pertama
    if (strcmp(getCKata(), "TAMPILKAN") == 0)
        return 0; // jika query tampilkan akan mengembalikan 0
    if (strcmp(getCKata(), "INSERT") == 0)
        return 1; // jika query insert akan mengembalikan 1
    if (strcmp(getCKata(), "CARI") == 0)
        return 2; // jika query cari akan mengembalikan 2
}

// prosedur menambahkan data
void insertData(char pita[], kereta *dataKereta)
{
    int count = 0; // menandakan kolom
    while (eopKata(pita) == 0)
    {
        incKata(pita);  // majukan baca pita
        if (count == 0) // untuk kolom 1
            strcpy(dataKereta->id, getCKata());
        else if (count == 1) // untuk kolom 2
            strcpy(dataKereta->nama, getCKata());
        count++;
    }
    strcpy(dataKereta->kelas, getCKata()); // untuk kolom 3
}

// prosedur mencari data
void cariData(char pita[], kereta dataKereta[], int n, kereta hasil[], int *found)
{
    int it = -1, start = 0;
    //-----------^awal index binary search
    //--^iterator penanda index
    if (eopKata(pita) == 0)
    {
        char atribut[30];
        incKata(pita);               // majukan membaca kata
        strcpy(atribut, getCKata()); // simpan kata saat ini sbg atribut yg dicari
        if (eopKata(pita) == 0)
        {
            incKata(pita); // majukan membaca kata
            for (int i = 0; i < n; i++)
            {
                it = binSearch(dataKereta, getCKata(), start, n, atribut); // cari data
                if (it != -1)                                              // jika ketemu
                {
                    hasil[*found] = dataKereta[it]; // simpan ke struct hasil
                    ++*found;                       // found sbg penanda jumlah data di struct hasil
                    start = it + 1;                 // ubah awal index binary seacrh
                }
            }
        }
    }
}

// fungsi binary search
int binSearch(kereta table[], char search[], int left, int right, char atribut[])
{
    if (strcmp(atribut, "id") == 0)
    {
        if (right >= left) // jika batas data terakhir >= batas data pertama
        {
            int mid = (right - left) / 2 + left;                          // cari tengah-tengahnya, simpan di var mid
            if (strcmp(table[mid].id, search) == 0)                       // jika index tengah sama dengan index yg dicari
                return mid;                                               // return data struct index yg dicari (karena sudah ketemu)
            else if (strcmp(table[mid].id, search) > 0)                   // jika index tengah > index yg dicari
                return binSearch(table, search, left, mid - 1, atribut);  // bagi dua array, fokus mencari di array bagian kiri
            else if (strcmp(table[mid].id, search) < 0)                   // jika index tengah < index yg dicari
                return binSearch(table, search, mid + 1, right, atribut); // bagi dua array, fokus mencari di array bagian kanan
        }
        return -1; // jika data tidak ditemukan, kembalikan nilai -1
    }
    if (strcmp(atribut, "nama") == 0)
    {
        if (right >= left) // jika batas data terakhir >= batas data pertama
        {
            int mid = (right - left) / 2 + left;                          // cari tengah-tengahnya, simpan di var mid
            if (strcmp(table[mid].nama, search) == 0)                     // jika index tengah sama dengan index yg dicari
                return mid;                                               // return data struct index yg dicari (karena sudah ketemu)
            else if (strcmp(table[mid].nama, search) > 0)                 // jika index tengah > index yg dicari
                return binSearch(table, search, left, mid - 1, atribut);  // bagi dua array, fokus mencari di array bagian kiri
            else if (strcmp(table[mid].nama, search) < 0)                 // jika index tengah < index yg dicari
                return binSearch(table, search, mid + 1, right, atribut); // bagi dua array, fokus mencari di array bagian kanan
        }
        return -1; // jika data tidak ditemukan, kembalikan nilai -1
    }
    if (strcmp(atribut, "kelas") == 0)
    {
        if (right >= left) // jika batas data terakhir >= batas data pertama
        {
            int mid = (right - left) / 2 + left;                          // cari tengah-tengahnya, simpan di var mid
            if (strcmp(table[mid].kelas, search) == 0)                    // jika index tengah sama dengan index yg dicari
                return mid;                                               // return data struct index yg dicari (karena sudah ketemu)
            else if (strcmp(table[mid].kelas, search) > 0)                // jika index tengah > index yg dicari
                return binSearch(table, search, left, mid - 1, atribut);  // bagi dua array, fokus mencari di array bagian kiri
            else if (strcmp(table[mid].kelas, search) < 0)                // jika index tengah < index yg dicari
                return binSearch(table, search, mid + 1, right, atribut); // bagi dua array, fokus mencari di array bagian kanan
        }
        return -1; // jika data tidak ditemukan, kembalikan nilai -1
    }
}

// fungsi mencari panjang string terpanjang
int Max(int arr[], int n)
{
    int mx = arr[0]; // inisialisasi mx dengan panjang string pertama
    for (int i = 0; i < n; i++)
    {
        if (mx < arr[i]) // jika array ke-i > dari mx
            mx = arr[i];
    }
    return mx; // kembalikan nilai terbesar
}

// prosedur mengubah data kolom struct menjadi array
void toArray(kereta tbl[], int n)
{
    int arrTbl[4][n], i = 0;
    max[0] = 0;
    max[1] = 0;
    max[2] = 0;
    for (i = 0; i < n; i++) // proses memindahkan panjang string per kolom ke array
    {
        arrTbl[0][i] = strlen(tbl[i].id);
        arrTbl[1][i] = strlen(tbl[i].nama);
        arrTbl[2][i] = strlen(tbl[i].kelas);
    }
    max[0] = Max(arrTbl[0], n); // mengembalikan panjang string terpanjang kolom 1
    max[1] = Max(arrTbl[1], n); // mengembalikan panjang string terpanjang kolom 2
    max[2] = Max(arrTbl[2], n); // mengembalikan panjang string terpanjang kolom 3
}

// mencetak pembatas tabel tampilan
void batas()
{
    for (int i = 0; i < max[0] + max[1] + max[2] + 10; i++)
        printf("=");
    printf("\n");
}

// membuat tabel dan menampilkan data
void tampilData(kereta dataTampil[], int n)
{
    strcpy(dataTampil[n].id, "ID_Kereta");     // copy string header kolom 1
    strcpy(dataTampil[n].nama, "Nama_Kereta"); // copy string header kolom 2
    strcpy(dataTampil[n].kelas, "Kelas");      // copy string header kolom 3
    toArray(dataTampil, n + 1);                // data tampil diubah jadi array dulu untuk dicari panjang max string
    printf("TABEL HASIL PENCARIAN\n");
    // menampilkan header tabel
    batas();
    printf("| ID Kereta ");
    for (int i = 0; i < max[0] - strlen("ID_Kereta"); i++)
        printf(" ");
    printf("| Nama Kereta ");
    for (int i = 0; i < max[1] - strlen("Nama_Kereta"); i++)
        printf(" ");
    printf("| Kelas ");
    for (int i = 0; i < max[2] - strlen("Kelas"); i++)
        printf(" ");
    printf("|\n");
    batas();
    // menampilkan isi tabel
    for (int j = 0; j < n; j++)
    {
        printf("| %s ", dataTampil[j].id);
        for (int i = 0; i < max[0] - strlen(dataTampil[j].id); i++)
            printf(" ");
        printf("| %s ", dataTampil[j].nama);
        for (int i = 0; i < max[1] - strlen(dataTampil[j].nama); i++)
            printf(" ");
        printf("| %s ", dataTampil[j].kelas);
        for (int i = 0; i < max[2] - strlen(dataTampil[j].kelas); i++)
            printf(" ");
        printf("|\n");
    }
    batas();
    printf("%d data dalam tabel.\n", n);
}