#include "header.h"

int main(){
    unsigned long int n, m; //-------> menggunakan unsigned long int (tidak menampung nilai negatif)
    scanf("%lu%lu", &n, &m); //------> meminta nilai n dan m untuk rekursif
    Bagi(n, m); //-------------------> memanggil prosedur rekursif
    return 0;
}