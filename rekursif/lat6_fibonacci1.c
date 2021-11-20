#include <stdio.h>

void Fib(int* arr, int n, int i){
    if(i == 0) {
        arr[i] = 0;
        Fib(arr, n, i+1);
    } else if (i == 1) {
        arr[i] = 1;
        Fib(arr, n, i+1);
    } else {
        if(i < n) {
            arr[i] = arr[i-1] + arr[i-2];
            Fib(arr, n, i+1);
        }
    }
}

int main(){
    int n;
    printf("Masukkan bilangan fibonacci : ");
    scanf("%d", &n);
    int arr[n];
    Fib(arr, n, 0);
    int i = 0;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}