#include <stdio.h>

int sc(int a, int idx, int bil){
    if(a == bil){
        return idx;
    } else {
        return sc(a, idx-1, bil);
    }
}

int main(){
    int n, bil, hasil = 0, i;
    scanf("%d%d", &n, &bil);
    int arr[n];
    for (i = 0; i < n; i++){
        scanf("%d", arr[i]);
    }
    i = 0;
    do {
        sc(&i, n-1, bil);
        i++;
    } while (!hasil);
    printf("%d\n", hasil);
    return 0;
}