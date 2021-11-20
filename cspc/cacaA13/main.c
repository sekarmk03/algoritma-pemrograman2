#include "header.h"

int main(){
    int titik = 0, i = 0, jumlah = 0, len = 0;
    do
    {
        scanf("%s", pita[i]);
        len = strlen(pita[i]);
        for (int j = 0; j < len; j++)
        {
            if(pita[i][j] == '.'){
                titik = 1;
            }
        }
        jumlah += Cari(len, &i);
        i++;
    } while (titik != 1);
    printf("%d\n", jumlah);
    return 0;
}