#include "header.h"

int main()
{
    // var lokal fungsi main
    int n, i, j;
    char sortBy[50];
    //----------------------------^menampung "nama"/"harga"/"penilaian"
    //----------------^menampung metode "insertion"/"selection"
    //-----^--^iterator dan penanda indeks
    //--^banyaknya data
    scanf("%d", &n); //--------------------------------------------> meminta inputan banyak data
    // perulangan inputan data sebanyak n
    for (i = 0; i < n; i++)
    {
        scanf("%s%d%f", d[i].nama, &d[i].harga, &d[i].rating);
    }
    scanf("%s%s%s", method, type, sortBy); //----------------------> meminta inputan metode, tipe, dan berdasarkan apa
    if (strcmp(method, "insertion") == 0)
    {
        // jika metode insertion
        // panggil prosedur insertion
        insert(n, sortBy);
    }
    else
    {
        // jika tidak
        // panggil prosedur selection
        sel(n, sortBy);
    }
    // cetak data yang telah diurutkan ke layar
    cetak(n);
    return 0;
}