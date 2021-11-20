#include "header.h"

int main(){

	int i,j; //deklarsi variabel untuk iterasi
	int awal[30][30];//deklarasi matrix awal
	int hasil[30][30];//deklarasi matrix awal

	scanf("%d %d", &baris, &kolom);	//meminta masukan user
	
	for(i=0; i<baris; i++){
		for(j=0; j<kolom; j++){
			scanf(" %d", &awal[i][j]);	//memasukkan matrik awal
			hasil[i][j]=awal[i][j];		//memasukkan isi matrix awal ke matrix akhir
		}
	}

	/*dengan pass by reference, isi matrix hasil pada main akan
	 otomatis terupdate jika terjadi perubahan di prosedur*/
	refleksi_atas(hasil); 	//memanggil prosedur refleksi dengan parameter matrix hasil
	transpose(hasil); 		//memanggil prosedur refleksi dengan parameter matrix hasil

	int putar;
	putar = hitung(hasil); 	//memanggil fungsi hitung kemudia menyimpannya nilai kembaliannya ke variabel putar
	rotasi(putar, hasil);	//memanggil prosedur rotasi
	
	//print matrix ke layar
	for(i=0; i<baris; i++){
		for(j=0; j<kolom; j++){
			if(j == kolom-1){
				printf("%c", hasil[i][j]);
			}else{
				printf("%c ", hasil[i][j]);
			}
		}
		printf("\n");
	}

	if(ket(awal, hasil)==0){//memanggil fungsi int kemudian membandingkannya
		printf("Coba lagi besok!\n");
	}else{
		printf("Wihh matrix yang seru!\n");
	}

	return 0;
}