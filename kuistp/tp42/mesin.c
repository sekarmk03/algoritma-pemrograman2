#include "header.h"

void swap(int i, int idx){
    data temp;
    strcpy(temp.nama, d[i].nama);
    temp.harga = d[i].harga;
    temp.rating = d[i].rating;
    strcpy(d[i].nama, d[idx].nama);
    d[i].harga = d[idx].harga;
    d[i].rating = d[idx].rating;
    strcpy(d[idx].nama, temp.nama);
    d[idx].harga = temp.harga;
    d[idx].rating = temp.rating;
}

void ins(int n, char sortBy[]){
    int i, j, tempHarga;
    float tempRating;
    char temp[50];
    for ( i = 1; i < n; i++)
    {
        tempHarga = d[i].harga;
        tempRating = d[i].rating;
        strcpy(temp, d[i].nama);
        j = i - 1;
        if(strcmp(sortBy, "nama") == 0){
            if(strcmp(type, "asc") == 0){
                while (j >= 0 && (strcmp(temp, d[j].nama) < 0) && (strcmp(temp, d[j].nama) != 0)){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            } else {
                while (j >= 0 && (strcmp(temp, d[j].nama) > 0) && (strcmp(temp, d[j].nama) != 0)){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            }
        }else if(strcmp(sortBy, "harga") == 0){
            if(strcmp(type, "asc")){
                while (j >= 0 && tempHarga < d[j].harga && tempHarga != d[j].harga){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            } else {
                while (j >= 0 && tempHarga > d[j].harga && tempHarga != d[j].harga){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            }
        }else{
            if(strcmp(type, "asc")){
                while (j >= 0 && tempRating < d[j].rating && tempRating != d[j].rating){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            } else {
                while (j >= 0 && tempRating > d[j].rating && tempRating != d[j].rating){
                    d[j+1].harga = d[j].harga;
                    d[j+1].rating = d[j].rating;
                    strcpy(d[j+1].nama, d[j].nama);
                    j--;
                }
            }
        }
        d[j+1].harga = tempHarga;
        d[j+1].rating = tempRating;
        strcpy(d[j+1].nama, temp);
    }
}

void sel(int n, char sortBy[]){
    int i, j, idx, tempHarga;
    float tempRating;
    char tempNama[50];
    for ( i = 0; i < n-1; i++){
        idx = i;
        for ( j = i + 1; j < n; j++){
            if(strcmp(sortBy, "nama") == 0){
                if(strcmp(type, "asc") == 0){
                    if ((strcmp(d[idx].nama, d[j].nama) > 0) && (strcmp(d[idx].nama, d[j].nama) != 0))
                    {
                        idx = j;
                    }
                } else {
                    if ((strcmp(d[idx].nama, d[j].nama) < 0) && (strcmp(d[idx].nama, d[j].nama) != 0))
                    {
                        idx = j;
                    }
                }
            } else if(strcmp(sortBy, "harga") == 0){
                if(strcmp(type, "asc") == 0){
                    if (d[idx].harga > d[j].harga && d[idx].harga != d[j].harga)
                    {
                        idx = j;
                    }
                } else {
                    if (d[idx].harga < d[j].harga && d[idx].harga != d[j].harga)
                    {
                        idx = j;
                    }
                }
            } else {
                if(strcmp(type, "asc") == 0){
                    if (d[idx].rating > d[j].rating && d[idx].rating != d[j].rating)
                    {
                        idx = j;
                    }
                } else {
                    if (d[idx].rating < d[j].rating && d[idx].rating != d[j].rating)
                    {
                        idx = j;
                    }
                }
            }
        }
        swap(i, idx);
    }
}

void cetak(int n){
    for (int i = 0; i < n; i++){
        printf("%s %d %0.1f\n", d[i].nama, d[i].harga, d[i].rating);
    }
}