#include <stdio.h>

void tower(int n, char awal, char akhir, char antara){
    if(n == 1){
        printf("pindahkan piringan ke-%d dari tiang %c ke tiang %c\n", n, awal, akhir);
    } else {
        tower((n-1), awal, antara, akhir);
        printf("pindahkan piringan ke-%d dari tiang %c ke tiang %c\n", n, awal, akhir);
        tower((n-1), antara, akhir, awal);
    }
}

int main(){
    tower(3, 'A', 'C', 'B');
    return 0;
}