#include <stdio.h>

void Tulis(int n){
    int counter;
    counter = n;
    if (counter >= 0)
    {
        printf("proses rekursif dengan nilai counter : %d\n", counter);
        counter--;
        Tulis(counter);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Tulis(n);
    return 0;
}