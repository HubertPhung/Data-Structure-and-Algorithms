﻿#include <iostream>
#include <fstream> //doc tap tin
#include<iomanip>
#include<string.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	sinhvien a[MAX];
	int soMenu = 9,
		menu,
		n = 0; //so luong sinh vien trong danh sach
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}
