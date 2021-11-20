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
    FILE *arsip1;
    FILE *arsip2;
    arsip1 = fopen("ArsipMatkul.dat", "r");
    arsip2 = fopen("ArsipMatkul_copy.dat", "w");
    printf("mulai proses menyalin file..\n");
    fscanf(arsip1, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
    if(strcmp(mhs.nim, "XXXX") == 0){
        fprintf(arsip2, "%s %s %s\n", "XXXX", "XXXX", "XXXX");
    } else {
        while(strcmp(mhs.nim, "XXXX") != 0){
            fprintf(arsip2, "%s %s %s\n", mhs.nim, mhs.nama, mhs.nilai);
            fscanf(arsip1, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
        }
        fprintf(arsip2, "%s %s %s\n", "XXXX", "XXXX", "XXXX");
    }
    printf("proses menyalin selesai..\n");
    fclose(arsip1);
    fclose(arsip2);
    return 0;
}