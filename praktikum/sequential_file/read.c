#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[20];
    char nama[50];
    char jurusan[50];
} dataMhs;

int main()
{
    int i = 0, idx = 0;
    dataMhs mhs[50];
    FILE *fileMhs;
    fileMhs = fopen("dataMahasiswa.dat", "r");
    FILE *fileLain;
    fileLain = fopen("FileLain.dat", "w");
    fscanf(fileMhs, "%s %s %s", mhs[idx].nim, mhs[idx].nama, mhs[idx].jurusan);
    if (strcmp(mhs[idx].nim, "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        while (strcmp(mhs[idx].nim, "####") != 0)
        {
            idx++;
            fscanf(fileMhs, "%s %s %s", mhs[idx].nim, mhs[idx].nama, mhs[idx].jurusan);
        }
        printf("Data mahasiswa :\n");
        for (i = 0; i < idx; i++)
        {
            printf("%s %s %s\n", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);
        }
    }
    fprintf(fileLain, "%s %s %s\n", "####", "####", "####");
    fclose(fileMhs);
    fclose(fileLain);
    return 0;
}

// scanf : konsol
// fscanf : file

// baca file
// masukin data dari file ke array
// tampilin data array ke konsol