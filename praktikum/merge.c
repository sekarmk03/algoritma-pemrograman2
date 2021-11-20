#include <stdio.h>
#include <string.h>

void merge(char str[][30], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char tempL[n1][30], tempR[n2][30];
    for (int i = 0; i < n1; i++){
        strcpy(tempL[i], str[i+left]);
    }
    for (int j = 0; j < n2; j++){
        strcpy(tempR[j], str[mid+1+j]);
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (strcmp(tempL[i], tempR[j]) <= 0){
            strcpy(str[k], tempL[i]);
            i++;
        } else {
            strcpy(str[k], tempR[j]);
            j++;
        }
        k++;
    }
    while (i < n1){
        strcpy(str[k], tempL[i]);
        i++; k++;
    }
    while (j < n2){
        strcpy(str[k], tempR[j]);
        j++; k++;
    }
}

void mergeSort(char str[][30], int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(str, left, mid);
    mergeSort(str, mid+1, right);
    merge(str, left, mid, right);
}

int main(){
    int n1, n2, i;
    char smt[100][30];
    scanf("%d", &n1);
    for (i = 0; i < n1; i++){
        scanf("%s", smt[i]);
    }
    scanf("%d", &n2);
    for ( i = n1; i < n1+n2; i++){
        scanf("%s", smt[i]);
    }
    mergeSort(smt, 0, n1+n2-1);
    for (int i = 0; i < n1+n2; i++){
        printf("%s\n", smt[i]);
    }
    return 0;
}