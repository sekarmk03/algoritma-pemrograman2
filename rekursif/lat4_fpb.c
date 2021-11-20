#include <stdio.h>

int CariFPB(int a, int b){
    if(b == 0) {
        return a;
    } else {
        int temp = a % b;
        return CariFPB(b, temp);
    }
}

int main(){
    int bil1, bil2, hasil;
    scanf("%d%d", &bil1, &bil2);
    hasil = CariFPB(bil1, bil2);
    printf("FPB dari %d dan %d adalah %d\n", bil1, bil2, hasil);
    return 0;
}