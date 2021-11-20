#include "header.h"

int main()
{
    char result[100][50], pita[300];
    //--------------------^menampung pita
    //---^menampung string hasil yg memenuhi spesifikasi
    int cek = 0, found = 0, control = 0;
    //----------------------^mengontrol increment kata
    //-----------^menghitung jumlah string yg memenuhi spesifikasi
    //--^mengatur perulangan
    scanf("%299[^\n]s", pita); //-----------------------------------------> meminta masukan pita
    startKata(pita); //---------------------------------------------------> mulai membaca pita per kata
    while (eopKata(pita) == 0) //-----------------------------------------> selama tidak menemukan akhir pita
    {
        if (control != 0) //----------------------------------------------> perulangan ke-2 dst, majukan pita
            incKata(pita);
        char tampung[50]; //----------------------------------------------> penampung kata pita
        strcpy(tampung, getCKata()); //-----------------------------------> tampung kata saat ini
        tampung[getPKata()] = '.'; //-------------------------------------> beri titik di akhir kata
        start(tampung); //------------------------------------------------> mulai membaca kata yg ditampung
        while (eop() == 0 && cek == 0) //---------------------------------> selama tidak bertemu titik dan
        { //--------------------------------------------------------------> kondisi spesifikasi belum terpenuhi
            char temp[6]; //----------------------------------------------> array pengecekan karakter
            temp[0] = getCC(); //-----------------------------------------> tampung karakter pertama
            inc(tampung); //----------------------------------------------> majukan karakter
            if ((eop() == 0) && (temp[0] != ' ') && //--------------------> jika karakter pertama vokal
                (temp[0] == 'a' || temp[0] == 'i' || temp[0] == 'u' || temp[0] == 'e' || temp[0] == 'o'))
            {
                temp[1] = getCC(); //-------------------------------------> tampung karakter kedua
                if ((eop() == 0) && (temp[1] != ' ') &&  //----------------> jika karakter kedua konsonan
                    (temp[1] != 'a' && temp[1] != 'i' && temp[1] != 'u' && temp[1] != 'e' && temp[1] != 'o'))
                {
                    inc(tampung); //--------------------------------------> majukan karakter
                    temp[2] = getCC(); //---------------------------------> tampung karakter ketiga
                    if ((eop() == 0) && (temp[2] != ' ') && //------------> jika karakter ketiga konsonan
                        (temp[2] != 'a' && temp[2] != 'i' && temp[2] != 'u' && temp[2] != 'e' && temp[2] != 'o'))
                    {
                        inc(tampung); //----------------------------------> majukan karakter
                        temp[3] = getCC(); //-----------------------------> tampung karakter keempat
                        if ((eop() == 0) && (temp[3] != ' ') && //--------> jika karakter keempat konsonan
                            (temp[3] != 'a' && temp[3] != 'i' && temp[3] != 'u' && temp[3] != 'e' && temp[3] != 'o'))
                        {
                            inc(tampung); //------------------------------> majukan karakter
                            if ((eop() == 0) && (getCC() != ' ') && //----> jika karakter saat ini vokal
                                (getCC() == 'a' || getCC() == 'i' || getCC() == 'u' || getCC() == 'e' || getCC() == 'o'))
                            {
                                tampung[getPKata()] = '\0'; //------------> tutup string
                                strcpy(result[found], tampung); //--------> simpan ke array hasil
                                cek = 1; //-------------------------------> agar loop berhenti, lanjut ke kata berikutnya
                                found++; //-------------------------------> menambah jumlah string yg memenuhi karakter
                            }
                        }
                    }
                }
            }
        }
        control = 1; //---------------------------------------------------> mengontrol increment kata dlm pita
        cek = 0; //-------------------------------------------------------> mengembalikan nilai cek
    }
    for (int i = 0; i < found; i++) //------------------------------------> mencetak semua string yg memenuhi spesifikasi
        printf("%s\n", result[i]);
    printf("%d\n", found); //---------------------------------------------> mencetak jumlah string yg memenuhi spesifikasi
    return 0;
}