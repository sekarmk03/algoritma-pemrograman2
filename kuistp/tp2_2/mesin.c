#include "header.h"

void InputData(data dt[][100]){
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%s", dt[i][j].nama);
            len[i][j] = strlen(dt[i][j].nama);
            for (int k = 0; k < 3; k++)
            {
                scanf("%d", &dt[i][j].nilai[k]);
            }
            dt[i][j].rataan = (float)(dt[i][j].nilai[0] + dt[i][j].nilai[1] + dt[i][j].nilai[2]) / 3;
        }
    }
}

void InputTukar(){
    int i = 0;
    jumlah = 0;
    do
    {
        scanf("%s", tukar[i]);
        i++; jumlah++;
    } while (strcmp(tukar[i-1], "stop") != 0);
}

void Swap(char namaKiri[], char namaKanan[], int x1, int y1, int x2, int y2){
    char tempNama[50];
    float tempRataan;
    strcpy(tempNama, namaKiri);
    strcpy(namaKiri, namaKanan);
    strcpy(namaKanan, tempNama);
    tempRataan = dt[x1][y1].rataan;
    dt[x1][y1].rataan = dt[x2][y2].rataan;
    dt[x2][y2].rataan = tempRataan;
}

void Cari(){
    int idxB[jumlah], idxK[jumlah], sama = 0, lima = 0;
    for (int a = 0; a < jumlah-1; a++)
    {
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                if (strcmp(tukar[a], dt[i][j].nama) == 0)
                {
                    strcpy(tukar[a], "\0");
                    idxB[a] = i; idxK[a] = j;
                    sama++;
                }
                if(sama == 2)
                {
                    sama = 0;
                    if (dt[idxB[a-1]][idxK[a-1]].rataan > dt[idxB[a]][idxK[a]].rataan)
                    {
                        Swap(dt[idxB[a-1]][idxK[a-1]].nama, dt[idxB[a]][idxK[a]].nama, idxB[a-1], idxK[a-1], idxB[a], idxK[a]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            len[i][j] = strlen(dt[i][j].nama);
        }
    }
}

void Max(){
    int i, j;
    for (i = 0; i < kolom; i++)
    {
        max[i] = len[0][i];
        for (j = 1; j < baris; j++)
        {
            if (max[i] < len[j][i])
            {
                max[i] = len[j][i];
            }
        }
    }
}

void Print(){
    Max();
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            for (int k = 0; k < strlen(dt[i][j].nama); k++)
            {
                printf("%c", dt[i][j].nama[k]);
            }
            if(j < kolom-1){
                for (int k = 0; k < max[j] - strlen(dt[i][j].nama); k++)
                {
                    printf(" ");
                }
                printf("  ");
            }
        }
        printf("\n");
    }
}