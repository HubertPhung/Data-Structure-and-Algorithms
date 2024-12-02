
void XuatMenu() {
		cout << "\n0. Thoat chuong trinh.";
		cout << "\n1. Tao danh sach sinh vien tu file.";
		cout << "\n2. Xem danh sach sinh vien.";
		cout << "\n3. Tim kiem tuyen tinh : xuat tat ca cac sinh vien trung ho, ten cho truoc va co nam sinh < x.";
		cout << "\n4. Tim kiem tuyen tinh linh canh : tra ve chi so dau tien sinh vien co ten cho truoc.";
		cout << "\n5. Dung thuat giai chon truc tiep sap danh sach tang dan theo nam sinh.";
		cout << "\n6. Dung thuat giai Quick sort sap danh sach giam dan theo diem trung binh.";
		cout << "\n7. Tim kiem nhi phan : tra ve chi so cuoi cung sinh vien co nam sinh cho truoc.";
		cout << "\n8. Tim kiem nhi phan : tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc.";
		cout << "\n9. Dung thuat giai Radix sort sap danh sach giam dan theo ten sinh vien.";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "\nNhap So Menu : ";
		cin >> stt;
	} while (stt <= 0 && stt >= soMenu);
	return stt;
}

void XuLyMenu(int menu, sinhVien a[MAX], int &n) {
	char filename[MAX];
	int kq;
	char ho[10];
	char ten[10];
	int x;
	switch (menu)
	{
	case 1:
		cout << "\n1. Tao danh sach sinh vien tu file.";
		do {
			cout << "\nNhap ten file : ";
			cin >> filename;
			kq = DocFile(filename, a, n);
		} while (!kq);
		break;
	case 2:
		cout << "\n2. Xem danh sach sinh vien.";
		XuatDSSV(a, n);
		break;
	case 3:
		cout << "\n3. Tim kiem tuyen tinh : xuat tat ca cac sinh vien trung ho, ten cho truoc va co nam sinh < x.";
		XuatDSSV(a, n);
		cout << "\nNhap ho : ";
		cin >> ho;
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap nam sinh x :";
		cin >> x;
		TKTT_TheoHoTenNamSinh(ho, ten, x, a, n);
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh linh canh : tra ve chi so dau tien sinh vien co ten cho truoc.";
		XuatDSSV(a, n);
		cout << "\nNhap ten : ";
		cin >> ten;
		cout <<"Tra ve chi so dau tien : " << TKTT_TenSV_DauTien(a, n, ten);
		break;
	case 5:
		cout << "\n5. Dung thuat giai chon truc tiep sap danh sach tang dan theo nam sinh.";
		Selection_TangNamSinh(a, n);
		XuatDSSV(a, n);
		break;
	case 6:
		cout << "\n6. Dung thuat giai Quick sort sap danh sach giam dan theo diem trung binh.";
		Quicksort(a, n);
		XuatDSSV(a, n);
		break;
	case 7:

	default:
		break;
	}
}