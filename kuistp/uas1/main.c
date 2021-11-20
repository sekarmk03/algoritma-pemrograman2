#include "header.h"

int main()
{
    char result[100][30], pita[300];
    //--------------------^menyimpan pita
    //---^menampung hasil
    int found = 0; //------------------------------------------> penanda ada kata yg memenuhi spesifikasi
    scanf("%299[^\n]s", pita); //------------------------------> meminta masukan kata
    start(pita); //----------------------------------------> mulai membaca pita
    while (eop() == 0) //--------------------------------------> selama tidak bertemu akhir pita
    {
        char temp[5]; //---------------------------------------> penampung string yang memenuhi spesifikasi
        temp[0] = getCC(); //----------------------------------> tampung karakter pertama
        inc(pita); //------------------------------------------> majukan karakter
        if ((eop() == 0) && (temp[0] != ' ') && //-------------> jika karakter pertama vokal
            (temp[0] == 'a' || temp[0] == 'i' || temp[0] == 'u' || temp[0] == 'e' || temp[0] == 'o'))
        {
            temp[1] = getCC(); //------------------------------> tampung karakter kedua
            inc(pita); //----------------------------------> majukan karakter
            if ((eop() == 0) && (temp[1] != ' ') && //---------> jika karakter kedua konsonan
                (temp[1] != 'a' && temp[1] != 'i' && temp[1] != 'u' && temp[1] != 'e' && temp[1] != 'o'))
            {
                temp[2] = getCC(); //--------------------------> tampung karakter ketiga
                inc(pita); //------------------------------> majukan karakter
                if ((eop() == 0) && (temp[2] != ' ') && //-----> jika karakter ketiga konsonan
                    (temp[2] != 'a' && temp[2] != 'i' && temp[2] != 'u' && temp[2] != 'e' && temp[2] != 'o'))
                {
                    if ((eop() == 0) && (getCC() != ' ') && //-> jika karakter saat ini vokal
                        (getCC() == 'a' || getCC() == 'i' || getCC() == 'u' || getCC() == 'e' || getCC() == 'o'))
                    {
                        temp[3] = getCC(); //------------------> tampung karakter saat ini
                        temp[4] = '\0'; //---------------------> tutup string
                        strcpy(result[found], temp); //--------> pindahkan string yg memenuhi spesifikasi ke hasil
                        found++; //----------------------------> tambah jumlah string yg memenuhi spesifikasi
                        inc(pita); //--------------------------> majukan karakter
                    }
                }
            }
        }
    }
    // output
    for (int i = 0; i < found; i++) //-------------------------> cetak seluruh string hasil
    {
        printf("%s\n", result[i]);
    }
    printf("%d\n", found); //----------------------------------> cetak jumlah string yg memenuhi spesifikasi
    return 0;
}