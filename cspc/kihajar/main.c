#include "header.h"

int main(){
    int n, prima[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if(i == 0){
            prima[i] = Prima(i + 2);
        } else {
            prima[i] = Prima(prima[i - 1] + 1);
        }
        hasil[i] = (i + 1) * prima[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %llu\n", i + 1, hasil[i]);
    }
    return 0;
}