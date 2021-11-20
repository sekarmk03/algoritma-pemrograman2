#include "header.h"

int main()
{
    int n, i, del = 0;
    char pita[200];
    scanf("%d", &n);

    mahasiswa dataMhs[n];

    for (i = 0; i < n; i++)
    {
        scanf(" %199[^\n]s", pita);
        if (strcmp(getCKata(), "INSERT") == 0)
        {
            insertData(pita, &dataMhs[i]);
        }
        else if (strcmp(getCKata(), "DELETE") == 0)
        {
            deleteData(pita, dataMhs);
            del++;
        }
    }

    printf("Data Mahasiswa :\n");
    int no = 1;
    for (i = 0; i < n - del; i++)
    {
        if (dataMhs[i].nim[0] != '\0')
        {
            printf("%d. %s %s %s\n", no, dataMhs[i].nim, dataMhs[i].nama, dataMhs[i].nilai);
            no++;
        }
    }
    return 0;
}