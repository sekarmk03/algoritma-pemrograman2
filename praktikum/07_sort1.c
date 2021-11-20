#include <stdio.h>
#include <string.h>
typedef struct {
    char nama[50];
    int nilai;
}data;
data d[100];

void urutNama(int n){
    int i, j, idxMin, tempA;
    char tempC[50];
    for ( i = 0; i < n-1; i++)
    {
        idxMin = i;
        for ( j = i + 1; j < n; j++)
        {
            if (strcmp(d[idxMin].nama, d[j].nama) > 0)
            {
                idxMin = j;
            }
        }
        strcpy(tempC, d[i].nama);
        tempA = d[i].nilai;
        strcpy(d[i].nama, d[idxMin].nama);
        d[i].nilai = d[idxMin].nilai;
        strcpy(d[idxMin].nama, tempC);
        d[idxMin].nilai = tempA;
    }
}

void urutNilai(int n){
    int i, j, key;
    char temp[50];
    for ( i = 1; i < n; i++)
    {
        key = d[i].nilai;
        strcpy(temp, d[i].nama);
        j = i - 1;
        while (j >= 0 && key < d[j].nilai)
        {
            d[j+1].nilai = d[j].nilai;
            strcpy(d[j+1].nama, d[j].nama);
            j--;
        }
        d[j+1].nilai = key;
        strcpy(d[j+1].nama, temp);
    }
}

int main(){
    int n, i;
    char c;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s%d", &d[i].nama, &d[i].nilai);
    }
    scanf(" %c", &c);
    if(c == 'A'){
        urutNama(n);
    } else {
        urutNilai(n);
    }
    for ( i = 0; i < n; i++)
    {
        printf("%s %d\n", d[i].nama, d[i].nilai);
    }
    return 0;
}