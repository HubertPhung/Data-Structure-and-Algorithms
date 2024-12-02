
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, nhanVien a[MAX], int& n);

void XuatMenu() {
	cout << "\n================================Menu===============================";
	cout << "\n0. Tao danh sach nhan vien";
	cout << "\n1. Xem danh sach nhan vien \n";
	cout << "\n2. Dung thuat giai chon truc tiep sap danh sach tang dan theo ma NV.";
	cout << "\n3. Dung thuat giai chen truc tiep sap danh sach tang dan theo dia chi.";
	cout << "\n4. Dung thuat giai Radix sap danh sach tang dan theo nam sinh";
	cout << "\n===================================================================\n";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "Nhap So Menu : ";
		cin >> stt;
	} while (stt <= 0 && stt >= soMenu);
	return stt;
}

void XuLyMenu(int menu,nhanVien a[MAX], int& n) {
	int kq;
	string filename;
	switch (menu)
	{
	case 0:
		cout << "\n0. Tao danh sach nhan vien";
		do {
			cout << "\nNhap ten file can doc : ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nSo luong nhan vien da doc la: " << n << "\n";
		break;
	case 1:
		cout << "\n1. Xem danh sach nhan vien ";
		Output_Arr(a, n);
		break;
	case 2:
		cout << "\n2. Dung thuat giai chon truc tiep sap danh sach tang dan theo ma NV.";
		Selection_L(a, n);
		Output_Arr(a, n);
		break;
	case 3:
		cout << "\n3. Dung thuat giai chen truc tiep sap danh sach tang dan theo dia chi.";
		Insertion_L(a, n);
		Output_Arr(a, n);
		break;
	case 4:
		cout << "\n4. Dung thuat giai Radix sap danh sach tang dan theo nam sinh";
		Radix(a, n);
		Output_Arr(a, n);
		break;
	default:
		break;
	}
}