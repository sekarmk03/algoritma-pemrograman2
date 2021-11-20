#include "sekar.h"

int main()
{
    char nama[50];                   // tampungan nama
    char id[100];                    // tampungan id
    int found = 0;                   // penanda ditemukannya kode rahasia
    scanf("%s %99[^\n]s", nama, id); // meminta masukan nama dan id
    start(id);                       // menjalankan mesin kata, memproses kalimat id
    while (eop() == 0 && found == 0) // selama bukan akhir kalimat dan kode rahasia tidak ditemukan
    {
        char temp1 = getCC();                 // penampung huruf ke-1
        inc(id);                              // memajukan pita kalimat
        if ((temp1 == 'x') || (temp1 == 'r')) // jika ditemukan calon kode rahasia (huruf x atau r)
        {
            if (eop() == 0) // jika bukan akhir kalimat
            {
                char temp2 = getCC(); // penampung huruf kedua
                inc(id);              // memajukan pita kalimat
                if (eop() == 0)       // jika bukan akhir kalimat
                {                     // jika bertemu kode rahasia (xcv atau xar atau rar)
                    if (((temp1 == 'x') && (temp2 == 'c') && (getCC() == 'v')) || ((temp1 == 'x') && (temp2 == 'a') && (getCC() == 'r')) || ((temp1 == 'r') && (temp2 == 'a') && (getCC() == 'r')))
                    {
                        found = 1; // tandai
                    }
                }
            }
        }
    }
    if (found == 1) // jika terdapat substring kode rahasia
    {
        printf("%s adalah Agen Rahasia.\n", nama);
    }
    else // jika tidak terdapat substring kode rahasia
    {
        printf("%s adalah pegawai biasa.\n", nama);
    }
    return 0;
}