#include <stdio.h>
#include <string.h>

typedef struct
{
    char namaMhs[100];
    int nim;
    float nilai[3];
    float rata2;
} dataMhs;

void swap(dataMhs *awal, dataMhs *akhir)
{
    dataMhs temp;
    temp = *awal;
    *awal = *akhir;
    *akhir = temp;
}

void selectionSort(dataMhs d[], int n)
{
    int i, j, idx;
    for (i = 0; i < n - 1; i++)
    {
        idx = i; //----------------------------------> inisialisasi nilai idx dengan i
        for (j = i + 1; j < n; j++)
        {
            if (d[idx].nim > d[j].nim)
            {
                idx = j; //--------------------------> inisialisasi idx dengan posisi data kanan
            }
        }
        swap(&d[i], &d[idx]); //---------------------> tukar data ke-i dengan data ke-idx
    }
}

void insertData(dataMhs listMhs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%99[^\n]s %d", listMhs[i].namaMhs, &listMhs[i].nim);
        float sum = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &listMhs[i].nilai[j]);
            sum += listMhs[i].nilai[j];
        }
        listMhs[i].rata2 = (float)(sum) / 3;
    }
}

int main()
{
    int arr[100];
    return 0;
}