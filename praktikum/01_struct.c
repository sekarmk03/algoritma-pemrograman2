#include <stdio.h>
#include <string.h>

typedef struct
{
    char warna[100];
    int red, green, blue;
}matriks;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    matriks dataWarna[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%s%d%d%d", &dataWarna[i][j].warna, &dataWarna[i][j].red, &dataWarna[i][j].green, &dataWarna[i][j].blue);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%s%d%d%d", dataWarna[i][j].warna, dataWarna[i][j].red, dataWarna[i][j].green, dataWarna[i][j].blue);
        }
    }
    
    return 0;
}