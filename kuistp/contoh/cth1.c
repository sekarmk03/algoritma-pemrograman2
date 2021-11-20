#include <stdio.h>
#include <string.h>

int main()
{
    int arr[5]; // 0, 1, 2, 3, 4
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
        scanf("%d", &arr[i]);
    }
    printf("hasil :\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}