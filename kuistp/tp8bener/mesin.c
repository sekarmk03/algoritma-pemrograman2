#include "header.h"

/* prosedur menambah data ke ListFilmFinal dan menampilkannya */
void mainProcess(dataFilm ListFilm[], dataKode ListSutradara[], dataKode ListGenre[], dataKode ListBioskop[], FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop, FILE *final)
{
    film = fopen("ListFilm.dat", "r");                           //---------)
    sutradara = fopen("Sutradara.dat", "r");                     //---)_______________________ buka file mode read
    genre = fopen("Genre.dat", "r");                             //-----------)
    bioskop = fopen("Bioskop.dat", "r");                         //-------)
    int a = readFilm(film, ListFilm);                            //----------------------------)
    int b = readKode(sutradara, ListSutradara, "Sutradara.dat"); //-)_____ baca file
    int c = readKode(genre, ListGenre, "Genre.dat");             //-------------)
    int d = readKode(bioskop, ListBioskop, "Bioskop.dat");       //-------)
    fclose(film);                                                //------------------------)
    fclose(sutradara);                                           //-------------------)_____________________________ tutup file
    fclose(genre);                                               //-----------------------)
    fclose(bioskop);                                             //---------------------)
    dataFilm Final[a];                                           //------------------------------------------------> penyimpan data file ListFilmFinal.dat
    final = fopen("ListFilmFinal.dat", "w");                     //--------------------------> buka file mode write
    for (int i = 0; i < a; i++)
    { //---------------------------------------> diulang sebanyak data ListFilm.dat
        /* proses memasukkan data dari ListFilm.dat ke ListFilmFinal.dat */
        strcpy(Final[i].judul, ListFilm[i].judul); //--------------------> masukkan data judul
        len[0][i] = strlen(Final[i].judul);        //---------------------------> simpan panjangnya
        strcpy(Final[i].sutradara, ListSutradara[search(ListFilm[i].sutradara, ListSutradara, b)].definisi);
        //-------------------------^pindahkan----^cari--^id dari ListFilm.dat--^cari definisi di Sutradara.dat
        len[1][i] = strlen(Final[i].sutradara);
        strcpy(Final[i].genre, ListGenre[search(ListFilm[i].genre, ListGenre, c)].definisi);
        len[2][i] = strlen(Final[i].genre);
        strcpy(Final[i].bioskop, ListBioskop[search(ListFilm[i].bioskop, ListBioskop, d)].definisi);
        len[3][i] = strlen(Final[i].bioskop);
        /* proses memasukkan data ke dalam file */
        fprintf(final, "%s %s %s %s\n", Final[i].judul, Final[i].sutradara, Final[i].genre, Final[i].bioskop);
    }
    fprintf(final, "%s %s %s %s\n", "####", "####", "####", "####"); //--> masukkan EOF
    fclose(final);                                                   //----------------------------------------------------> tutup file
    output(Final, a);                                                //-------------------------------------------------> cetak tabel
}

/* prosedur membaca data file ListFilm.dat */
int readFilm(FILE *film, dataFilm d[])
{
    int i = 0;
    fscanf(film, "%s %s %s %s", d[i].judul, d[i].sutradara, d[i].genre, d[i].bioskop); //----> baca data baris pertama
    if (strcmp(d[i].judul, "####") == 0)
    { //--------------------------------------------------> jika baris pertama EOF
        printf("Data 'ListFilm.dat' kosong.\nSilakan masukkan data :\n");
        addFilm(d);                                                                        //-----------------------------------------------------------------------> tambahkan data karena file kosong
        film = fopen("ListFilm.dat", "r");                                                 //------------------------------------------------> buka file
        system("cls");                                                                     //--------------------------------------------------------------------> bersihkan layar setelah menambah data
        fscanf(film, "%s %s %s %s", d[i].judul, d[i].sutradara, d[i].genre, d[i].bioskop); //> baca dan simpan data baris pertama
    }
    while (strcmp(d[i].judul, "####") != 0)
    { //-----------------------------------------------> selama data bukan EOF
        i++;
        fscanf(film, "%s %s %s %s", d[i].judul, d[i].sutradara, d[i].genre, d[i].bioskop); //> baca dan simpan data baris berikutnya
    }
    return i; //-----------------------------------------------------------------------------> return jumlah data
}

