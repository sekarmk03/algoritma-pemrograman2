/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP8
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char judul[50]; //-------> untuk menyimpan judul film
    char sutradara[50]; //---> untuk menyimpan nama sutradara
    char genre[20]; //-------> untuk menyimpan data genre
    char bioskop[20]; //-----> untuk menyimpan data bioskop
}dataFilm; //----------------> inisialisasi nama struct

typedef struct 
{
    char kode[10]; //--------> untuk menyimpan data kode
    char definisi[30]; //----> untuk menyimpan definisi kode
}dataKode; //----------------> inisialisasi nama struct

/* Variabel Global */
int len[4][50]; //-----------> menyimpan panjang string per kolom
int max[4]; //---------------> menyimpan string terpanjang tiap kolom
int pilih; //----------------> menyimpan pilihan menu user

/* Prosedur & Fungsi */
void mainProcess(dataFilm ListFilm[], dataKode ListSutradara[], dataKode ListGenre[], dataKode ListBioskop[], FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop, FILE *final);
// prosedur menampilkan tabel
void Menu(); //------------------------------------------------------------> prosedur menampilkan menu
int readFilm(FILE *film, dataFilm d[]); //---------------------------------> fungsi baca file ListFilm.dat
int readKode(FILE *file, dataKode d[], char namaFile[]); //----------------> fungsi baca file Sutradara.dat, Genre.dat, Bioskop.dat
int search(char search[], dataKode data[], int n); //----------------------> fungsi mencari kode
void output(dataFilm fin[], int n); //-------------------------------------> fungsi mencetak isi file ListFilmFinal.dat
int Max(int idx, int n); //------------------------------------------------> fungsi mencari string terpanjang per kolom
void batas(int n); //------------------------------------------------------> prosedur pencetak batas tabel
void addFilm(dataFilm ListFilm[]); //--------------------------------------> prosedur menambahkan data ke ListFilm.dat
void writeKode(FILE *file, dataKode ListKode[], int n, char namaFile[]); //> prosedur menulis data ke Sutradara.dat, Genre.dat, Bioskop.dat
void addKode(dataKode ListKode[], char namaFile[]); //---------------------> prosedur menambahkan data ke Sutradara.dat, Genre.dat, Bioskop.dat