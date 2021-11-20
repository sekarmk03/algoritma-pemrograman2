#include <stdio.h>
int main(){
    int i, j, key, arr[] = {8,5,7,1,9,3};
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // perulangan muali dari indeks ke-1
    for ( i = 1; i < 6; i++)
    {
        // menjadikan elemen ke-i sbg data sisip (key)
        key = arr[i];
        j = i - 1;
        // loop sebanyak j >= 0 karena idx min arr adalah 0
        // dan selama arr elemen ke-j > data sisip (key)
        while (j >= 0 && key < arr[j])
        {
            // arr ke-j geser ke belakang
            arr[j + 1] = arr[j];
            j--;
        }
        // masukkan data sisip ke paling depan
        // dari array yang tergeser
        arr[j + 1] = key;
    }
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}