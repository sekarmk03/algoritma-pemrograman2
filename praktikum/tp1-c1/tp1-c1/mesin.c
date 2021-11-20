#include "header.h"

void refleksi_kanan(int hasil[30][30]){
	int i,j,a; //untuk iterasi perulangan
	int temp[baris][kolom];//untuk matrix sementara

	//proses refleksi
	for(i=0; i<baris; i++){
		a=0;
		for(j=kolom-1; j>=0; j--){
			temp[i][a++]=hasil[i][j];//tempnya dimasukkan ke temp
		}
	}

	/*
	** temp dimasukkan kembali ke hasil agar 
	** isi yang telah diubah berada pada hasil
	*/
	for(i=0; i<baris; i++){
		for(j=0; j<kolom; j++){
			hasil[i][j]=temp[i][j];//temp dimasukkan ke hasil
		}
	}
}

void refleksi_atas(int hasil[30][30]){
	int i,j,a; //untuk iterasi perulangan
	int temp[baris][kolom];//untuk matrix sementara

	//proses refleksi
		a=0;
	for(i=baris-1; i>=0; i--){
		for(j=0; j<kolom; j++){
			temp[a][j]=hasil[i][j];//hasil dimasukkan ke temp
		}
		a++;
	}

	/*
	** temp dimasukkan kembali ke hasil agar 
	** isi yang telah diubah berada pada hasil
	*/
	for(i=0; i<baris; i++){
		for(j=0; j<kolom; j++){
			hasil[i][j]=temp[i][j];//temp dimasukkan ke hasil
		}
	}
}

void transpose(int hasil[30][30]){
	int i,j;//untuk iterasi perulangan
	int temp[kolom][baris];//untuk matrix sementara

	//proses transpose
	for(i=0; i<kolom; i++){
		for(j=0; j<baris; j++){
			temp[i][j]=hasil[j][i];//hasil dimasukkan ke temp
		}
	}

	/*
	** temp dimasukkan kembali ke hasil agar 
	** isi yang telah diubah berada pada hasil
	*/
	for(i=0; i<kolom; i++){
		for(j=0; j<baris; j++){
			hasil[i][j]=temp[i][j];//temp dimasukkan ke hasil
		}
	}

	//mengubah kolom dan baris matrix hasil
	int a;
	a = baris;
	baris = kolom;
	kolom = a;
}

//untuk rotasi sebanyak 2 kali
void putar_2(int hasil[30][30]){
	int i,j, a=0, b=0;//untuk iterasi perulangan
	int temp[baris][kolom];//untuk matrix sementara

	for(i=baris-1; i>=0; i--){
		b=0;
		for(j=kolom-1; j>=0; j--){
			//printf("%d %d \n", a, b);
			temp[a][b++]=hasil[i][j];//hasil dimasukkan ke temp
		}
		a++;
	}

	for(i=0; i<baris; i++){
		for(j=0; j<kolom; j++){
			hasil[i][j]=temp[i][j];//temp dimasukkan ke hasil			
		}
	}
}

//untuk menghitung jumlah kolom dan menentukan arah rotasi
int hitung(int hasil[30][30]){
	int i, jumlah=0;

	for(i=0; i<baris; i++){
		jumlah = jumlah + hasil[i][kolom-1];//menjumlahkan kolom
	}

	if((jumlah%2) == 0){
		//genap kiri
		arah = 0;
	}else{
		//ganjil kanan
		arah = 1;
	}

	return jumlah%4; //mengembalikkan nilai dari modulus jumlah%4
}

void rotasi(int putar, int hasil[30][30]){
	if(((arah == 0) && (putar == 1)) || ((arah == 1) && (putar == 3))){
		//rotasi ke kiri sebanyak 1 atau ke kanan sebanyak 3
		refleksi_kanan(hasil);
		transpose(hasil);
	}else if(putar == 2){
		//rotasi sebanyak 2 kali
		putar_2(hasil);
	}else if((arah == 0) && (putar == 3) || ((arah == 1) && (putar == 1))){
		//rotasi ke kiri sebanyak 3 atau ke kanan sebanyak 1
		transpose(hasil);
		refleksi_kanan(hasil);
	}
}

int ket(int awal[30][30], int hasil[30][30]){
	int i=0, j=0, cek=0;

	//menggunakan while karena jika sudah ada isi matrix yang berbeda maka perulangan langsung berhenti
	while(i<baris && cek==0){
		j=0;
		while(j<kolom && cek==0){
			if(awal[i][j] != hasil[i][j]) cek=1;
			j++;
		}
		i++;
	}

	//jika cek=0 maka matrix sama, jika cek=1 matrix berbeda
	return cek;//mengembalikkan nilai cek
}