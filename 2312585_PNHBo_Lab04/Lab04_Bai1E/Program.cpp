#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();
int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	LIST l;
	int menu, soMenu = 11, n = 0;
	do {
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu,l);
		system("PAUSE");
	} while (soMenu > 0);
}