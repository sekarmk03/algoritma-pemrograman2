#include "header.h"

void input(arrlist song[], int n, char id){
    for (int i = 0; i < n; i++){
        scanf("%f%s", &song[i].duration, &song[i].title);
        song[i].id = id;
    }
}

