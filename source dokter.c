#include "header.h"

void createEmpty(Multilist *l){
	l->firstParent = NULL;
}

bool isEmptyML(Multilist l){
	return l.firstParent == NULL;
}

bool isUnik(Multilist l,string id){
	AddressParent ap = l.firstParent;
	
	while(ap != NULL){
		if(strcmp(ap->dataParent.username,id)==0){
			return NULL;
		}
		ap=ap->next;
	}
	return id;
}

void tampilDokter(Multilist L){
    int i=0,j=0,k=1; AddressParent P = L.firstParent;
    int index;
    int count =0;
    
    printf("\n\n\t\t====< DATA DOKTER >====");
 
    while(P != NULL){
            printf("\n\n\t\t> Dokter ke-%d\n",k); k++;
            printf("\n\t\t\t> Nama Dokter\t\t : %s", P->dataParent.nama);
            printf("\n\t\t\t> Tanggal bergabung\t : %s", P->dataParent.tanggal);
            printf("\n\t\t\t> ID\t\t\t : %d\n", P->dataParent.id);
 			AddressChild temp = P->firstChild;
 			
            while(temp != NULL){
            		
				if(count == 0){
					printf("\n\n\t\t=====< Riwayat > ======");
				    printf("\n\t\t Nama Hewan : %s",temp->dataChild.namaHewan);
		            printf("\n\t\t Jenis Hewan : %s",temp->dataChild.jenis);
		            printf("\n\t\t Kelamin Hewan : %s",temp->dataChild.kelamin);
		            printf("\n\t\t Tanggal Lahir Hewan : %s",temp->dataChild.lahir);
					            
					count ++;
				}
		
				if(strcmpi(temp->dataChild.diagnosa,"-")!=0 && strcmpi(temp->dataChild.diagnosa,"")!=0){
					printf("\n\n\t\tID RIWAYAT : %d",temp->dataChild.r);
					printf("\n\t\t Tanggal Periksa \t : %s",temp->dataChild.tgl);	
					printf("\n\t\t Diagnosa \t : %s\n",temp->dataChild.diagnosa);
					printf("\n\n\t\t---< DATA OBAT >---");
						while(strcmpi(temp->dataChild.obat[j],"-")!=0){
							printf("\n\t\tObat \t : %s",temp->dataChild.obat[j]);
							j++;
						}
					j=0;
				}else{
					printf("\n\t\tBelum Melakukan Pemeriksaan!");
				}
				temp = temp->next;
			}
			count = 0;
			P = P->next;
		}  
}

void insertFirstParent(Multilist *l, DataParent data){

	AddressParent dataParent = alokasiParent(data);

	dataParent->next = l->firstParent;
	l->firstParent = dataParent;
}

void insertLastParent(Multilist *l, DataParent data){

	AddressParent dataParent = alokasiParent(data);

	if(isEmptyML(*l)){
		insertFirstParent(&(*l), data);
	}else{
	
		AddressParent temp = l->firstParent;
	
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = dataParent;
	}
}

void deleteFirstParent(Multilist *l){
	
	AddressParent temp = l->firstParent;
	
	if(!isEmptyML(*l)){
		deleteAllChild(temp);
		
		l->firstParent = l->firstParent->next;
		free(temp);
	}
}

void deleteAtParent(Multilist *l, int idParent){

	AddressParent temp = l->firstParent;
	AddressParent hapus;
	
	if(!isEmptyML(*l)){
	
		if(temp->dataParent.id == idParent){
			deleteFirstParent(&(*l));
		}else{
			while(temp->next != NULL){
			
				if(temp->next->dataParent.id == idParent){
					hapus = temp->next; 
					temp->next = temp->next->next; 
					deleteAllChild(temp);
					free(hapus);
					break;
				}
				temp = temp->next;
			}
		}
	}
}

AddressParent findParent(Multilist l, string target){
	AddressParent P = NULL;
    P = l.firstParent;

    while(P != NULL){
	    if(strcmpi(P->dataParent.username, target)==0){
	            return P;
	    }
    P = P->next;
    }
    return NULL;
}

AddressParent alokasiParent(DataParent data){

    AddressParent ap;

    ap = (AddressParent) malloc(sizeof(NodeParent));

    ap->next = NULL;
    ap->firstChild = NULL; 
    ap->dataParent = data;

    return ap;
}

AddressParent findDokter(Multilist l, int i ){
    AddressParent P = NULL;
    P = l.firstParent;

    while(P != NULL){
	    if(P->dataParent.id == i){
	        return P;
	    }
    P = P->next;
    }
    return NULL;
}

bool isUnikUser(Multilist l, string cari){
	AddressParent P = l.firstParent;
	
	while(P!=NULL){
		if(strcmpi(P->dataParent.username, cari)==0){
			return false;
		}
		P = P->next;
	}
	return true;
}


int countDokter(Multilist l){
	AddressParent P = l.firstParent; int count = 0;
	
	while(P != NULL){
		count++;
		P = P->next;
	}
	return count;
}
