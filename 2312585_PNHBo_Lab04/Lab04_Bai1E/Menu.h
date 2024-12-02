

void XuatMenu() {
		cout << "\n0. Thoat khoi chuong trinh";
		cout << "\n1. Tao danh sach";
		cout << "\n2. Xem danh sach";
		cout << "\n3. Tinh gia tri nho nhat cua danh sach";
		cout << "\n4. Tinh gia tri lon nhat cua danh sach";
		cout << "\n5. Dem gia tri x xuat hien bao nhieu lan trong danh sach";
		cout << "\n6. Tinh tong cac gia tri trong danh sach";
		cout << "\n7. Tinh tong cac gia tri khac nhau trong danh sach";
		cout << "\n8. Xuat cac gia tri khac nhau trong danh sach va so lan xuat hien tuong ung";
		cout << "\n9. Sap danh sach tang dan bang thuat giai chen truc tiep";
		cout << "\n10. Sap danh sach theo yeu cau :";
		cout << "\n	\t Gia tri 0 xuat hien tai cac nut dau danh sach";
		cout << "\n	\t Tiep theo la cac nut co gia tri am giam dan";
		cout << "\n	\t Cuoi cung la cac nut co gia tri duong tang dan";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "\nNhap So menu : ";
		cin >> stt;
	} while (stt <= 0 && soMenu >= stt);
	return stt;
}

void XuLyMenu(int menu,LIST &l) {
	Data x;
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 1:
		cout << "\n1. Tao danh sach";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = File_List(filename, l);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem danh sach";
		XuatDS(l);
		break;
	case 3:
		cout << "\n3. Tinh gia tri nho nhat cua danh sach";
		cout <<"\Gia tri nho nhat : " << TimGTNN(l);
		break;
	case 4:
		cout << "\n4. Tinh gia tri lon nhat cua danh sach";
		cout << "\Gia tri lon nhat : " << TimGTNN(l);
		break;
	default:
		break;
	}
}