#include "header.h"

void makeEmpty(List *L){
	(*L).first = NULL;
}

bool isEmpty(List L){
	return L.first == NULL;
}


void printData(List H){
	address temp=H.first;
	int i,j;
	while(temp!=NULL){
		printf("\n\n\tID hewan : %d",temp->data.id);
		printf("\n\tNama Hewan : %s",temp->data.namaHewan);
		printf("\n\tTanggal Lahir Hewan : %s",temp->data.tanggalLahir);
		printf("\n\tJenis Hewan : %s",temp->data.jenis);
		printf("\n\tJenis Kelamin : %s",temp->data.kelamin);
		
		if(strcmpi(temp->data.R[0].diagnosa,"-")==0 || strcmpi(temp->data.R[0].diagnosa,"")==0){
			printf("\n\t\t[!] Belum Melakukan Pemeriksaan!");
		}else{
			printf("\n\n\t\t======< RIWAYAT PERIKSA >======\n");
		}
		
		for(i=0;i<10;i++){
			if(strcmpi(temp->data.R[i].diagnosa,"-")!=0 && strcmpi(temp->data.R[i].diagnosa,"")!=0){
				printf("\n\t\tDiagnosa : %s",temp->data.R[i].diagnosa);
				printf("\n\t\tTanggal : %s",temp->data.R[i].tgl);
				printf("\n\n\t\t---< DATA OBAT >---");
				for(j=0;j<30;j++){
					if(strcmpi(temp->data.R[i].obat[j],"-")!=0 && strcmpi(temp->data.R[i].obat[j],"")!=0){
						printf("\n\t\tObat: %s",temp->data.R[i].obat[j]);
					}else{
						break;
					}
				}
			}else{
				break;
			}
		}
		temp= temp->next;
	}
	
}

void printHWN(address ac, AddressParent ap){
	int i,j;
	
	printf("\n\n\tID hewan : %d",ac->data.id);
	printf("\n\t\tNama Hewan : %s",ac->data.namaHewan);
	printf("\n\t\tTanggal Lahir Hewan : %s",ac->data.tanggalLahir);
	printf("\n\t\tJenis Hewan : %s",ac->data.jenis);
	printf("\n\t\tJenis Kelamin : %s",ac->data.kelamin);
	
	printf("\n\t\tID Riwayat yang bisa dipilih : ");
	for(i=0;i<10;i++){
		if(strcmpi(ac->data.R[i].diagnosa,"-")==0 && ac->data.R[i].dkt == ap->dataParent.id ){
			printf("%d, ",ac->data.R[i].temp);
		}
	}
		
}

void tampilRiwayat(AddressParent P, int x, int y){
	AddressChild tem = P->firstChild;
	int count =0;
	int i=0,j=0;

		while(tem != NULL){
            	//if(strcmpi(temp->data.R[index].diagnosa,"-")==0 ||  strcmpi(temp->data.R[index].diagnosa,"")==0 ){
            	//}else{
			//ubahh
				if(tem->dataChild.id != count){
					 y += 2; gotoxy(x,y); printf("=====< Riwayat > ======");
			           	y++; gotoxy(x,y); printf("Nama Hewan : %s",tem->dataChild.namaHewan);
			           	y++; gotoxy(x,y); printf("Jenis Hewan : %s",tem->dataChild.jenis);
			           	y++; gotoxy(x,y); printf("Kelamin Hewan : %s",tem->dataChild.kelamin);
			           	y++; gotoxy(x,y); printf("Tanggal Lahir Hewan : %s",tem->dataChild.lahir);
			           	count = tem->dataChild.id;
			}
			
					
				if(strcmpi(tem->dataChild.diagnosa,"-")!=0 && strcmpi(tem->dataChild.diagnosa,"")!=0){
					y += 2; gotoxy(x,y); printf("ID RIWAYAT : %d",tem->dataChild.r);
					 	y++; gotoxy(x,y); printf("Tanggal Periksa \t : %s",tem->dataChild.tgl);	
						y++; gotoxy(x,y); printf("Diagnosa \t : %s\n",tem->dataChild.diagnosa);
						y += 2; gotoxy(x,y); printf("---< DATA OBAT >---");
						while(strcmpi(tem->dataChild.obat[j],"-")!=0){
							y++; gotoxy(x,y); printf("Obat \t : %s",tem->dataChild.obat[j]);
							j++;
						}
						j=0;
				}else{
					y += 2; gotoxy(x,y); printf("Belum Melakukan Pemeriksaan");
				}
				tem = tem->next;	 	
			//batas ubah		
		            		
//			for(i=0;i<10;i++){
//				if(temp->dataParent.id == tem->data.R[i].dkt){
//					if(strcmpi(tem->data.R[i].diagnosa,"-")!=0 && strcmpi(tem->data.R[i].diagnosa,"")!=0){
//				 	if(count == 0){
//					 	printf("\n\n\t\t=====< Riwayat > ======");
//			           	printf("\n\t\t Nama Hewan : %s",tem->data.namaHewan);
//			           	printf("\n\t\t Jenis Hewan : %s",tem->data.jenis);
//			           	printf("\n\t\t Kelamin Hewan : %s",tem->data.kelamin);
//			           	printf("\n\t\t Tanggal Lahir Hewan : %s",tem->data.tanggalLahir);
//			           	count ++;
//					}
//					
//					 	printf("\n\n\t\tID RIWAYAT : %d",tem->data.R[i].temp);
//					 	printf("\n\t\t Tanggal Periksa \t : %s",tem->data.R[i].tgl);	
//						printf("\n\t\t Diagnosa \t : %s\n",tem->data.R[i].diagnosa);
//						printf("\n\n\t\t---< DATA OBAT >---");
//						while(strcmpi(tem->data.R[i].obat[j],"-")!=0){
//							printf("\n\t\tObat \t : %s",tem->data.R[i].obat[j]);
//							j++;
//						}
//						j=0;
//					}
//				}
//			}
//			count =0;
					
				//}
		tem = tem->next;
		}		
}
		
