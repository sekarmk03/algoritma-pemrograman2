#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    float duration;
    char title[30], id;
} arrlist;

void input(arrlist song[], int n, char id);
void insertion(arrlist song[], int n, char type);
void bubble(arrlist song[], int n, char type);
void quick(arrlist song[], int kiri, int kanan, char type);
void selection(arrlist song[], int n, char type);
void swap(arrlist *awal, arrlist *akhir);
void merge(arrlist song1[], arrlist song2[], int n, int m, arrlist result[], char type);
void output(arrlist result[], int n, arrlist ibnu[]);