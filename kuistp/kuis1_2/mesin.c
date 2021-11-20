#include "header.h"

/*=== Prosedur ===*/
void Bagi(unsigned long int a, unsigned long int b){
    /*
        * prosedur rekursif
        * var a dibagi 2 setiap rekursif
        * var b dikali 2 setiap rekursif
    */
    if (a == 1)
    {
        // base case jika a mencapai nilai 1
        printf("(%lu|%lu)\n", a, b); //-----------------------> mencetak hasil akhir a dan b
    }
    else
    {
        // kondisi ketika harus di rekursif (nilai a belum 1)
        printf("(%lu|%lu)\n", a, b); //-----------------------> mencetak hasil a dan b setiap rekursif
        Bagi(a/2, b*2); //------------------------------------> memanggil prosedur rekursif
    }
}