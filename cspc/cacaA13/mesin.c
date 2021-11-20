#include "header.h"

int Cari(int len, int *i){
    int count = 0;
    for (int j = 1; j < len - 1; j++)
    {
        if(pita[*i][j] == 'a' && (pita[*i][j - 1] != ' ' && pita[*i][j + 1] != ' ' && pita[*i][j - 1] != '.' && pita[*i][j + 1] != '.')){
            count++;
        }
    }
    return count;
}