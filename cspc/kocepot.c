#include <stdio.h>
#include <string.h>

int jalan, cepot[100][100], kolom[100], baris[100];

int main(){
    int n, langkah;
    char arah[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        baris[i] = 0; kolom[i] = 0;
        scanf("%d%d", &baris[i], &kolom[i]);
        scanf("%d", &langkah);
        for (int j = 0; j < langkah; j++)
        {
            scanf("%s%d", arah, &jalan);
            if(strcmp(arah, "horizontal") == 0){
                baris[i] += jalan;
            } else if(strcmp(arah, "-horizontal") == 0){
                baris[i] -= jalan;
            } else if(strcmp(arah, "vertikal") == 0){
                kolom[i] += jalan;
            } else if(strcmp(arah, "-vertikal") == 0){
                kolom[i] -= jalan;
            } else if(strcmp(arah, "miring") == 0){
                kolom[i] += jalan;
                baris[i] += jalan;
            } else {
                kolom[i] -= jalan;
                baris[i] -= jalan;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", baris[i], kolom[i]);
    }
    return 0;
}