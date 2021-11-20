#include "header.h"

unsigned long long int Fpb(int a, int b){
    if(b == 0){
        return a;
    } else {
        int temp = a % b;
        return Fpb(b, temp);
    }
}

void Hasil(int n1, int n2){
    hasil = 0;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            hasil = Fpb(headerBaris[i], headerKolom[j]);
            printf("%llu\n", hasil);
        }
    }
}