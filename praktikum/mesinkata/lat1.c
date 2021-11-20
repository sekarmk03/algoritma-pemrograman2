#include <stdio.h>
#include <string.h>

int idx;
int lenKata;
char currKata[50];

void startKata(char pita[]);
void resetKata();
void incKata(char pita[]);
char *getCurrKata();
int getLenKata();
int eopKata(char pita[]);
void space(int a);

int main()
{
    char pita[300];
    int alas = 0;
    scanf("%299[^/n]s", pita);

    startKata(pita);

    while (eopKata(pita) == 0)
    {
        printf("%s", getCurrKata());
        alas += getLenKata();
        space(alas);
        incKata(pita);
    }
    return 0;
}

void startKata(char pita[])
{
    idx = 0;
    lenKata = 0;
    while (pita[idx] == ' ')
    {
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {
        currKata[lenKata] = pita[idx];
        idx++;
        lenKata++;
    }
    currKata[lenKata] = '\0';
}

void resetKata()
{
    lenKata = 0;
    currKata[lenKata] = '\0';
}

void incKata(char pita[])
{
    lenKata = 0;
    while (pita[idx] == ' ')
    {
        idx++;
    }
    while ((pita[idx] != ' ') && (eopKata(pita) == 0))
    {
        currKata[lenKata] = pita[idx];
        idx++;
        lenKata++;
    }
    currKata[lenKata] = '\0';
}

char *getCurrKata()
{
    return currKata;
}

int getLenKata()
{
    return lenKata;
}

int eopKata(char pita[])
{
    if (pita[idx] == '.')
    {
        return 1;
    }
    return 0;
}

void space(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf(" ");
    }
    printf("\n");
}