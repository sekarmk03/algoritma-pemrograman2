#include "header.h"

int main(){
    dataFilm ListFilm[50];
    dataKode ListSutradara[50];
    dataKode ListGenre[50];
    dataKode ListBioskop[50];
    FILE *film, *sutradara, *genre, *bioskop, *final;
    film = fopen("ListFilm.dat", "r");
    genre = fopen("Genre.dat", "r");
    sutradara = fopen("Sutradara.dat", "r");
    bioskop = fopen("Bioskop.dat", "r");
    int i = 0, a = 0;
    fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    while(strcmp(ListFilm[a].judul, "####") != 0){
        a++;
        fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    }
    int b = 0;
    fscanf(sutradara, "%s %s", ListSutradara[b].kode, ListSutradara[b].definisi);
    while(strcmp(ListSutradara[b].kode, "####") != 0){
        b++;
        fscanf(sutradara, "%s %s", ListSutradara[b].kode, ListSutradara[b].definisi);
    }
    int c = 0;
    fscanf(genre, "%s %s", ListGenre[c].kode, ListGenre[c].definisi);
    while(strcmp(ListGenre[c].kode, "####") != 0){
        c++;
        fscanf(genre, "%s %s", ListGenre[c].kode, ListGenre[c].definisi);
    }
    int d = 0;
    fscanf(bioskop, "%s %s", ListBioskop[d].kode, ListBioskop[d].definisi);
    while(strcmp(ListBioskop[d].kode, "####") != 0){
        d++;
        fscanf(bioskop, "%s %s", ListBioskop[d].kode, ListBioskop[d].definisi);
    }
    fclose(film);
    fclose(sutradara);
    fclose(genre);
    fclose(bioskop);
    dataFilm Final[a];
    final = fopen("ListFilmFinal.dat", "w");
    for(i = 0; i < a; i++){
        strcpy(Final[i].judul, ListFilm[i].judul);
        strcpy(Final[i].sutradara, ListSutradara[search(ListFilm[i].sutradara, ListSutradara, b)].definisi);
        strcpy(Final[i].genre, ListGenre[search(ListFilm[i].genre, ListGenre, c)].definisi);
        strcpy(Final[i].bioskop, ListBioskop[search(ListFilm[i].bioskop, ListBioskop, d)].definisi);
        fprintf(final, "%s %s %s %s\n", Final[i].judul, Final[i].sutradara, Final[i].genre, Final[i].bioskop);
    }
    fprintf(final, "%s %s %s %s\n", "####", "####", "####", "####");
    fclose(final);
    for(i = 0; i < a; i++){
        printf("%s %s %s %s\n", Final[i].judul, Final[i].sutradara, Final[i].genre, Final[i].bioskop);
    }
    return 0;
}