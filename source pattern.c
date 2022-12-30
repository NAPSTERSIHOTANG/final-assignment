#include "header.h"

// COORDINATE OPERATOR
void gotoxy(int x, int y){
	COORD pos;
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MaximizeOutputWindow(){
    HWND consoleWindow = GetConsoleWindow(); 		// This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); 		// This mimics clicking on its' maximize button
}

void outInBorder(int x, int y){
	gotoxy(x, y); printf(" ");
}

// PATTERN OPERATOR

// LOGIN PATTERN
void printLogin(int x, int y, int column, int row){
	int i, j;
	
	gotoxy(x, y);
	//printf("\n\n\n\t\t\t");
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);					// Top Left Upper Corner
			}else if(i==column && j==1){
				printf("%c", 200);					// Top Left Bottom Corner
			}else if(i==1 && j==row){
				printf("%c", 187);					// Top Right Upper Corner
			}else if(i==column && j==row){
				printf("%c", 188);					// Top Right Bottom Corner
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);					// Left Bar
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);					// Bottom and Upper Bar
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);					// Right Bar
			}else{
				printf(" ");
			}
		}
		//printf("\n\t\t\t");
		gotoxy(x, y+i);
	}
}

void creatingBottomLogin(int x, int y, int column, int row){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 204);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 185);						// Top Right Upper Corner
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}
}

void creatingLine(int x, int y, int column, int row){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 204);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 185);						// Top Right Upper Corner
			}else if(i==1 && (j>1 && j<row)){
				printf("%c", 205);
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}	
}

void creatingMainLogin(int x, int y, int column, int row, int pos){
	green();
	printLogin(x, y, column, row);
	printLogin(x, y+5, column+4, row);
	creatingLine(x, y+5, column-(column-1), row);
	creatingBottomLogin(x, y+15, column-5, row);
	
	textLogin(x, y, pos);
}

void textLogin(int x, int y, int pos){
	gotoxy(x+20, y+2); printf("MENU LOGIN");	
	gotoxy(x+8, y+8); printf("Username\t : ");
	gotoxy(x+8, y+12); printf("Password\t : ");
	
	if(pos!=2){
		gotoxy(x+1, y+17); printf("[!] Press enter in this box to submit your data");
	}else{
		gotoxy(x+8, y+17); printf("Ready to submit your data");
	}

	if(pos==0){
		gotoxy(x+4, y+8); printf("--> "); 							// Username Arrow Indicator
	}else if(pos==1){
		gotoxy(x+4, y+12); printf("--> ");							// Password Arrow Indicator
	}else if(pos==2){
		gotoxy(x+4, y+17); printf("--> ");							// Bottom Arrow Indicator
	}

	gotoxy(x, y+22); printf("[!] Press enter to write in each sessions");
}

void errorHandlingLogin(int x, int y, int column, int row){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 204);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 185);						// Top Right Upper Corner
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);	
	}
}

// ADMIN MENU
void creatingMainAdmin(int x, int y, int column, int row, int pos){
	creatingAdmin(x, y, column, row, pos);
	
	creatingLine(x, y+5, column-(column-1), row);
	
	x+=5; column-=(column-5); row-=(row-39);
	
	creatingAdmin(x, y+7, column, row, pos);
	creatingAdmin(x, y+14, column, row, pos);
	creatingAdmin(x, y+21, column, row, pos);
	creatingAdmin(x, y+28, column, row, pos);
	creatingAdmin(x, y+35, column, row, pos);
}

void printAdminMenu1(int x, int y, int column, int row, int pos){
	gotoxy(x+15, y+2); printf("-=< Menu Dokter >=-");
	//gotoxy(x+16, y+2); printf("-=< Menu Hewan >=-");
	
	x+=15;
	
	gotoxy(x, y+9); printf("Tambah Data Dokter");
	gotoxy(x, y+16); printf("Tampil Data Dokter");
	gotoxy(x+1, y+23); printf("Cari Data Dokter");
	gotoxy(x+1, y+30); printf("Ubah Data Dokter");
	gotoxy(x, y+37); printf("Hapus Data Dokter");
	
}

