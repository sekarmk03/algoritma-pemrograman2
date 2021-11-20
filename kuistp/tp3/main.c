/*=== Library ===*/
#include "header.h"

/*=== Fungsi Utama ===*/
int main(){
    int a[100], b[100], c[100], n, hasil[100];
    //-----------------------------^penampung hasil pemrosesan (jml bakteri jam ke-c)
    //--------------------------^banyak masukan & keluaran (bakteri)
    //------------------^jam yg ditanyakan
    //----------^jml bakteri jam ke-1
    //--^jml bakteri jam ke-0
    scanf("%d", &n); //-------------> meminta masukan n (bakteri)
    InOut(n, a, b, c, hasil); //----> memanggil fungsi masukan dan keluaran < mesin.c line 23 - 41 >
    return 0;
}