#include "header.h"

unsigned long long int Fakt(int n){
    if(n == 1){
        return n;
    } else {
        return n * Fakt(n - 1);
    }
}

void Hasil(int x, int y){
    for (int i = 0; i < y; i++)
    {
        hasil[0][i] = 0;
        for (int j = 0; j < x; j++)
        {
            hasil[0][i] = Fakt(headerBaris[i]) * Fakt(headerKolom[j]);
            printf("%llu\n", hasil[0][i]);
        }
    }
}