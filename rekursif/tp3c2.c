#include <stdio.h>

int rec(int a, int b, int c, int p){
    if (c == 2){
        return (2 * p * b) + (a * a) - 1;
    } else {
        int temp = (2 * p * b) + (a * a) - 1;
        return rec(b, temp, c-1, p+1);
    }
}

int main(){
    int a, b, c, n;
    scanf("%d", &n);
    int hasil[n];
    for (int i = 0; i < n; i++){
        scanf("%d%d%d", &a, &b, &c);
        hasil[i] = rec(a, b, c, 2);
    }
    for (int i = 0; i < n; i++){
        printf("%d\n", hasil[i]);
    }
    return 0;
}