void printAdminMenu2(int x, int y, int column, int row, int pos){
	x+=60;
	gotoxy(x+15, y+2); printf("-=< Menu Hewan >=-");
	
	x+=15;
	
	gotoxy(x-3, y+9); printf("Pendaftaran Periksa Hewan");
	gotoxy(x+2, y+16); printf("Hapus Data Hewan");
	gotoxy(x+1, y+23); printf("Tampil Data Hewan");
	gotoxy(x+1, y+30); printf("Input Data Periksa");
	gotoxy(x+7, y+37); printf("Keluar");
	
}

void allPrintAdminMenu(int x, int y, int column, int row, int pos){
	printAdminMenu1(x, y, column, row, pos);
	printAdminMenu2(x, y, column, row, pos);
	
	if(pos==0){
		gotoxy(x+1, y+9); printf(" >>");
		gotoxy(x+45, y+9); printf("<< ");
	}else if(pos==1){
		gotoxy(x+1, y+16); printf(" >>");
		gotoxy(x+45, y+16); printf("<< ");
	}else if(pos==2){
		gotoxy(x+1, y+23); printf(" >>");
		gotoxy(x+45, y+23); printf("<< ");
	}else if(pos==3){
		gotoxy(x+1, y+30); printf(" >>");
		gotoxy(x+45, y+30); printf("<< ");		
	}else if(pos==4){
		gotoxy(x+1, y+37); printf(" >>");
		gotoxy(x+45, y+37); printf("<< ");
	}else if(pos==5){
		gotoxy(x+61, y+9); printf(" >>");
		gotoxy(x+61+44, y+9); printf("<< ");
	}else if(pos==6){
		gotoxy(x+61, y+16); printf(" >>");
		gotoxy(x+61+44, y+16); printf("<< ");
	}else if(pos==7){
		gotoxy(x+61, y+23); printf(" >>");
		gotoxy(x+61+44, y+23); printf("<< ");		
	}else if(pos==8){
		gotoxy(x+61, y+30); printf(" >>");
		gotoxy(x+61+44, y+30); printf("<< ");		
	}else if(pos==9){
		gotoxy(x+61, y+37); printf(" >>");
		gotoxy(x+61+44, y+37); printf("<< ");
	}
}

void creatingAdmin(int x, int y, int column, int row, int pos){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 187);						// Top Right Upper Corner
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}
}

void popupMenu(int x, int y, int column, int row, int pos){
	int i, j;
	
	x+=52; y+=3;
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 187);						// Top Right Upper Corner
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}	
}

char switchingMenuAdmin(int pos){
	if(pos==0){
		return '1';
	}else if(pos==1){
		return '2';
	}else if(pos==2){
		return '3';
	}else if(pos==3){
		return '4';
	}else if(pos==4){
		return '5';
	}else if(pos==5){
		return '6';
	}else if(pos==6){
		return '7';
	}else if(pos==7){
		return '8';
	}else if(pos==8){
		return '9';
	}else if(pos==9){
		return '0';
	}
}

// IN ADMIN MENU

