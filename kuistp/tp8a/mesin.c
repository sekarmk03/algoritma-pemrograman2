#include "header.h"

int readFile(FILE *file, dataKode d[]){
    int i = 0;
    fscanf(file, "%s %s", d[i].kode, d[i].definisi);
    while(strcmp(d[i].kode, "####") != 0){
        i++;
        fscanf(file, "%s %s", d[i].kode, d[i].definisi);
    }
    return i;
}

void fileOpen(FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop){
    film = fopen("ListFilm.dat", "r");
    sutradara = fopen("Sutradara.dat", "r");
    genre = fopen("Genre.dat", "r");
    bioskop = fopen("Bioskop.dat", "r");
}

void fileClose(FILE *film, FILE *sutradara, FILE *genre, FILE *bioskop){
    fclose(film);
    fclose(sutradara);
    fclose(genre);
    fclose(bioskop);
}

int search(char search[], dataKode data[], int n){
    int i = 0;
    while(strcmp(search, data[i].kode) != 0){
        i++;
    }
    return i;
}

