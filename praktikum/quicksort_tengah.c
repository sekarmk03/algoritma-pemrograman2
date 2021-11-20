#include <stdio.h>

void qsTengah(int data[], int kiri, int kanan){
    int i, j, temp;
    i = kiri; j = kanan;
    int pivot = data[(kanan + kiri) / 2];
    do
    {
        while (data[i] < pivot && i <= j)
        {
            i++;
        }
        while (data[j] > pivot && i <= j)
        {
            j--;
        }
        if(i < j)
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++; j++;
        }
    } while (i < j);
    if(kiri < j && j < kanan)
    {
        qsTengah(data, kiri, j);
    }
    if(i < kanan && i > kiri)
    {
        qsTengah(data, i, kanan);
    }
}