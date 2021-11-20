#include "header.h"

void swap(arrlist *awal, arrlist *akhir){
    arrlist temp;
    temp = *awal;
    *awal = *akhir;
    *akhir = temp;
}

void input(arrlist song[], int n, char id){
    for (int i = 0; i < n; i++){
        scanf("%f%s", &song[i].duration, &song[i].title);
        song[i].id = id;
    }
}

void insertion(arrlist song[], int n, char type){
    int i, j; float keyDuration; char keyTitle[50], keyId;
    if (type == 'a') {
        for (i = 1; i < n; i++) {
            keyDuration = song[i].duration;
            strcpy(keyTitle, song[i].title);
            keyId = song[i].id;
            j = i - 1;
            while (j >= 0 && keyDuration < song[j].duration) {
                swap(&song[j+1], &song[j]);
                j--;
            }
            song[j + 1].duration = keyDuration;
            strcpy(song[j + 1].title, keyTitle);
            song[j + 1].id = keyId;
        }
    } else {
        for (i = 1; i < n; i++) {
            keyDuration = song[i].duration;
            strcpy(keyTitle, song[i].title);
            keyId = song[i].id;
            j = i - 1;
            while (j >= 0 && keyDuration > song[j].duration) {
                swap(&song[j+1], &song[j]);
                j--;
            }
            song[j + 1].duration = keyDuration;
            strcpy(song[j + 1].title, keyTitle);
            song[j + 1].id = keyId;
        }
    }
}

void selection(arrlist song[], int n, char type){
    int i, j, idx; float tempRating; char tempNama[50];
    for (i = 0; i < n - 1; i++) {
        idx = i;
        for (j = i + 1; j < n; j++) {
            if (type == 'a') {
                if (song[idx].duration > song[j].duration) {
                    idx = j;
                }
            } else {
                if (song[idx].duration < song[j].duration) {
                    idx = j;
                }
            }
        }
        swap(&song[i], &song[idx]);
    }
}

void quick(arrlist song[], int left, int right, char type){
    int i = left, j = right;
    float pivot = song[i].duration;
    if (left < right){
        while (i < j){
            if(type == 'a'){
                while (song[j].duration < pivot && i < j){
                    j--;
                }
                // song[i] = song[j];
                while (song[i].duration > pivot && i < j){
                    i++;
                }
                // song[j] = song[i];
                swap(&song[i], &song[j]);
            } else {
                while (song[j].duration > pivot && i < j){
                    j--;
                }
                song[i] = song[j];
                while (song[i].duration < pivot && i < j){
                    i++;
                }
                song[j] = song[i];
            }
       }
       song[i].duration = pivot;
       quick(song, left, i - 1, type);
       quick(song, j + 1, right, type);
    }/*
    int i = left, j = right;
    float pivot = song[(right + left) / 2].duration;
    do{
        if(type == 'a'){
            while (song[i].duration < pivot && i <= j)
                i++;
            while (song[j].duration > pivot && i <= j)
                j--;
        } else {
            while (song[i].duration > pivot && i <= j)
                i++;
            while (song[j].duration < pivot && i <= j)
                j--;
        }
        if(i < j){
            swap(&song[i], &song[j]);
            i++; j--;
        }
    } while (i < j);
    if((left < j) && (j < right))
        quick(song, left, j, type);
    if((i < right) && (i > left))
        quick(song, i, right, type);*/
}

void bubble(arrlist song[], int n, char type){
    int i, tukar;
    do{
        tukar = 0;
        for ( i = 0; i < n-1; i++){
            if(type == 'a'){
                if (song[i].duration > song[i+1].duration){
                    swap(&song[i], &song[i+1]);
                    tukar = 1;
                }
            } else {
                if (song[i].duration < song[i+1].duration){
                    swap(&song[i], &song[i+1]);
                    tukar = 1;
                }
            }
        }
    } while (tukar == 1);
}

void merge(arrlist song1[], arrlist song2[], int n, int m, arrlist result[], char type){
    int i = 0, j = 0, k = 0, l = 0;
    while ((i < n) && (j < m)){
        if(type == 'a'){
            if (song1[i].duration <= song2[j].duration){
                result[k] = song1[i];
                i++;
                k++;
            }
            if (song2[j].duration <= song1[i].duration){
                result[k] = song2[j];
                j++;
                k++;
            }
        } else {
            if (song1[i].duration >= song2[j].duration){
                result[k] = song1[i];
                i++;
                k++;
            }
            if (song2[j].duration >= song1[i].duration){
                result[k] = song2[j];
                j++;
                k++;
            }
        }
    }
    if (i < n){
        for ( l = i; l < n; l++){
            result[k] = song1[l];
            k++;
        }
    }
    if (j < m){
        for ( l = j; l < m; l++){
            result[k] = song2[l];
            k++;
        }
    }
}

void output(arrlist result[], int n, arrlist ibnu[]){
    int x = 0;
    printf("Daftar Lagu Keluarga:\n");
    for (int i = 0; i < n; i++){
        printf("%0.2f %s\n", result[i].duration, result[i].title);
        if(i < (int)(ceil(n * 0.5))){
            if(result[i].id == 'x')
                x++;
        }
    }
    printf("\nLagunya Ibnu:\n");
    for (int i = 0; i < x; i++){
        printf("%s\n", ibnu[i].title);
    }
    if(x == 0){
        printf("Tidak memutar song Ibnu\n");
    }
}