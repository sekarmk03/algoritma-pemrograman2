#include "header.h"

int main(){
    int i, n[3] = {1};
    arrlist song[3][n[0]];
    for (i = 0; i < 3; i++){
        scanf("%d", &n[i]);
        song[i][n[i]];
        input(song[i], n[i], 'x');
    }
    
    /*int n1, n2, n3;
    scanf("%d", &n2); arrlist adik[n2]; input(adik, n2, 'y');
    scanf("%d", &n3); arrlist ayah[n3]; input(ayah, n3, 'z');
    char method, type;
    if(method == 'i')
        insertion();
    else if(method == 's')
        selection();
    else if(method == 'q')
        quick();
    else
        bubble();
    */
    for(i = 0; i < n[0]; i++){
        printf("%0.2f %s %c\n", song[0][i].duration, song[0][i].title, song[0][i].id);
    }
    for(i = 0; i < n[1]; i++){
        printf("%0.2f %s %c\n", song[1][i].duration, song[1][i].title, song[1][i].id);
    }
    for(i = 0; i < n[2]; i++){
        printf("%0.2f %s %c\n", song[2][i].duration, song[2][i].title, song[2][i].id);
    }

    return 0;
}