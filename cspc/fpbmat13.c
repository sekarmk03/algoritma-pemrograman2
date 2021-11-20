#include <stdio.h>

int Fpb(int a, int b);

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
            hasil = Fpb(headerBaris[i], headerKolom[j]);
            printf("%d\n", hasil);
        }
    }
    return 0;
}

int Fpb(int a, int b){
    if(b == 0){
        return a;
    } else {
        int temp = a % b;
        return Fpb(b, temp);
    }
}