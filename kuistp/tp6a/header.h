#include <stdio.h>
#include <string.h>

typedef struct {
    float duration;
    char title[30], id;
} arrlist;

void input(arrlist song[], int n, char id);