#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int tempL[n1], tempR[n2];
    for (int i = 0; i < n1; i++){
        tempL[i] = arr[left+i];
    }
    for (int j = 0; j < n2; j++){
        tempR[j] = arr[mid+1+j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (tempL[i] <= tempR[j]){
            arr[k] = tempL[i];
            i++;
        } else {
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = tempL[i];
        i++; k++;
    }
    while (j < n2){
        arr[k] = tempR[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}