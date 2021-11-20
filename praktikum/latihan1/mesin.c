#include "header.h"

//mulai cek pita
void startKata(char pita[]){
	indeks = 0; //karena start ada diawal pita, maka nilai indeks adalah 0
	panjangkata = 0;
	/*kondisi ini berlaku bila pada awal pita terdapat beberapa
	spasi sebelum kata pertama*/
	while(pita[indeks] == ' ') {
	    indeks++;
	}
	//proses menampung kata pertama
	while((pita[indeks] != ' ') && (eopKata(pita) == 0)) {
	    currentKata[panjangkata] = pita[indeks];
	    indeks++;
	    panjangkata++;
	}
	//kosongkan karakter pada indeks panjang dari kata tampungan
	currentKata[panjangkata] = '\0';
}
//reset tampungan kata
void resetKata(){
	panjangkata = 0;
	currentKata[panjangkata] = '\0';
}
//maju satu kata pada pita
void incKata(char pita[]){
	panjangkata = 0;
	/*kondisi ini berlaku bila pada pengecekan pita terdapat beberapa
	spasi sebelum kata berikutnya*/
	while(pita[indeks] == ' ') {
	    indeks++;
	}
	//proses menampung kata berikutnya
	while((pita[indeks] != ' ') && (eopKata(pita) == 0)) {
	    currentKata[panjangkata] = pita[indeks];
	    indeks++;
	    panjangkata++;
	}

	currentKata[panjangkata] = '\0';
}
//dapatkan kata yang sedang ditampung
char *getCurrentKata(){
	return currentKata;
}
//dapatkan panjang kata yang sedang ditampung
int getPanjangKata(){
	return panjangkata;
}
//pengecek apakah pita inputan sudah selesai
int eopKata(char pita[]){
	//bila bertemu titik, maka itu adalah akhir dari pita inputan
	if (pita[indeks] == '.') return 1;
	else return 0;
}
