
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);
void ChayChuongTrinh();

void XuatMenu() {
	cout << "\n1. Doc File";
	cout << "\n2. Xuat Danh Sach";
	cout << "\n3. Tim kiem theo maNV";
	cout << "\n4. Tim kiem theo ho";
	cout << "\n5. Tim kiem theo tenLot";
	cout << "\n6. Tim kiem theo ten";
	cout << "\n7. Tim kiem theo nam sinh";
	cout << "\n8. Tim kiem theo dtb";
	cout << "\n4. Tim kiem theo lop";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "\nNhap So Menu :";
		cin >> stt;
	} while (stt <= 0 && stt >= soMenu);
	return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int &n) {
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 1:
		system("CLS");
		do {
			cout << "\nNhap file : ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		break;
	case 2:
		Xuat_DSSV(a, n);
		break;
	default:
		break;
	}
}

void ChayChuongTrinh() {
	int soMenu=10,
		menu,
		n = 0;
	sinhvien a[MAX];
	do {
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}