void tableDokter(int x, int y, int column, int row, int pos, Multilist L, List D){
	int i, j, limit = countDokter(L); AddressParent P = L.firstParent;
	column = limit + 5;
	
	y+=15; x+=52;
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 187);						// Top Right Upper Corner
			}else if(i==3 && (j>1 && j<row)){
				printf("%c", 205);						// Horizontal Line
			}else if(i==3 && j==1){
				printf("%c", 204);//185					// Rebuild Horizontal Line Corner Left
			}else if(i==3 && j==row){
				printf("%c", 185);						// Rebuild Horizontal Line Corner Right
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
			
		}
		gotoxy(x, y+i);
	}
	verticalLine(x+28, y, column, 1, pos);
	verticalLine(x+62, y, column, 1, pos);
	verticalLine(x+93, y, column, 1, pos);
	
	y+=1;
	gotoxy(x+2, y); printf("Dokter ke");
	gotoxy(x+30, y); printf("Nama Dokter");
	gotoxy(x+64, y); printf("Tanggal bergabung");
	gotoxy(x+95, y); printf("ID");
	
	if(P!=NULL){
		textShowDokter(x, y, column, row, L, D);	
	}
}

void textShowDokter(int x, int y, int column, int row, Multilist L, List D){
    int i=0,j=0,k=0; AddressParent P = L.firstParent;
    AddressChild ac = P->firstChild;
    address temp = D.first;
    
    while(P != NULL){
            gotoxy(x+3, y+2); printf("> Dokter ke-%d", k); k++;
            gotoxy(x+30, y+2); printf("> : %s", P->dataParent.nama);
            gotoxy(x+65, y+2); printf("> : %s", P->dataParent.tanggal);
            gotoxy(x+96, y+2); printf("> : %d\n", P->dataParent.id);
 
        P = P->next;
		
        y+=1;
    }
}

void verticalLine(int x, int y, int column, int row, int pos){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 203);
			}else if(i==column && j==row){
				printf("%c", 202);
			}else if(i==3){
				printf("%c", 206);
			}else{
				printf("%c", 186);
			}
		}
		gotoxy(x, y+i);
	}	
}

void doubletableDokter(int x, int y, int column, int row, int pos, Multilist L, List D){
	int i, j;
	
	y+=15; x+=52;
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 187);						// Top Right Upper Corner
			}else if(i==3 && (j>1 && j<row)){
				printf("%c", 205);						// Horizontal Line Top
			}else if(i==5 && (j>1 && j<row)){
				printf("%c", 205);						// Second Horizontal Line
			}else if(i==3 && j==1){	
				printf("%c", 204);//185					// Rebuild Horizontal Line Corner Left
			}else if((j==(row/2) && i==1)){
				printf("%c", 205);						// Mini Vertical Line In The Middle
			}else if(i==3 && j==row){
				printf("%c", 185);						// Rebuild Horizontal Line Corner Right
			}else if(i==5 && j==1){
				printf("%c", 204);						// Second Rebuild Horizontal
			}else if(i==5 && j==row){
				printf("%c", 185);						// Second Rebuild Horizontal
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else if(j==(row/2) && i<5 && i>2){
				printf("%c", 186);						// Mini Vertical Line In The Middle						
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}
	row -= 115; column -= 15;
	
	x -= 52;
	popupMenu(x+2, y+2, column+2, row+20, pos); popupMenu(x+28, y+2, column+2, row+20, pos); popupMenu(x+54, y+2, column+2, row+20, pos);
	
	y -= 4;
	popupMenu(x+2, y+9, column+2, row+20, pos); popupMenu(x+28, y+9, column+2, row+20, pos); popupMenu(x+54, y+9, column+2, row+20, pos);
	
	y += 4;
	popupMenu(x+80, y+2, column+9, row+34, pos);
}

