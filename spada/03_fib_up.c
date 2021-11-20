#include <stdio.h>

void fib(int *arr, int n, int i){
    if(i == 0){
        arr[i] = 0;
        fib(arr, n, i+1);
    } else if(i == 1){
        arr[i] = 1;
        fib(arr, n, i+1);
    } else {
        if(i < n){
            arr[i] = arr[i-1] + arr[i-2];
            fib(arr, n, i+1);
        }
    }
}

int main(){
    int n;
    printf("bilangan fibonacci : ");
    scanf("%d", &n);
    int arr[n];
    fib(arr, n, 0);
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}