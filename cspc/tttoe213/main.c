#include "header.h"

int main(){
    int P1[3][2], P2[3][2];
    for (int i = 0; i < 6; i++)
    {
        scanf("%s %c", ttt[i].pemain, &ttt[i].tanda);
        if(strcmp(ttt[i].pemain, "P1") == 0){
            for (int j = 0; j < 2; j++)
            {
                scanf("%d%d", &P1[i][j]);
            }
        } else {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d%d", &P2[i][j]);
            }
        }
    }
    int cek;
    return 0;
}