#include "header.h"

int main(){
    while(pilih != 5){ //--------------------------------------> diulang selama nilai var pilih bukan 5
        system("cls"); //--------------------------------------> membersihkan layar
        dataFilm ListFilm[50]; //------------------------------> penyimpan data file ListFilm.dat
        dataKode ListSutradara[50], ListGenre[50], ListBioskop[50];
        //-----------------------------------------^penyimpan data file Bioskop.dat
        //--------------------------^penyimpan data file Genre.dat
        //-------^penyimpan data file Sutradara.dat
        FILE *film, *sutradara, *genre, *bioskop, *final;
        //----------------------------------------^inisialisasi file ListFilmFinal.dat
        //------------------------------^inisialisasi file Bioskop.dat
        //----------------------^inisialisasi file Genre.dat
        //----------^inisialisasi file Sutradara.dat
        //---^inisialisasi file ListFilm.dat
        mainProcess(ListFilm, ListSutradara, ListGenre, ListBioskop, film, sutradara, genre, bioskop, final);
        // memanggil prosedur pengisi file ListFilmFinal awal dan menampilkan isinya
        Menu(); //---------------------------------------------> menampilkan pilihan menu
        switch (pilih){ //-------------------------------------> kondisi sesuai pilihan user
        case 1: //---------------------------------------------> jika user memilih 1
            printf("Masukkan data film :\n");
            addFilm(ListFilm); //------------------------------> prosedur menambahkan data ke ListFilm.dat
            break;
        case 2: //---------------------------------------------> jika user memilih 2
            printf("Masukkan data sutradara (Sxxx) :\n");
            addKode(ListSutradara, "Sutradara.dat"); //--------> prosedur menambahkan data ke Sutradara.dat
            break;
        case 3: //---------------------------------------------> jika user memilih 3
            printf("Masukkan data genre (Gxxx) :\n");
            addKode(ListGenre, "Genre.dat"); //----------------> prosedur menambahkan data ke Genre.dat
            break;
        case 4: //---------------------------------------------> jika user memilih 4
            printf("Masukkan data bioskop (Bxxx) :\n");
            addKode(ListBioskop, "Bioskop.dat"); //------------> prosedur menambahkan data ke Bioskop.dat
            break;
        default: //--------------------------------------------> selain 1,2,3,4
            pilih = 5; //--------------------------------------> user dianggap memilih 5, loop while berhenti
            break;
        }
    }
    return 0; //-----------------------------------------------> keluar dari program
}