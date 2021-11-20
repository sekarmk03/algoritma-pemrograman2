#include <stdio.h>

int Fib(int* arr, int n){
    if(n < 2) {
        arr[n] = n;
        return n;
    } else {
        arr[n] = Fib(arr, n-1) + Fib(arr, n-2);
        return arr[n];
    }
}

int main(){
    int n;
    printf("Jumlah bilangan fibonacci : ");
    scanf("%d", &n);
    int arr[n];
    Fib(arr, n);
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}