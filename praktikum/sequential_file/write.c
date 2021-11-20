#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[20];
    char nama[50];
    char jurusan[20];
} dataMhs;

int main()
{
    int i = 0;
    dataMhs mhs[50];
    FILE *fileMhs;
    fileMhs = fopen("dataMahasiswa.dat", "w");
    scanf("%s %s %s", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);
    while (strcmp(mhs[i].nim, "----") != 0)
    {
        fprintf(fileMhs, "%s %s %s\n", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);
        i++;
        scanf("%s %s %s", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);
    }
    fprintf(fileMhs, "%s %s %s\n", "----", "----", "----");
    fclose(fileMhs);
    return 0;
}

// 200 sekar ilkom -> masuk array
//

// ####

// w : masukin sesuatu ke file
// r : ngebaca file

// sesuatu buat nge akses

// user input ke konsol
// masuk array
// array -> file