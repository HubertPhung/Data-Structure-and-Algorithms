#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main() {
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh() {
	nhanVien a[MAX];
	int soMenu = 5, menu;
	int n = 0;
	do {
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu >= 0);
}
