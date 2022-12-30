#include "header.h"

bool haveChild(AddressParent ap){
	return ap->firstChild != NULL;
}

void insertFirstChild(Multilist l, int target, AddressChild ac){

	AddressParent parent = findDokter(l, target);
	
	if(parent != NULL){
		ac->next = parent->firstChild;
		parent->firstChild = ac;
	}
}

//void deleteFirstChild(AddressParent ap){
//	
//
//		
//	if(haveChild(parent)){
//			
//		AddressChild temp = parent->firstChild;
//		parent->firstChild = parent->firstChild->next;
//			
//		free(temp);
//	}
//
//}

void deleteAtChildModif(Multilist *l, int targetHewan){
	AddressParent P = (*l).firstParent;
	AddressChild C = NULL, Ctarget = NULL;
	
	while(P != NULL){
		if(haveChild(P)){
			Ctarget = findChild(P,targetHewan);
			if(P->firstChild->dataChild.id == targetHewan){
				Ctarget = P->firstChild;
				P->firstChild = P->firstChild->next;
				free(Ctarget);	
			}else{
				C = P->firstChild;
				while(C->next != NULL && C->dataChild.id != targetHewan){
					C = C->next;
				}
				C->next = Ctarget->next;
				free(Ctarget);			
			}
			
			printf("\n\tdisini");	
		}
		if(findChild(P,targetHewan) != NULL){
			
		}
		else P = P->next;
	}
}

void deleteAllChild(AddressParent parent){
	
	AddressChild temp;
	
	while(haveChild(parent)){
		
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		
		free(temp);
	}
}

AddressChild alokasiChild(string a, string b, string c, string d, string e, int f, int g){
	AddressChild ac;
	int i;
	ac = (AddressChild) malloc(sizeof(NodeChild));
	
	ac->next = NULL; 
	strcpy(ac->dataChild.namaHewan,a);
	strcpy(ac->dataChild.jenis,b);
	strcpy(ac->dataChild.kelamin,c);
	strcpy(ac->dataChild.lahir,d);
	strcpy(ac->dataChild.tgl,e);
	ac->dataChild.id = f;
	ac->dataChild.r = g;
	strcpy(ac->dataChild.diagnosa,"-");
	for(i=1;i<30;i++){
		strcpy(ac->dataChild.obat[i],"-");
	}
	return ac;
}

AddressChild findChildR(AddressParent ap, int temp){
	int i;
	AddressChild ac = ap->firstChild;
	while(ac != NULL){
		for(i=0;i<10;i++){
			if(ac->dataChild.r != temp){
				return ac;
			}	
		}	
	ac= ac->next;
	}
	return NULL;
}

void deleteDkt(List D, AddressParent temp){
	address tem = D.first;
	int i;
	while(tem!=NULL){
		for(i=0;i<10;i++){
			if(tem->data.R[i].dkt == temp->dataParent.id){
				strcpy(tem->data.R[i].diagnosa,"-");
				tem->data.R[i].dkt = -1;	
			}
		}
		
		tem = tem->next;
	}
}

int findRiwayat(AddressChild ac, int temp){
	int i;
		for(i=0;i<10;i++){
			if(ac->dataChild.r == temp){
				return i;
			}
		}
	return -1;
}

AddressChild findChild(AddressParent ap, int i ){
	AddressChild ac= ap->firstChild;
	
		while(ac != NULL){
			 if(ac->dataChild.id == i){
	        	return ac;
	    	}
	    	ac= ac->next;
		}	
    return NULL;
}

int getIndex(AddressChild ac){
	int i;
		for(i=0;i<10;i++){
			if(strcmpi(ac->dataChild.diagnosa,"")==0){
				return i;
			}
		}
		return -1;
}

int searchInML(Multilist l, string target){
	int i = 0; AddressParent P = NULL; AddressChild C = NULL;
	
	while(P != NULL){
		C = P->firstChild;
		
		while(C != NULL){
			if(strcmpi(C->dataChild.namaHewan, target)==0){
				i++;
			}
			C = C->next;
		}
		P = P->next;
	}
	return i;
}

