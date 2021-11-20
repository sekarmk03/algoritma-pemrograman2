#include "header.h"

void startKata(char pita[])
{
    idx = 0;
    pKata = 0;
    while (pita[idx] == ' ')
    {
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {
        cKata[pKata] = pita[idx];
        idx++;
        pKata++;
    }
    cKata[pKata] = '\0';
}

void resetKata()
{
    pKata = 0;
    cKata[pKata] = '\0';
}

void incKata(char pita[])
{
    pKata = 0;
    while (pita[idx] == ' ')
    {
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {
        cKata[pKata] = pita[idx];
        idx++;
        pKata++;
    }
    cKata[pKata] = '\0';
}

char *getCKata()
{
    return cKata;
}

int getPKata()
{
    return pKata;
}

int eopKata(char pita[])
{
    if (pita[idx] == '.')
        return 1;
    else
        return 0;
}

void insertData(char pita[], mahasiswa *data)
{
    int countLen = 0;
    startKata(pita);

    while (eopKata(pita) == 0)
    {
        if ((strcmp(getCKata(), "INSERT") != 0) && (strcmp(getCKata(), "mahasiswa") != 0))
        {
            if (countLen == 0)
                strcpy(data->nim, getCKata());
            else if (countLen == 1)
                strcpy(data->nama, getCKata());
            countLen++;
        }
        incKata(pita);
    }
    strcpy(data->nilai, getCKata());
}

void resetData(char str[])
{
    str[0] = '\0';
}

int findIdx(char str[], mahasiswa data[])
{
    int i = 0;
    while (strcmp(data[i].nim, str) != 0)
    {
        i++;
    }
    return i;
}

void deleteData(char pita[], mahasiswa data[])
{
    startKata(pita);

    while (eopKata(pita) == 0)
    {
        if ((strcmp(getCKata(), "DELETE") != 0) && (strcmp(getCKata(), "mahasiswa") != 0))
        {
            int del = findIdx(getCKata(), data);
            resetData(data[del].nama);
            resetData(data[del].nilai);
            resetData(data[del].nim);
        }
        incKata(pita);
    }
}