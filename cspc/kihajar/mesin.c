#include "header.h"

int Prima(int n){
    int prima = n, count = 0;
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 1; j <= prima; j++)
        {
            if(prima % j == 0){
                count++;
            }
        }
        if(count == 2){
            return prima;
        } else {
            prima++;
        }
        count = 0;
    }
}