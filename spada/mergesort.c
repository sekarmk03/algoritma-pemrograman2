#include <stdio.h>

int main(){
    int n1, n2, i, j, counter1 = 0, counter2 = 0, counter3 = 0, counter = 0;
    scanf("%d %d", &n1, &n2);
    int tabel1[n1], tabel2[n2], tabel3[n1+n2];
    for ( i = 0; i < n1; i++)
    {
        scanf("%d", &tabel1[i]);
    }
    for ( i = 0; i < n2; i++)
    {
        scanf("%d", &tabel2[i]);
    }
    while ((counter1 < n1) && (counter2 < n2))
    {
        if(tabel1[counter1] < tabel2[counter2])
        {
            tabel3[counter3] = tabel1[counter1];
            counter1++; counter3++;
        }
        else if(tabel1[counter1] > tabel2[counter2])
        {
            tabel3[counter3] = tabel2[counter2];
            counter2++; counter3++;
        }
        else
        {
            tabel3[counter3] = tabel1[counter1];
            counter1++; counter3++;
            tabel3[counter3] = tabel2[counter2];
            counter2++; counter3++;
        }
    }
    if(counter1 < n1)
    {
        for ( counter = counter1; counter < n1; counter++)
        {
            tabel3[counter3] = tabel1[counter1];
            counter3++;
        }
    }
    if (counter2 < n2)
    {
        for ( counter = counter2; counter < n2; counter++)
        {
            tabel3[counter3] = tabel2[counter2];
            counter3++;
        }
    }
    for ( i = 0; i < n1+n2; i++)
    {
        printf("%d ", tabel3[i]);
    }
    printf("\n");
    return 0;
}