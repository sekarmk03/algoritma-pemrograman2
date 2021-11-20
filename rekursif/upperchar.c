#include <stdio.h>

int sc(char str[], int idx){
    if(str[idx] >= 65 && str[idx] <= 90){
        return idx;
    } else {
        return sc(str, idx+1);
    }
}

int main(){
    char string[30];
    scanf("%s", string);
    printf("%c -> %d\n", string[sc(string, 0)], sc(string, 0));
    return 0;
}