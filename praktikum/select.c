#include <stdio.h>
int main(){
    int i, j, temp, idxMin, arr[] = {8,5,7,1,9,3};
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for ( i = 0; i < 6; i++)
    {
        for ( j = i + 1; j < 6; j++)
        {
            if (arr[idxMin] > arr[j])
            {
                idxMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[idxMin];
        arr[idxMin] = temp;
    }
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}