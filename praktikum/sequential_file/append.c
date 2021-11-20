#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[20];
    char nama[50];
    char jurusan[20];
} dataMhs;

void prosedur(dataMhs data[], FILE *File, char namaFile[])
{
    int i = 0, idx = 0;
    File = fopen(namaFile, "r");
    fscanf(File, "%s %s %s", data[idx].nim, data[idx].nama, data[idx].jurusan);
    if (strcmp(data[idx].nim, "####") == 0)
    {
        printf("File Kosong!\n");
    }
    else
    {
        while (strcmp(data[idx].nim, "####") != 0)
        {
            idx++;
            fscanf(File, "%s %s %s", data[idx].nim, data[idx].nama, data[idx].jurusan);
        }
        scanf("%s %s %s", data[idx].nim, data[idx].nama, data[idx].jurusan);
        while (strcmp(data[idx].nim, "####") != 0)
        {
            idx++;
            scanf("%s %s %s", data[idx].nim, data[idx].nama, data[idx].jurusan);
        }
    }
    fclose(File);
    File = fopen(namaFile, "w");
    for (i = 0; i < idx; i++)
    {
        fprintf(File, "%s %s %s\n", data[i].nim, data[i].nama, data[i].jurusan);
    }
    fprintf(File, "%s %s %s\n", "####", "####", "####");
    fclose(File);
}

int main()
{
    int i = 0, idx = 0;
    dataMhs mhs[50], mhs2[50];
    FILE *fileMhs;
    FILE *fileMhs2;
    prosedur(mhs, fileMhs, "dataMahasiswa1.dat");
    prosedur(mhs2, fileMhs2, "dataMahasiswa2.dat");
    return 0;
}

// baca data dari file
// masukin datanya ke array (0 1 2) : 3
// user input data baru ke konsol
// masukin data baru ke array (3 4 5 6) : 4
// print array ke file