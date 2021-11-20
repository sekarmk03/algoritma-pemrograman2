#include <stdio.h>

int Fakt(int);

int main(){
    int n1, n2, headerKolom[100], headerBaris[100], hasil = 0;
    char tandaK, tandaB;
    scanf(" %c%d", &tandaK, &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &headerKolom[i]);
    }
    scanf(" %c%d", &tandaB, &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &headerBaris[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            hasil = Fakt(headerBaris[i]) * Fakt(headerKolom[j]);
            printf("%d\n", hasil);
        }
    }
    return 0;
}

int Fakt(int n){
    if(n == 1){
        return n;
    } else {
        return n * Fakt(n - 1);
    }
}