#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();


int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	int menu,
		soMenu = 8;
	LIST l;
	do {
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu > 0);
}