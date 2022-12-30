#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

/*
Candra Dionisius Sihotang - 210711241
Carolus Seto Arianto - 210711186
Josua Puniwan Yahya - 210711234
William Juvent - 210711067
*/

typedef char string[100];
typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;
typedef struct node *address;

typedef struct{
	int temp;
	string diagnosa;
	string tgl;
	int dkt;
	string obat[30];
}Riwayat;

typedef struct{
    int id;
    string namaDokter;
    string namaHewan;
    string tanggalLahir;
    string jenis;
    string kelamin;
	Riwayat R[10];    
}MasterHewan;

typedef struct node{
    MasterHewan data;
    address next;
}node;

typedef struct{
    address first;
}List;

typedef struct DataChild{
    int id; // id hewan
    int r; // id riwayat
    string namaDokter;
    string namaHewan;
    string lahir;
    string jenis;
    string kelamin;
    string diagnosa;
	string tgl;
    string obat[30];
}DataChild;

typedef struct DataParent{
	int id;
    string username;
    string password;
    string nama;
    string tanggal;
}DataParent;

typedef struct Child{
	DataChild dataChild;
	AddressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	
	AddressChild firstChild;
}NodeParent;

typedef struct{
	AddressParent firstParent;
}Multilist;

// ALL VOID
void showMenu();
void showMenuAdm();

void createEmpty(Multilist *l);
void makeEmpty(List *L);
void createEmptyObat(AddressChild *ML, int index);

void insertFirstParent(Multilist *l, DataParent data);
void insertLastParent(Multilist *l, DataParent data);

void insertFirst(List *L, address newNode);
void insertLast(List *L, address newNode);
void insertAfter(address before, address newNode);

void deleteFirstParent(Multilist *l);
void deleteAtParent(Multilist *l, int idParent);
void deleteAllChild(AddressParent parent);

void deleteAtChildModif(Multilist *l, int targetHewan);

void tampilDokter(Multilist L);

// ALL OTHER FUNCTION
bool isEmptyML(Multilist l);
bool isEmpty(List L);
bool isUnikUser(Multilist l, string cari);

int findHWNDkt(List l, int id);
int searchInML(Multilist l, string target);
int searchInLL(List l, string target);

// ALL ADDRESS FUNCTION
AddressParent alokasiParent(DataParent data);
AddressChild alokasiChild(string a, string b, string c, string d, string e, int f, int g);
AddressChild findChild(AddressParent ap, int i );
AddressParent findParent(Multilist l, string target);
AddressParent findDokter(Multilist l, int i);
address findAt(List L);
address findHWN(List l, int i );
address alokasiHewan(MasterHewan D);
AddressChild findChildR(AddressParent ap, int temp);

// PATTERN

// UI LOGIN PATTERN
void printLogin(int x, int y, int column, int row);
void creatingMainLogin(int x, int y, int column, int row, int pos);
void creatingBottomLogin(int x, int y, int column, int row);
void creatingLine(int x, int y, int column, int row);
void textLogin(int x, int y, int pos);
void errorHandlingLogin(int x, int y, int column, int row);

// UI ADMIN PATTERN
void creatingMainAdmin(int x, int y, int column, int row, int pos);
void creatingAdmin(int x, int y, int column, int row, int pos);
void printAdminMenu1(int x, int y, int column, int row, int pos);
void printAdminMenu2(int x, int y, int column, int row, int pos);
void allPrintAdminMenu(int x, int y, int column, int row, int pos);

void popupMenu(int x, int y, int column, int row, int pos);


char switchingMenuAdmin(int pos);

// CONTENT MENU ADMIN
void tableDokter(int x, int y, int column, int row, int pos, Multilist L, List D);
void doubletableDokter(int x, int y, int column, int row, int pos, Multilist L, List D);
void verticalLine(int x, int y, int column, int row, int pos);

void textShowDokter(int x, int y, int column, int row, Multilist L, List D);

// UI DOKTER PATTERN
void creatingMainDokter(int x, int y, int column, int row, int pos);
void creatingDokter(int x, int y, int column, int row, int pos);
void allPrintDokterMenu(int x, int y, int column, int row, int pos);
void allPrintDataDokter(int x, int y, AddressParent P, List D, int row, int column);

void tampilRiwayatAll(int x, int y, List D);

char switchingMenuDokter(int pos);

void insertingChild(int x, int y, AddressParent P, List D, int row, int column);

// COORDINATE OPERATOR
void gotoxy(int x, int y);
void MaximizeOutputWindow();
void outInBorder(int x, int y);

// COLOR
void red();
void green();
void yellow();
void reset();


