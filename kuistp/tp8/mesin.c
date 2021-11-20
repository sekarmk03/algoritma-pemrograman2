#include "header.h"

int search(char search[], dataKode data[], int n){
    int i = 0;
    while(strcmp(search, data[i].kode) != 0){
        i++;
    }
    return i;
}