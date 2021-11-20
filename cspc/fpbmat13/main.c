#include "header.h"

int main(){
    int n1 = 0, n2 = 0;
    char c1, c2;
    scanf(" %c%d", &c1, &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &headerKolom[i]);
    }
    scanf(" %c%d", &c2, &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &headerBaris[i]);
    }
    Hasil(n1, n2);
    return 0;
}