#include "header.h"

int main(){
    int i = 0, j, len = 0, titik = 0, kata = 0;
    do
    {
        scanf("%s", pita[i]);
        len = strlen(pita[i]);
        for (j = 0; j < len; j++)
        {
            if(pita[i][j] == '.'){
                titik = 1;
            }
        }
        hurufA[i] = Cari(len, &i);
        i++;
    } while (titik != 1);
    kata = i;
    pita[i-1][len-1] = '\0';
    Urut(kata);
    for (i = 0; i < kata; i++)
    {
        if(hurufA[i] > 0){
            printf("%s", pita[i]);
            if(i != kata-2){
                printf("-");
            }
        } else {
            continue;
        }
    }
    printf("\n");
    return 0;
}