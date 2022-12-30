#include "header.h"

void showMenu(){
	int i;
    system("cls");
	printf("\n\t");
	
	for(i=0;i<60;i++){
		printf("=");
	}

	printf("\n\n\t\tSILAHKAN LOGIN TERLEBIH DAHULU [ADMIN / DOKTER]");
	printf("\n\n\t");
	
    for(i=0;i<60;i++){
		printf("=");
	}
	
    printf("\n\n");
	getch();
}

void showMenuAdm(){
    system("cls");
    printf("\n\t\t=====< MENU DOKTER >=====");
    printf("\n\t\t[1]. Tambah Data Dokter");
    printf("\n\t\t[2]. Tampil Data Dokter");
    printf("\n\t\t[3]. Cari Data Dokter");
    printf("\n\t\t[4]. Ubah Data Dokter");
    printf("\n\t\t[5]. Hapus Data Dokter");

    printf("\n\n\t\t=====< MENU HEWAN >=====");
    printf("\n\t\t[6]. Pendaftaran Periksa Hewan");
	printf("\n\t\t[7]. Hapus Data Hewan");
	printf("\n\t\t[8]. Tampil Data Hewan");
	printf("\n\t\t[9]. Input Data Periksa");
    printf("\n\n\t\t[ESC]. Keluar");
    printf("\n\t\t>>> ");
}

void showMenuDKT(){
	system("cls");
	printf("\n\t\t=====< MENU DOKTER >=====");
    printf("\n\t\t[1]. Periksa Hewan");
    printf("\n\t\t[2]. Lihat Riwayat");
	printf("\n\t\t[ESC]. Keluar");
}

