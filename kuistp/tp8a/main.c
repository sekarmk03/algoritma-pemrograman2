#include "header.h"

int main(){
    dataFilm ListFilm[50];
    dataKode ListSutradara[50], ListGenre[50], ListBioskop[50];
    FILE *film, *sutradara, *genre, *bioskop, *final;
    fileOpen(film, sutradara, genre, bioskop);
    int i = 0, a = 0;
    // readFile(film, ListFilm);
    fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    while(strcmp(ListFilm[a].judul, "####") != 0){
        a++;
        fscanf(film, "%s %s %s %s", ListFilm[a].judul, ListFilm[a].sutradara, ListFilm[a].genre, ListFilm[a].bioskop);
    }
    int b = readFile(sutradara, ListSutradara);
    int c = readFile(genre, ListGenre);
    int d = readFile(bioskop, ListBioskop);
    fileClose(film, sutradara, genre, bioskop);
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