#include <stdio.h>
#include <time.h>

void wait(float x){
    time_t start;
    time_t current;
    time(&start);
    do
    {
        time(&current);
    } while (difftime(current,start) < x);
}

int main(){
    char arr[6][6];
    int i, j, x = -1, y = -1, jalan = 1;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            arr[i][j] = '-';
        }
    }
    while(1){
        system("cls");
        if((x >= 0) && (x < 6)){
            arr[x][y] = '-';
        }
        if((x == 6) && (y == 6)){
            jalan = -1;
            x--;
            y--;
        } else if((x == -1) && (y == -1)){
            jalan = 1;
            x++;
            y++;
        } else if(jalan == 1){
            x++;
            y++;
        } else {
            x--;
            y--;
        }
        if((x >= 0) && (x < 6)){
            arr[x][y] = 'B';
        }
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                if(arr[i][j] == '-'){
                    printf("    ");
                } else {
                    printf(" %c ", arr[i][j]);
                }
            }
            printf("\n");
        }
        wait(1);
    }
    return 0;
}