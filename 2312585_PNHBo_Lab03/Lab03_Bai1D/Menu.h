
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu() {
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu ";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Chon truc tiep (Selection Straight sort)";
	cout << "\n4. Chen truc tiep (Insertion Straight sort)";
	cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n6. Noi bot (Bubble sort)";
	cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
	cout << "\n8. Radix\n";
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

void XuLyMenu(int menu, int a[MAX], int& n) {
	int kq;
	string filename;
	string chon;
	switch (menu) {
	case 1:
		cout << "\n1. Tao du lieu\n";
		do {
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		break;
	case 2:
		cout << "\n2. Xem du lieu \n";
		Output(a, n); cout << '\n';
	case 3:
		cout << "\n3. Chon truc tiep (Selection Straight sort)";
		Selection_L(a, n); cout << '\n';
		break;
	case 4:
		cout << "\n4. Chen truc tiep (Insertion Straight sort)";
		Insertion_L(a, n); cout << '\n';
		break;
	case 5:
		cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
		Interchange_L(a, n); cout << '\n';
		break;
	case 6:
		cout << "\n6. Noi bot (Bubble sort)";
		Buble_L(a, n); cout << '\n';
		break;
	case 7:
		cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
		Binary_Insertion(a, n); cout << '\n';
		break;
	case 8:
		cout << "\n8. Radix";
		Binary_Insertion(a, n); cout << '\n';
		break;
	default:
		cout << "Thoat khoi chuong trinh";
		break;
	}
}

