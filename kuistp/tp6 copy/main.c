#include "header.h"

int main(){
    int n1, n2, n3;
    scanf("%d", &n1); arrlist ibnu[n1]; input(ibnu, n1, 'x');
    scanf("%d", &n2); arrlist adik[n2]; input(adik, n2, 'y');
    scanf("%d", &n3); arrlist ayah[n3]; input(ayah, n3, 'z');
    arrlist result[n1+n2], final[n1+n2+n3];
    char method, type;
    scanf(" %c %c", &method, &type);
    if(method == 'i'){
        insertion(ibnu, n1, type); insertion(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        insertion(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    } else if(method == 's'){
        selection(ibnu, n1, type); selection(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        selection(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    } else if(method == 'q'){
        quick(ibnu, 0, n1-1, type); quick(adik, 0, n2-1, type);
        merge(ibnu, adik, n1, n2, result, type);
        quick(ayah, 0, n3-1, type); merge(result, ayah, n1+n2, n3, final, type);
    } else{
        bubble(ibnu, n1, type); bubble(adik, n2, type);
        merge(ibnu, adik, n1, n2, result, type);
        bubble(ayah, n3, type); merge(result, ayah, n1+n2, n3, final, type);
    }
    output(final, n1+n2+n3, ibnu);
    return 0;
}