void insertFirst(List *L, address newNode){
	
	newNode->next = (*L).first; (*L).first = newNode;	
}

void insertAfter(address before, address newNode){
	
	if(before!=NULL){
		newNode->next = before->next; before->next = newNode;
	}
}

void insertLast(List *L, address newNode){
	
	address P;
	if(isEmpty((*L))){
		insertFirst(L,newNode);
	}else{
		for(P = (*L).first; P->next != NULL; P=P->next);
		P->next = newNode;
	}
}

void deleteFirst(List *L){
	
	if(!isEmpty((*L))){
		address del = (*L).first;
		(*L).first = (*L).first->next;
		free(del);
	}
}

void deleteAt(List *L, address del){
	address P;
	
	if(!isEmpty((*L))){
		if((*L).first == del){
			deleteFirst(L);
		}else{
			P = (*L).first;
			while(P->next != del){
				P = P->next;
			}
			
			P->next = del->next;
			free(del);
		}
	}
}

address alokasiHewan(MasterHewan D){
	int i;
	address P;
	P = (node*) malloc(sizeof(node)); P->data = D;
	P->next = NULL; return P;
	for(i=0;i<10;i++){
		P->data.R[i].temp = -1;
	}	
}

address findAt(List L){
	address P = L.first;

	if(P->next == NULL){
		return P;	
	}else{
		while(P != NULL){
			if(strcmpi(P->data.jenis, "Burung") && strcmpi(P->next->data.jenis, "Anjing")!=0){
				return P;				
			}
			P = P->next;
		}
	}
}

address findHWN(List l, int i ){
    address P = l.first;
    
    while(P != NULL){
	    if(P->data.id == i){
	        return P;
	    }
    P = P->next;
    }
    return NULL;
}

int findHWNDkt(List l, int id){
    address P = l.first;
    int i;
    while(P != NULL){
    	for(i=0;i<10;i++){
		    if(P->data.R[i].dkt == id){
		        return i;
		    }	
		}
    P = P->next;
    }
    return -1;
}

int getIndexHWN(address ac){
	int i;
		for(i=0;i<10;i++){
			if(strcmpi(ac->data.R[i].diagnosa,"")==0){
				return i;
			}
		}
		return -1;
}

int findIndexHWN(address P, int id){
	int i;
	
	for(i=0;i<10;i++){
			if(P->data.R[i].temp == id){
				return i;
			}
		}
		return -1;
}

int searchInLL(List l, string target){
	int i = 0; address P = l.first;
	
	while(P != NULL){
		if(strcmpi(P->data.namaHewan, target)==0){
			i++;
		}
		P = P->next;
	}
	return i;
}

