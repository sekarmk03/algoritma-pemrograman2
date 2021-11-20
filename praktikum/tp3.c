#include <stdio.h>


int bakteri(int a, int b, int c){
    if(c == 2){
        return (2*b + a*a);
    } else {
        int temp = 2*b + a*a;
        return bakteri(b, temp, c-1);
    }
}

int main(){
    int a[100], b[100], c[100], n, i, j, hasil[100];
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        hasil[i] = bakteri(a[i], b[i], c[i]);
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", hasil[i]);
    }
    return 0;
}