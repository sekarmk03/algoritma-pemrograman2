#include <stdio.h>

int fib(int *arr, int n){
    if(n < 2){
        arr[n] = n;
        return n;
    } else {
        arr[n] = fib(arr, n-1) + fib(arr, n-2);
        return arr[n];
    }
}

int main(){
    int n;
    printf("bilangan fibonacci : ");
    scanf("%d", &n);
    int arr[n];
    fib(arr, n);
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}