/* prosedur membaca data file Sutradara.dat, Genre.dat, Bioskop.dat */
// komentar penjelasan -+ sama dengan prosedur readFilm
int readKode(FILE *file, dataKode d[], char namaFile[])
{
    int i = 0;
    fscanf(file, "%s %s", d[i].kode, d[i].definisi);
    if (strcmp(d[i].kode, "####") == 0)
    {
        printf("Data '%s' kosong.\nSilakan masukkan data :\n", namaFile);
        writeKode(file, d, 0, namaFile);
        file = fopen(namaFile, "r");
        system("cls");
        fscanf(file, "%s %s", d[i].kode, d[i].definisi);
    }
    while (strcmp(d[i].kode, "####") != 0)
    {
        i++;
        fscanf(file, "%s %s", d[i].kode, d[i].definisi);
    }
    return i;
}

/* prosedur mencari string terpanjang per kolom */
int Max(int idx, int n)
{
    max[idx] = len[idx][0]; //----------> inisialisasi panjang maksimal awal
    for (int i = 0; i < n; i++)
    { //------> diulang sebanyak baris data
        if (max[idx] < len[idx][i])
        {                           //--> jika string ke-i lebih panjang
            max[idx] = len[idx][i]; //--> update panjang maksimal
        }
    }
    return max[idx]; //-----------------> return panjang maksimal
}

/* prosedur mencari definisi dari id/kode */
int search(char search[], dataKode data[], int n)
{
    int i = 0;
    while (strcmp(search, data[i].kode) != 0)
    {        //--> sequential search
        i++; //-----------------------------------> increment selama belum ketemu
    }
    return i; //----------------------------------> return index dimana data ditemukan
}

/* prosedur pembuat batas baris tabel atas bawah */
void batas(int n)
{
    printf("+"); //--------------------> pembatas antar kolom
    for (int j = 0; j < 2 + n; j++)
    {                //-> sebanyak panjang string terpanjang + 2
        printf("-"); //----------------> strip dicetak
    }
}

/* prosedur pencetak judul kolom dalam tabel */
void thead(int a, int b, int c, int d)
{
    char h1[] = "Judul_Film", h2[] = "Sutradara", h3[] = "Genre", h4[] = "Bioskop";
    //---^judul kolom 1-------^judul kolom 2------^judul kolom 3--^judul kolom 4
    printf("| ");
    for (int i = 0; i < (a - strlen(h1)) / 2; i++)
    {
        // agar judul kolom rata tengah, print spasi sebanyak
        // (stringterpanjang-panjangjudul) / 2
        printf(" ");
    }
    printf("%s", h1); // cetak judul
    for (int i = (a - strlen(h1)) / 2; i < (a - strlen(h1)); i++)
    {
        // print sisa spasinya
        printf(" ");
    }
    /* komentar penjelasan -+ sama dengan line 106 - 116 */
    printf(" | ");
    for (int i = 0; i < (b - strlen(h2)) / 2; i++)
    {
        printf(" ");
    }
    printf("%s", h2);
    for (int i = (b - strlen(h2)) / 2; i < (b - strlen(h2)); i++)
    {
        printf(" ");
    }
    printf(" | ");
    for (int i = 0; i < (c - strlen(h3)) / 2; i++)
    {
        printf(" ");
    }
    printf("%s", h3);
    for (int i = (c - strlen(h3)) / 2; i < (c - strlen(h3)); i++)
    {
        printf(" ");
    }
    printf(" | ");
    for (int i = 0; i < (d - strlen(h4)) / 2; i++)
    {
        printf(" ");
    }
    printf("%s", h4);
    for (int i = (d - strlen(h4)) / 2; i < (d - strlen(h4)); i++)
    {
        printf(" ");
    }
    printf(" |\n");
}

