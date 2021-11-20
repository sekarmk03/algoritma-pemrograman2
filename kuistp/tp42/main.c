#include "header.h"

int main(){
    int n, i, j;
    char method[50], sortBy[50];
    scanf("%d", &n);
    for ( i = 0; i < n; i++){
        scanf("%s%d%f", d[i].nama, &d[i].harga, &d[i].rating);
    }
    scanf("%s%s%s", method, type, sortBy);
    if(strcmp(method, "insertion") == 0){
        ins(n, sortBy);
    }else{
        sel(n, sortBy);
    }
    cetak(n);
    return 0;
}