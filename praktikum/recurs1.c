#include <stdio.h>

void alf(int n){
    printf("%c ", n);
    if(n > 'a'){
        alf(n - 1);
    }
}

int main(){
    alf('z');
    return 0;
}