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
    arsip = fopen("ArsipMatkul.dat", "w");
    printf("Tuliskan rekaman satu per satu\n");
    printf("nim : ");
    scanf("%s", &mhs.nim);
    while (strcmp(mhs.nim, "XXXX") != 0){
        printf("nama : ");
        scanf("%s", &mhs.nama);
        printf("nilai : ");
        scanf("%s", &mhs.nilai);
        fprintf(arsip, "%s %s %s\n", mhs.nim, mhs.nama, mhs.nilai);
        printf("nim : ");
        scanf("%s", &mhs.nim);
    }
    fprintf(arsip, "%s %s %s", "XXXX", "XXXX", "XXXX");
    fclose(arsip);
    return 0;
}
