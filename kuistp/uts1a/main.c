#include "header.h"

int main(){
    // deklarasi variabel
    char type[5], negara1[50], negara2[50], negara3[50];
    int n1, n2, n3;

    // meminta inputan
    // memanggil prosedur input untuk menginput isi array of struct
    scanf("%s", type);
    scanf("%s", negara1);
    scanf("%d", &n1); dessert satu[n1]; input(satu, n1, negara1);
    scanf("%s", negara2);
    scanf("%d", &n2); dessert dua[n2]; input(dua, n2, negara2);
    scanf("%s", negara3);
    scanf("%d", &n3); dessert tiga[n3]; input(tiga, n3, negara3);

    // deklarasi array hasil awal dan akhir
    dessert result[n1+n2], final[n1+n2+n3];

    /*
        * pengecekan tipe sorting
        * urutannya :
                     - urutkan array pertama dan kedua (sort)
                     - gabungkan array pertama dan kedua, simpan dalam array result (merge)
                     - urutkan array ketiga (sort)
                     - gabungkan array ketiga dan array result, simpan dalam array final (merge)
    */
    if(strcmp(type, "is") == 0){
        // jika memilih insertion sort
        insertion(satu, n1); insertion(dua, n2);
        merge(satu, dua, n1, n2, result);
        insertion(tiga, n3); merge(result, tiga, n1+n2, n3, final);
    } else if(strcmp(type, "ss") == 0){
        // jika memilih selection sort
        selection(satu, n1); selection(dua, n2);
        merge(satu, dua, n1, n2, result);
        selection(tiga, n3); merge(result, tiga, n1+n2, n3, final);
    } else if(strcmp(type, "qs") == 0){
        // jika memilih quick sort
        quick(satu, 0, n1-1); quick(dua, 0, n2-1);
        merge(satu, dua, n1, n2, result);
        quick(tiga, 0, n3-1); merge(result, tiga, n1+n2, n3, final);
    } else{
        // jika memilih bubble sort
        bubble(satu, n1); bubble(dua, n2);
        merge(satu, dua, n1, n2, result);
        bubble(tiga, n3); merge(result, tiga, n1+n2, n3, final);
    }

    // mencetak sesuai spesifikasi
    // memanggil prosedur output
    printf("Per Negara:\n");
    printf("%s:\n", negara1);
    output(negara1, satu, n1);
    printf("%s:\n", negara2);
    output(negara2, dua, n2);
    printf("%s:\n", negara3);
    output(negara3, tiga, n3);
    printf("Semua:\n");
    output("semua", final, n1+n2+n3);
    return 0;
}