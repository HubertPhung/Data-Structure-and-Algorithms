#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	int soMenu = 11,
		menu,
		n = 0;
	sinhVien a[MAX];
	do {
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");

	} while (menu > 0);
}