void tampilRiwayatJos(AddressParent P , int x, int y){
	int count =0;
	int i=0,j=0;

	AddressChild temp = P->firstChild;
 			
        while(temp != NULL){
			if(temp->dataChild.id != count){
				gotoxy(x,y); printf("=====< Riwayat > ======");
			    y++; gotoxy(x,y); printf("Nama Hewan : %s",temp->dataChild.namaHewan);
		        y++; gotoxy(x,y); printf("Jenis Hewan : %s",temp->dataChild.jenis);
		    	y++; gotoxy(x,y); printf("Kelamin Hewan : %s",temp->dataChild.kelamin);
		        y++; gotoxy(x,y); printf("Tanggal Lahir Hewan : %s",temp->dataChild.lahir);
					     
            count = temp->dataChild.id;
			}
		
			if(strcmpi(temp->dataChild.diagnosa,"-")!=0 && strcmpi(temp->dataChild.diagnosa,"")!=0){
				y += 2; gotoxy(x,y); printf("ID RIWAYAT : %d",temp->dataChild.r);
				y++; gotoxy(x,y); printf("Tanggal Periksa \t : %s",temp->dataChild.tgl);	
				y++; gotoxy(x,y); printf("Diagnosa \t : %s\n",temp->dataChild.diagnosa);
				y += 2; gotoxy(x,y); printf("---< DATA OBAT >---");
					while(strcmpi(temp->dataChild.obat[j],"-")!=0){
						y++; gotoxy(x,y); printf("Obat \t : %s",temp->dataChild.obat[j]);
						j++;
					}
					j=0;
				}else{
					y += 2; gotoxy(x,y); printf("Belum Melakukan Pemeriksaan!");
				}
				temp = temp->next;
		}
}

// DOKTER MENU
void creatingMainDokter(int x, int y, int column, int row, int pos){
	creatingDokter(x, y, column, row, pos);
	creatingLine(x, y+5, column-(column-1), row);

	creatingDokter(x+5, y+7, column-(column-5), row-10, pos);
	creatingDokter(x+5, y+13, column-(column-5), row-10, pos);
	creatingDokter(x+5, y+19, column-(column-5), row-10, pos);
	
	allPrintDokterMenu(x, y, column, row, pos);
}

void creatingDokter(int x, int y, int column, int row, int pos){
	int i, j;
	
	gotoxy(x, y);
	
	for(i=1; i<=column; i++){
		for(j=1; j<=row; j++){
			if(i==1 && j==1){
				printf("%c", 201);						// Top Left Upper Corner
			}else if(i==1 && j==row){
				printf("%c", 187);						// Top Right Upper Corner
			}else if(j==row && i!=1 && i!=column){
				printf("%c", 186);						// Right Bar
			}else if(j==1 && i!=1 && i!=column){
				printf("%c", 186);						// Left Bar
			}else if(i==column && j==row){
				printf("%c", 188);						// Top Left Bottom Corner
			}else if(i==column && j==1){
				printf("%c", 200);						// Top Left Bottom Corner
			}else if((i==1 || i==column) && j!=row){
				printf("%c", 205);						// Bottom and Upper Bar
			}else{
				printf(" ");
			}
		}
		gotoxy(x, y+i);
	}
}

void allPrintDokterMenu(int x, int y, int column, int row, int pos){
	gotoxy(x+15, y+2); printf("-=< Menu Dokter >=-");
	
	x+=18;
	gotoxy(x, y+9); printf("Periksa Hewan");
	gotoxy(x-1, y+15); printf("Lihat Riwayat");
	gotoxy(x+3, y+21); printf("Keluar");
	
	if(pos==0){
		gotoxy(x-16, y+9); printf(">>");
		gotoxy(x+27, y+9); printf("<< ");
	}else if(pos==1){
		gotoxy(x-16, y+15); printf(">>");
		gotoxy(x+27, y+15); printf("<< ");
	}else if(pos==2){
		gotoxy(x-16, y+21); printf(">>");
		gotoxy(x+27, y+21); printf("<< ");		
	}
}

char switchingMenuDokter(int pos){
	if(pos==0){
		return '1';
	}else if(pos==1){
		return '2';
	}else if(pos==2){
		return '0';
	}
}

void insertingChild(int x, int y, AddressParent P, List D, int row, int column){
	
}

// COLOUR
void red(){
	system("COLOR 04");
}

void green(){
	system("COLOR 02");
}

void yellow(){
	system("COLOR 06");
}

void reset(){
	system("COLOR 07");
}

