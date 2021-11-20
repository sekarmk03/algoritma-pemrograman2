#include <stdio.h>

void kaliProsedur(int bil1, int bil2, int *hasil)
{
    *hasil = bil1 * bil2;
}

int kaliFungsi(int bil1, int bil2)
{
    return bil1 * bil2;
}

int main()
{
    int a, b, hasil = 0;
    a = 5, b = 2;
    kaliProsedur(a, b, &hasil);
    printf("hasil prosedur %d\n", hasil);
    hasil = kaliFungsi(a, b);
    printf("hasil fungsi %d\n", hasil);
}