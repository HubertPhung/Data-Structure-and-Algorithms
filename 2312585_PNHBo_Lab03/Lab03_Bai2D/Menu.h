void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu() {
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Tao danh sach sinh vien";
	cout << "\n1. Xem danh sach sinh vien ";
	cout << "\n2. QuickSort";
	cout << "\n3. HeapSort";
	cout << "\n4. MergeSort\n";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "Nhap so menu: ";
		cin >> stt;
	} while (stt <= 0 && stt > soMenu);
	return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int& n) {
	int kq;
	string filename;
	switch (menu) {
	case 0:
		cout << "\n0. Tao danh sach nhan vien\n";
		do {
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "So luong sv da doc " << n << '\n';
		break;
	case 1:
		cout << "\n1. Xem danh sach nhan vien\n ";
		Output_Arr(a, n); cout << '\n';
		break;
	case 2:
		cout << "\n2.  QuickSort\n ";
		cout << "Chua sap xep :";
		Output_Arr(a, n); cout << '\n';
		cout << "Da sap xep :\n";
		QuickSort(a, n);
		Output_Arr(a, n);
		break;
	case 3:
		cout << "\n3. HeapSort\n ";
		cout << "Chua sap xep :";
		Output_Arr(a, n); cout << '\n';
		cout << "Da sap xep :\n";
		HeapSort(a, n);
		Output_Arr(a, n);
		break;
	case 4:
		cout << "\n4. MergeSort\n ";
		cout << "Chua sap xep :";
		Output_Arr(a, n); cout << '\n';
		cout << "Da sap xep :\n";
		MergeSort(a, n);
		Output_Arr(a, n);
		break;
	}
}