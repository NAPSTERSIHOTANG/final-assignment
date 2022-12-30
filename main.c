#include "header.h"

int main(int argc, char *argv[]) {
	
	int pos = 0; char kursor, menu;
	string nama = "", password = "";
	Multilist ML, R; List H;
	AddressParent tempAddP, mainAddP, tempUser; address P;
	DataParent DP; DataChild DC; MasterHewan MH; 
	AddressChild tempAddC;
	createEmpty(&R); createEmpty(&ML); makeEmpty(&H);
	//createEmptyObat(&ML);
	int tahun, bulan, hari, mainLogin = 0;
	int id=0, hwn=0, rwt=0;
	int index, index2, jml, i, x = 0, y = 0;
	
	MaximizeOutputWindow();
	
	do{
		do{
			system("cls");
			 //outInBorder(20, 30);
			creatingMainLogin(50, 5, 10, 50, pos);
			
			gotoxy(75, 13); printf("%s", nama);
			gotoxy(75, 17); printf("%s", password);
			
			gotoxy(50, 30); printf("[!] Use your keypad to navigate [ W / S ] : "); kursor=getch();
			
			if('W'==kursor || 'w'==kursor){
				if(pos==0){
					
				}else{
					pos--;				
				}
			}else if('S'==kursor || 's'==kursor){
				if(pos==2){
					
				}else{
					pos++;
				}
			}else if(kursor==13){
				if(pos==0){
					gotoxy(75, 13); fflush(stdin); gets(nama);
				}else if(pos==1){
					gotoxy(75, 17); fflush(stdin); gets(password);
				}else if(pos==2){
					if(strcmpi(nama, "Keluar")==0 && strcmpi(password, "Keluar")==0){
						menu=27;
						break;
					}else{
						errorHandlingLogin(50, 20, 5, 50);
										
						if(strcmp(nama, "admincintasatwa")==0 && strcmp(password, "admincintasatwa")==0){
							mainLogin = 1;
							break;
						}else if(!isEmptyML(ML)){
							tempAddP = findParent(ML, nama);
		
							if(strcmpi(tempAddP->dataParent.username, nama)==0 && strcmpi(tempAddP->dataParent.password, password)==0){
								mainAddP = tempAddP;	
								mainLogin = 2;
								gotoxy(54, 22); printf("[!] Login sebagai %s", mainAddP->dataParent.nama);
								getch();
								break;
							}else{
								gotoxy(54, 22); printf("[!] Data dokter belum ada sama sekali");
							}
						}else{
							mainLogin = 0;
							if(isEmptyML(ML)){
								gotoxy(54, 22); printf("[!] Data dokter belum ada sama sekali");
							}else{
								printf("[!] Username ataupun password Anda tidak ditemukan");				
							}
						}
						strcpy(nama, ""); strcpy(password, "");
						getch();
						// BERHASIL LOGIN					
					}
				}
			}
		}while(true);

		system("cls");
		pos=0;

		if(mainLogin==1){
			do{
				system("cls"); x = y = 0;
				creatingMainAdmin(50, 5, 42, 49, pos); creatingMainAdmin(50+60, 5, 42, 49, pos);
				allPrintAdminMenu(50, 5, 40, 49, pos);
				
				kursor=getch();
				
				if(kursor=='W' || kursor=='w'){
					if(pos==0){
						pos=9;
					}else{
						pos--;
					}
				}else if(kursor=='S' || kursor=='s'){
					if(pos==9){
						pos=0;
					}else{
						pos++;
					}
				}else if(kursor=='D' || kursor=='d'){
					if(pos<5){
						pos+=5;
					}else{
						pos-=5;
					}
				}else if(kursor=='A' || kursor=='a'){
					if(pos>4){
						pos-=5;
					}else{
						pos+=5;
					}
				}else if(kursor==13){
					menu = switchingMenuAdmin(pos);
					
					if(menu=='0'){
						getch();
						break;
					}else if(menu=='1'){
						y = 10; x=5;
						popupMenu(x, y, 20, 70, pos);
						
						y+=4; x+=75; gotoxy(x, y); printf("=====< INPUT DATA DOKTER >=====");
						
						y++; x-=20; gotoxy(x, y); printf("\tNama Dokter\t\t : "); fflush(stdin); gets(DP.nama);
						while(strlen(DP.nama)<0){
							y++; gotoxy(x, y); printf("\t[!] Nama Dokter Tidak Boleh Kosong");
							y++; printf("\tNama Dokter\t\t : "); fflush(stdin); gets(DP.nama);
						}
						
						id++;
						DP.id=id;
						y++; gotoxy(x, y); printf("\tID Dokter\t\t : %d\n",DP.id);
						
						while(true){
							y++; gotoxy(x, y); printf("\tTanggal Bergabung\t : "); fflush(stdin); gets(DP.tanggal);
	
								if(strlen(DP.tanggal)== 10){
									if(DP.tanggal[2] == '-' && DP.tanggal[5] == '-'){
									sscanf(DP.tanggal, "%d-%d-%d", &hari, &bulan, &tahun);

										if((hari > 0 && hari < 32) && (bulan > 0 && bulan < 13)){
											break;
										}else if(!(hari > 0 && hari < 32)){
											y++; gotoxy(x, y); printf("\t[!] Format tanggal harus diantara 1 - 31");
										}else if(!(bulan > 0 && bulan < 13)){
											y++; gotoxy(x, y); printf("\t[!] Format bulan harus diantara 1 - 12");
										}else{
											break;
										}
									}else{
										y++; gotoxy(x, y); printf("\t[!] Format penanggalan yang seharusnya ");
										y++; gotoxy(x, y); printf("\tContoh : 22-10-2022");
									}
								}else{
									y++; gotoxy(x, y); printf("[!] Format Tanggal Salah invalid");
								}
							}
						
						y+=2; gotoxy(x, y); printf("\t\t=====< DATA LOGIN >=====\n");
						
						while(true){//error handling belum kalau username sama (done)
							//belum bisa -jospun
							y++; gotoxy(x, y); printf("\tUsername\t\t : "); fflush(stdin); gets(DP.username);
							if(strcmpi(DP.username, "-")==0 || strlen(DP.username)==0 || strcmpi(DP.username, " ")==0){
								y++; gotoxy(x, y); printf("\t\t[!] Format penamaan tidak boleh kosong\n");
							}else if(isUnikUser(ML, DP.username)){
								break;
							}else{
								y++; gotoxy(x, y); printf("\n\t\t[!]Username tidak boleh sama");
							}
						}

						while(true){
							y++; gotoxy(x, y); printf("\tPassword\t\t : "); fflush(stdin); gets(DP.password);
							if(strcmpi(DP.password, "-")==0 || strlen(DP.password)==0 || strcmpi(DP.password, " ")==0){
								y++; gotoxy(x, y); printf("\t\t[!] Format password tidak boleh kosong");
							}else{
								break;
							}
						}
						y+=2; gotoxy(x, y); printf("\t\t[!] Data berhasil dimasukkan");
						insertLastParent(&ML, DP);
						getch();
						
					}else if(menu=='2'){
						x = 5, y = 5;
						tableDokter(x, y, 20, 120, pos, ML, H);	
						getch();
						
					}else if(menu=='3'){
						y = 24; x = 5;
						popupMenu(x, y, 22, 70, pos);
						
						y += 4; x += 72; gotoxy(x, y); printf("=====< CARI DATA DOKTER >=====");
						
						y += 1; x -= 5; gotoxy(x, y); printf("ID Dokter	: "); scanf("%d", &DP.id);
						tempAddP = findDokter(ML, DP.id);
						
						if(tempAddP == NULL){
							y += 2; x += 2; gotoxy(x, y); printf("[!] DATA DOKTER TIDAK ADA");
						}else{
							y += 2; gotoxy(x, y); printf("Nama Dokter\t\t : %s", tempAddP->dataParent.nama);
				            y += 1; gotoxy(x, y); printf("Tanggal bergabung\t : %s", tempAddP->dataParent.tanggal);
				            y += 1; gotoxy(x, y); printf("ID\t\t\t : %d\n", tempAddP->dataParent.id);				            
//							tampilRiwayat(tempAddP);
						}
						getch();
					}else if(menu=='4'){
						x = 5; y = 12;
						popupMenu(x, y, 40, 90, pos);
							
						if(!isEmptyML(ML)){
							y += 5; x += 80; gotoxy(x,y); printf("=====< UBAH DATA DOKTER >=====");
							y++; gotoxy(x,y); printf("ID Dokter\t\t: "); scanf("%d", &DP.id);
							tempAddP = findDokter(ML, DP.id);
							
							if(tempAddP == NULL){
								y += 2; gotoxy(x,y); printf("[!] DATA DOKTER TIDAK ADA");
							}else{
								
								while(&DP.id<=0){
									y += 2; gotoxy(x,y); printf("[!] ID Dokter Tidak Boleh Kosong");
									y++; gotoxy(x,y); printf("ID Dokter\t\t: "); scanf("%d", &DP.id);
								}
								
								y++; gotoxy(x,y); printf("Nama Dokter\t\t : "); fflush(stdin); gets(DP.nama);
								while(strlen(DP.nama)<0){
									y += 2; gotoxy(x,y); printf("[!] Nama Dokter Tidak Boleh Kosong");
									y++; gotoxy(x,y); printf("Nama Dokter\t : "); fflush(stdin); gets(DP.nama);
								}
								
								while(true){
									y++; gotoxy(x,y); printf("Tanggal Bergabung\t\t : "); fflush(stdin); gets(DP.tanggal);
			
										if(strlen(DP.tanggal)== 10){
											if(DP.tanggal[2] == '-' && DP.tanggal[5] == '-'){
											sscanf(DP.tanggal, "%d-%d-%d", &hari, &bulan, &tahun);
		
												if((hari > 0 && hari < 32) && (bulan > 0 && bulan < 13)){
													break;
												}else if(!(hari > 0 && hari < 32)){
													y += 2; gotoxy(x,y); printf("[!] Format tanggal harus diantara 1 - 31");
												}else if(!(bulan > 0 && bulan < 13)){
													y += 2; gotoxy(x,y); printf("[!] Format bulan harus diantara 1 - 12");
												}else{
													break;
												}
											}else{
												y += 2; gotoxy(x,y); printf("[!] Format penanggalan yang seharusnya ");
												y += 2; gotoxy(x,y); printf(" Contoh : 22-10-2022\n");
											}
										}else{
											y += 2; gotoxy(x,y); printf("[!] Format penanggalan yang seharusnya ");
											y += 2; gotoxy(x,y); printf(" Contoh : 22-10-2022\n");
										}
									}
								
								y += 2; gotoxy(x,y); printf("=====< DATA LOGIN >=====");
								
								while(true){
									y++; gotoxy(x,y); printf("Username\t\t : "); fflush(stdin); gets(DP.username);
									if(strcmpi(DP.username, "-")==0 || strlen(DP.username)==0 || strcmpi(DP.username, " ")==0){
										y +=2; gotoxy(x,y); printf("[!] Format penamaan tidak boleh kosong");
									}else if(strlen(DP.username)>20){
										y +=2; gotoxy(x,y); printf("\t\t\t[!] Format penamaan tidak boleh lebih dari 20");
									}else{
										break;
									}
								}
	
								while(true){
									y++; gotoxy(x,y); printf("Password\t\t : "); fflush(stdin); gets(DP.password);
									if(strcmpi(DP.password, "-")==0 || strlen(DP.password)==0 || strcmpi(DP.password, " ")==0){
										y +=2; gotoxy(x,y); printf("[!] Format password tidak boleh kosong");
									}else if(strlen(DP.password)>20){
										y +=2; gotoxy(x,y); printf("[!] Format password tidak boleh lebih dari 20");
									}else{
										break;
									}
								}
								tempAddP->dataParent = DP;
							}
						}
						getch();

					}else if(menu=='5'){
						y = 11; x = 5;
						popupMenu(x, y, 30, 70, pos);					
						
						x += 72; y += 5;
						gotoxy(x, y); printf("=====< HAPUS DATA DOKTER >=====");
						
						x -= 6; y += 2;
						gotoxy(x, y); printf("ID Dokter	: "); scanf("%d", &DP.id);
						tempAddP = findDokter(ML,DP.id);
						//P = findHWNDkt(H,DP.id);
						if(tempAddP == NULL){
							y += 2; gotoxy(x, y); printf("[!] DATA DOKTER TIDAK ADA");
						}else{
							insertFirstParent(&R, tempAddP->dataParent);
							deleteAtParent(&ML, DP.id);
							
							y += 2; gotoxy(x, y); printf("Berhasil Hapus Data Dokter [*]");
						}
						getch();
					}else if(menu=='6'){
						y = 10; x = 65;
						
						popupMenu(x, y, 25, 90, pos);
						
						y += 6; x += 75; gotoxy(x, y); printf("=====< INPUT DATA HEWAN >=====");
							hwn++;
							MH.id = hwn;
							y+=2; x -= 10; gotoxy(x, y); printf("Nama Hewan\t\t : "); fflush(stdin); gets(MH.namaHewan);
							while(strlen(MH.namaHewan) == 0 || strcmpi(MH.namaHewan, "-") == 0 || strcmpi(MH.namaHewan, " ") == 0){
							y++; gotoxy(x, y); printf("[!] Nama hewan tidak boleh kosong");
							y++; gotoxy(x, y);	printf("Nama Hewan\t\t : "); fflush(stdin); gets(MH.namaHewan);
							}
							
							while(true){
							y++; gotoxy(x, y); printf("Jenis Hewan\t\t : "); fflush(stdin); gets(MH.jenis);
							
								if(strcmpi(MH.jenis, "Anjing")==0 || strcmpi(MH.jenis, "Kucing")==0 || strcmpi(MH.jenis, "Burung")==0){
									break;
								}else{
									y++; gotoxy(x, y); printf("[!] Jenis Hewan Hanya Boleh (Anjing / Kucing/ Burung)");
								}
							}
							
							y++; gotoxy(x, y); printf("Kelamin Hewan\t\t : "); fflush(stdin); gets(MH.kelamin);
							while(true){
								if(strcmpi(MH.kelamin, "L") == 0 || strcmpi(MH.kelamin, "P") == 0){
									if(strcmpi(MH.kelamin, "L")==0){
										strcpy(MH.kelamin, "Jantan");
									}else{
										strcpy(MH.kelamin, "Betina");
									}
									break;
								}else{
									y++; gotoxy(x, y); printf("[!] Jenis Kelamin Antara [ L / P ]");
								}
								y++; gotoxy(x, y); printf("Kelamin Hewan\t\t\t : "); fflush(stdin); gets(MH.kelamin);
							}

							do{
								y++; gotoxy(x, y); printf("Tanggal Lahir Hewan\t : "); fflush(stdin); gets(MH.tanggalLahir);

								if(strlen(MH.tanggalLahir) == 10){
									if(MH.tanggalLahir[2] == '-' && MH.tanggalLahir[5] == '-'){
									sscanf(MH.tanggalLahir, "%d-%d-%d", &hari, &bulan, &tahun);

										if((hari > 0 && hari < 32) && (bulan > 0 && bulan < 13)){
											break;
										}else if(!(hari > 0 && hari < 32)){
											y++; gotoxy(x, y); printf("[!] Format tanggal harus diantara 1 - 31");
										}else if(!(bulan > 0 && bulan < 13)){
											y++; gotoxy(x, y); printf("[!] Format bulan harus diantara 1 - 12");
										}else{
											break;
										}
									}else{
										y++; gotoxy(x, y); printf("[!] Format penanggalan yang seharusnya ");
										y++; gotoxy(x, y); printf(" Contoh : 22-10-2022");
									}
								}else{
										y++; gotoxy(x, y); printf("\t[!] Format penanggalan yang seharusnya ");
										y++; gotoxy(x, y); printf("\t Contoh : 22-10-2022");
								}

							}while(true);

							if(strcmpi(MH.jenis, "Anjing")==0){
								insertFirst(&H, alokasiHewan(MH));
							}else if(strcmpi(MH.jenis,"Burung")==0){

								if(isEmpty(H)){
									insertFirst(&H, alokasiHewan(MH));

								}else{	
									insertAfter(findAt(H), alokasiHewan(MH));	
								}
							}else{
								insertLast(&H, alokasiHewan(MH));
							}
							y+=2; gotoxy(x, y); printf("Berhasil Memasukkan Data Hewan Kucing dengan ID - %d [*]",MH.id);
							getch();
					}else if(menu=='7'){
						y = 10; x = 65;
						popupMenu(x, y, 40, 90, pos);
						
						y += 6; x += 75; gotoxy(x, y); printf("=====< HAPUS DATA HEWAN >=====");
						y += 1; x -= 5; gotoxy(x, y); printf("Masukkan ID Hewan : "); scanf("%d",&MH.id);		
						
						P = findHWN(H,MH.id);
						
						if(P == NULL){
							y += 2; gotoxy(x,y); printf("[!] DATA HEWAN TIDAK ADA!");
						}else{
							if(!isEmptyML(ML)){
								deleteAtChildModif(&ML, MH.id);
							}
							deleteAt(&H,P);
						}
						getch();
					}else if(menu=='8'){
						if(isEmpty(H)){
													
						}else{
							y = 24; x = 65;
							popupMenu(x, y, 40, 90, pos);
							x += 78; y += 5;
							tampilRiwayatJos(x, y, H);
								
						}
						getch();
					}else if(menu=='9'){
						
						y = 10; x = 65;
						y += 21;
						
						popupMenu(x, y, 40, 90, pos);
						
						y += 5; x += 79; gotoxy(x, y); printf("=====< INPUT DATA PERIKSA >=====");
						y += 2; x -= 9; gotoxy(x, y); printf("ID Dokter\t: "); scanf("%d", &DP.id);
						tempAddP = findDokter(ML,DP.id);
					
						if(tempAddP == NULL){
							y += 2; gotoxy(x,y); printf("[!] DATA DOKTER TIDAK ADA");
							getch();
						}else{
							
							y ++ ; gotoxy(x,y); printf("ID Hewan\t: ");scanf("%d",&MH.id);
							P = findHWN(H,MH.id);
							
							if(P == NULL){
								y += 2; gotoxy(x,y); printf("[!] DATA HEWAN TIDAK ADA!");
								getch();
							}else{
							index = getIndexHWN(P);	
//							printf("%d",index);
														
							rwt++;
							P->data.R[index].dkt = DP.id;	
							P->data.R[index].temp = rwt;
								
							//printf("\n\t%d",P->data.R[index].dkt);
							
								y++; gotoxy(x,y); printf("ID Riwayat\t: %d",P->data.R[index].temp);
								while(true){
									y++; gotoxy(x,y); printf("Tanggal Periksa\t: ");fflush(stdin);gets(P->data.R[index].tgl);
									if(strlen(P->data.R[index].tgl)== 10){
										if(P->data.R[index].tgl[2] == '-' && P->data.R[index].tgl[5] == '-'){
											sscanf(P->data.R[index].tgl, "%d-%d-%d", &hari, &bulan, &tahun);
	
												if((hari > 0 && hari < 32) && (bulan > 0 && bulan < 13)){
													break;
												}else if(!(hari > 0 && hari < 32)){
													y += 2; gotoxy(x,y); printf("[!] Format tanggal harus diantara 1 - 31");
												}else if(!(bulan > 0 && bulan < 13)){
													y += 2; gotoxy(x,y); printf("[!] Format bulan harus diantara 1 - 12");
												}else{
													break;
												}
											}else{
												y++; gotoxy(x,y); printf("\n\t\t[!] Format penanggalan yang seharusnya ");
												y++; gotoxy(x,y); printf("\n\t\t Contoh : 22-10-2022");
											}
										}else{
											y++; gotoxy(x,y); printf("\n\t\t[!] Format penanggalan yang seharusnya ");
											y++; gotoxy(x,y); printf("\n\t\t Contoh : 22-10-2022");
										}
									}
								strcpy(P->data.R[index].diagnosa,"-");
								
								for(i=0;i<20;i++){
									strcpy(P->data.R[index].obat[i], "-");
								}	
							}
							
						}
						getch();
					}
				}
				i = 0;
			}while(true);
			pos=0;

		}else if(mainLogin==2){
			
			pos=0;
			
			do{
				system("cls");
				creatingMainDokter(50, 5, 26, 49, pos); kursor=getch();
			
				if(kursor=='W' || kursor=='w'){
					if(pos==0){
						pos=2;
					}else{
						pos--;
					}
				}else if(kursor=='S' || kursor=='s'){
					if(pos==2){
						pos=0;
					}else{
						pos++;
					}
				}else if(kursor==13){
					menu = switchingMenuDokter(pos);
					
					if(menu=='0'){
						break;
					}else if(menu=='1'){
						y = 2; x = 50;
//						popupMenu(50, 2, 40, 90, pos);
						popupMenu(x, y, 40, 90, pos);
						
						y += 5; x += 80; gotoxy(x, y); printf("=====< MENU PERIKSA HEWAN >=====");
						
						y+=2; x -= 10; gotoxy(x, y); printf("ID Hewan: "); scanf("%d", &DP.id);
						P = findHWN(H,DP.id);
						
						if(P == NULL){
							y+=2; gotoxy(x, y); printf("DATA HEWAN TIDAK ADA!");
							break;							
						}
						
						//ubah
						printHWN(P,tempAddP);
						tempAddC = findChild(tempAddP, P->data.id);
						
						printf("\n\t\tID Riwayat: "); scanf("%d", &MH.id);
						index2 = 0;
						tempAddC = findChildR(tempAddP, MH.id);
						//batas ubah
						
						for(index = 0; index<10;index++){
							
						if(P->data.R[index].dkt == tempAddP->dataParent.id && P->data.R[index].temp == MH.id && strcmpi(P->data.R[index].diagnosa,"-")==0){
						y++; gotoxy(x, y); printf(" Diagnosa \t : ");fflush(stdin);gets(P->data.R[index].diagnosa);
						y++; gotoxy(x, y); printf(" Jumlah Obat\t : ");scanf("%d",&jml);
							for(i=0;i<jml;i++){
								y+=2; gotoxy(x, y); printf("Obat \t: ");fflush(stdin);gets(P->data.R[index].obat[i]);
								strcpy(tempAddC->dataChild.obat[i],P->data.R[index].obat[i]);
							}
							index2++;
							break;
						}
							
						}
						if(index2 == 0){
							printf("\n\t\t[!] ID Riwayat Tidak Ada! / Riwayat Sudah Terisi");	
						}else{
							strcpy(tempAddC->dataChild.diagnosa,P->data.R[index].diagnosa);
							printf("\n\t\t[*] Berhasil Input Data Periksa!");
						}
						getch();
					}else if(menu=='2'){
						y = 2; x = 50;
						
						popupMenu(x, y, 40, 90, pos);
						
						
						y += 3; x += 20;
						tampilRiwayat(tempAddP,x,y);
						
					getch();
					}
				}
			}while(true);
		}
		strcpy(nama, ""); strcpy(password, "");
	}while(true);

	

	return 0;
}
