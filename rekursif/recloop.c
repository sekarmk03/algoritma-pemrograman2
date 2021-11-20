#include <stdio.h>

void loop(int n, int arr[]){
    static int jumlah = 0;
    for(int i = 0; i < n; i++){
        jumlah += i;
        arr[i] = jumlah;
    }
}

void rec(int n, int arr[]){
    static int i = 0, jumlah = 0;
    if(n == 0){
        jumlah += i;
        arr[i] = jumlah;
    } else {
        jumlah += i;
        arr[i] = jumlah;
        i++;
        rec(n-1, arr);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    loop(n, arr1);
    rec(n, arr2);
    //print arr1 & arr2
    for(int i = 0; i < n; i++){
        printf("arr1[%d] = %d\n", i, arr1[i]);
        printf("arr2[%d] = %d\n", i, arr2[i]);
        printf("-----------\n");
    }
    return 0;
}