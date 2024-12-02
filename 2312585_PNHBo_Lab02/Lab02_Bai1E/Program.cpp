#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<iomanip>

using namespace std;
#include "thuvien.h"
#include "menu.h"



void ChayChuongTrinh();

int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	nhanvien a[MAX];
	int soMenu = 7, menu;
	int n = 0;
	do {
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu >= 0);

}