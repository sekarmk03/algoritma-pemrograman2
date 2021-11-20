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
    printf("isi arsip adalah :\n");
    fscanf(arsip, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
    if(strcmp(mhs.nim, "XXXX") == 0){
        printf("arsip kosong\n");
    } else {
        do
        {
            printf("%s %s %s\n", mhs.nim, mhs.nama, mhs.nilai);
            fscanf(arsip, "%s %s %s\n", &mhs.nim, &mhs.nama, &mhs.nilai);
        } while (strcmp(mhs.nim, "XXXX") != 0);
    }
    printf("done\n");
    fclose(arsip);
    return 0;
}