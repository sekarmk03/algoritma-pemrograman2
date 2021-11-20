#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[100];
    char nilai[2];
}data;


int main(){
    data mhs;
    FILE *arsip;
    arsip = fopen("ArsipMatkul.dat", "r");
    char kata_cari[10];
    printf("masukkan nim yang dicari : ");
    scanf("%s", &kata_cari);
    fscanf(arsip, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
    if(strcmp(mhs.nim, "XXXX") == 0){
        printf("arsip kosong\n");
    } else {
        if(strcmp(kata_cari, "XXXX") == 0){
            printf("tidak ditemukan\n");
        } else {
            while((strcmp(mhs.nim, "XXXX") != 0) && (strcmp(kata_cari, mhs.nim) != 0)){
                fscanf(arsip, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
            }
            if(strcmp(mhs.nim, kata_cari) == 0){
                printf("hasil pencarian : \n");
                printf("%s %s %s\n", mhs.nim, mhs.nama, mhs.nilai);
            } else {
                printf("tidak ditemukan\n");
            }
        }
    }
    fclose(arsip);
    return 0;
}