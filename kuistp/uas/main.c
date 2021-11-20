#include "header.h"

int main(){
    char pita[300];
    int found = 0, controlIncKata = 0, count = 0;
    char result[100][20];
    scanf(" %299[^\n]s", pita);
    startKata(pita);
    start(pita);
    // while (eopKata(pita) == 0){
        while (eop() == 0){
            if(controlIncKata != 0){
                incKata(pita);
                adv(pita);
            }
            printf("%c -", getCC());
            // int saveIdx[4];
            char temp[20], tempKata[20];
            if(getCC() >= 97 && getCC() <= 122){
                if(eop() == 0 && count == 0 && (getCC() == 'a' || getCC() == 'i' || getCC() == 'u' || getCC() == 'e' || getCC() == 'o')){
                    // saveIdx[count] = idxChar;
                    temp[count] = getCC();
                    count++;
                    printf("%c [%d] count %d\n", getCC(), idxChar, count);
                    inc(pita);
                    if(eop() == 0 && count == 1 && (getCC() != 'a' || getCC() != 'i' || getCC() != 'u' || getCC() != 'e' || getCC() != 'o')){
                        // saveIdx[count] == idxChar;
                        temp[count] = getCC();
                        count++;
                        printf("%c [%d] count %d\n", getCC(), idxChar, count);
                        inc(pita);
                        if(eop() == 0 && count == 2 && (getCC() != 'a' || getCC() != 'i' || getCC() != 'u' || getCC() != 'e' || getCC() != 'o')){
                            // saveIdx[count] == idxChar;
                            temp[count] = getCC();
                            count++;
                            printf("%c [%d] count %d\n", getCC(), idxChar, count);
                            inc(pita);
                            if(eop() == 0 && count == 3 && (getCC() == 'a' || getCC() == 'i' || getCC() == 'u' || getCC() == 'e' || getCC() == 'o')){
                                // saveIdx[count] = idxChar;
                                temp[count] = getCC();
                                count++;
                                printf("%c [%d] count %d\n", getCC(), idxChar, count);
                                inc(pita);
                            }
                        }
                    }
                }
            }
            if(count == 4){
                strcpy(result[found], temp);
                found++;
            }
            count = 0;
            controlIncKata = 1;
        }
    // }
    printf("\n%d\n", found);
    return 0;
}