#include "header.h"

int main(){
    int n; char type, by;
    scanf("%d", &n);
    pecahan frac[n];
    for (int i = 0; i < n; i++){
        frac[i].hasil = 0;
        scanf(" %lf %lf", &frac[i].num, &frac[i].den);
        frac[i].hasil = (double)frac[i].num / frac[i].den;
    }
    scanf(" %c %c", &type, &by);
    if(type == 'b'){
        bubbleSort(frac, n, by);
    } else {
        qsTengah(frac, 0, n-1, by);
    }
    cetak(frac, n);
    return 0;
}