/* prosedur mencetak data tabel */
void output(dataFilm fin[], int n)
{
    int a = Max(0, n), b = Max(1, n), c = Max(2, n), d = Max(3, n); //--> inisialisasi nilai string terpanjang per kolom
    if (d < 7)
    {
        // jika string terpanjang kolom terakhir
        // kurang dari judul ("Bioskop")
        d = 7; // string terpanjang = panjang judul
    }
    batas(a);
    batas(b);
    batas(c);
    batas(d);
    printf("+\n");     //-----------> cetak batas atas baris judul
    thead(a, b, c, d); //-----------------------------------------------> cetak judul kolom
    batas(a);
    batas(b);
    batas(c);
    batas(d);
    printf("+\n"); //-----------> cetak batas bawah baris judul
    for (int i = 0; i < n; i++)
    {                                 //--------------------------------------> diulang sebanyak baris data dalam file
        printf("| %s", fin[i].judul); //--------------------------)
        if (strlen(fin[i].judul) < a)
        { //--------------------------)
            for (int j = strlen(fin[i].judul); j < a; j++)
            {                //-----)-----> data kolom judul
                printf(" "); //-----------------------------------)
            }                //--------------------------------------------------)
        }
        printf(" | %s", fin[i].sutradara); //---------------------)
        if (strlen(fin[i].sutradara) < b)
        { //----------------------)
            for (int j = strlen(fin[i].sutradara); j < b; j++)
            {                //-)-----> data kolom sutradara
                printf(" "); //-----------------------------------)
            }                //--------------------------------------------------)
        }
        printf(" | %s", fin[i].genre); //-------------------------)
        if (strlen(fin[i].genre) < c)
        { //--------------------------)
            for (int j = strlen(fin[i].genre); j < c; j++)
            {                //-----)-----> data kolom genre
                printf(" "); //-----------------------------------)
            }                //--------------------------------------------------)
        }
        printf(" | %s", fin[i].bioskop); //-----------------------)
        if (strlen(fin[i].bioskop) < d)
        { //------------------------)
            for (int j = strlen(fin[i].bioskop); j < d; j++)
            {                //---)-----> data kolom bioskop
                printf(" "); //-----------------------------------)
            }                //--------------------------------------------------)
        }
        printf(" |\n");
        batas(a);
        batas(b);
        batas(c);
        batas(d);
        printf("+\n"); //-------> cetak batas bawah tiap baris data
    }
}

/* prosedur menampilkan menu pilihan */
void Menu()
{
    printf("\n");
    printf("MENU\n");
    printf("1. Tambah data film\n");
    printf("2. Tambah data sutradara\n");
    printf("3. Tambah data genre\n");
    printf("4. Tambah data bioskop\n");
    printf("5. Keluar\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &pilih); //meminta masukan pilihan user
}

/* prosedur menambah data ke file ListFilm.dat */
void addFilm(dataFilm ListFilm[])
{
    FILE *film;                        //------------------------------------> inisialisasi file ListFilm.dat
    film = fopen("ListFilm.dat", "r"); //-------------> buka file mode read
    int i = 0, a = 0;
    // baca dan simpan data baris pertama
    fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    while (strcmp(ListFilm[a].judul, "####") != 0)
    { //-> selama baris yang dibaca bukan EOF
        a++;
        // baca dan simpan data baris berikutnya sampai EOF
        fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    }
    // tambahkan data baru ke array penyimpan data
    scanf("%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    while (strcmp(ListFilm[a].judul, "####") != 0)
    { //-> selama data yang ditambahkan buka EOF
        a++;
        // tambahkan data untuk baris berikutnya
        scanf("%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    }
    fclose(film);                      //----------------------------------> tutup file
    film = fopen("ListFilm.dat", "w"); //-------------> buka file mode write
    for (i = 0; i < a; i++)
    {
        // masukkan data dari array ke file satu per satu
        fprintf(film, "%s %s %s %s\n", ListFilm[i].judul, ListFilm[i].sutradara, ListFilm[i].genre, ListFilm[i].bioskop);
    }
    // masukkan EOF
    fprintf(film, "%s %s %s %s\n", "####", "####", "####", "####");
    fclose(film); //----------------------------------> tutup file
}

void addKode(dataKode ListKode[], char namaFile[])
{
    FILE *filekode;                                 //---------------------------------> inisialisasi file
    filekode = fopen(namaFile, "r");                //----------------> buka file mode read
    int n = readKode(filekode, ListKode, namaFile); //-> baca file, simpan banyak datanya
    fclose(filekode);                               //-------------------------------> tutup file
    writeKode(filekode, ListKode, n, namaFile);     //-----> panggil prosedur untuk menulis data
    fclose(filekode);                               //-------------------------------> tutup file
}

/* prosedur menulis data ke file Sutradara.dat, Genre.dat, Bioskop.dat */
void writeKode(FILE *file, dataKode ListKode[], int n, char namaFile[])
{
    scanf("%s %s", ListKode[n].kode, ListKode[n].definisi); //--------------> menambah data baru (indeks melanjutkan data sebelumnya)
    while (strcmp(ListKode[n].kode, "####") != 0)
    { //------------------------> selama data yang ditambahkan bukan EOF
        n++;
        scanf("%s %s", ListKode[n].kode, ListKode[n].definisi); //----------> tambah data berikutnya
    }
    fclose(file);                //--------------------------------------------------------> tutup file
    file = fopen(namaFile, "w"); //-----------------------------------------> buka file mode write
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s %s\n", ListKode[i].kode, ListKode[i].definisi); //> masukkan data dari array ke file satu per satu
    }
    fprintf(file, "%s %s\n", "####", "####"); //----------------------------> masukkan data EOF
    fclose(file);                             //--------------------------------------------------------> tutup file
}
