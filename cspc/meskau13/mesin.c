#include "header.h"

int Cari(int len, int *i){
    int count = 0;
    for (int j = 0; j < len; j++)
    {
        if(pita[*i][j] == 'a'){
            count++;
        }
    }
    return count;
}

void Urut(int kata){
    int max, tempA;
    char tempB[100];
    for (int i = 0; i < kata; i++)
    {
        max = i;
        for (int j = i + 1; j < kata; j++)
        {
            if(hurufA[j] > hurufA[max]){
                max = j;
            }
        }
        tempA = hurufA[max];
        strcpy(tempB, pita[max]);
        hurufA[max] = hurufA[i];
        strcpy(pita[max], pita[i]);
        hurufA[i] = tempA;
        strcpy(pita[i], tempB);
    }
}