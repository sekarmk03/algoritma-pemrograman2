#include <stdio.h>

int mxSearch(int arr[], int n, int sc){
    int i = 0, found = 0;
    while(i < n && found == 0){
        if(arr[i] == sc){
            return i;
        } else {
            i++;
        }
    }
}

int main(){
    int n, sc, max = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max){
            max = arr[i];
        }
    }
    arr[mxSearch(arr, n, sc)] = 0;
    
}