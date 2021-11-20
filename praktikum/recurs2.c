#include <stdio.h>

int fib(int n){
    if(n == 0){
        return 0;
    } else if(n == 1){
        return 1;
    } else {
        // int genap = 0;
        // if((fib(n-1) + fib(n-2)) % 2 == 0){
        //     genap = fib(n-1) + fib(n-2);
        // }
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}