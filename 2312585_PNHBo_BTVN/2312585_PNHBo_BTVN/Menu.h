

void XuatMenu() {
	cout << "\n===============================Chon Chuc Nang=================================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Dem so luong nhan vien co he so luong >=3.4";
	cout << "\n4. Tim kiem tuyen tinh: theo ten nhan vien, tra ve node cuoi cung";
	cout << "\n5. Chen 1 nhan vien sau nhan vien co ma nhan vien = x (x nhap tu ban phim)";
	cout << "\n6. Xoa tat ca nhan vien theo ten";
	cout << "\n7. Dung thuat giai chon truc tiep sap tang dan theo nam sinh";
	cout << "\n==============================================================================";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "\nNhap so menu : ";
		cin >> stt;
	} while (stt <= 0 && stt >= soMenu);
	return stt;
}

void XuLyMenu(int menu, LIST& l) {
	Data x;
	NODE* nvmoi;
	int kq;
	string filename = "data.txt";
	string ten;
	char manv[8];
	switch (menu)
	{
	case 1:
		cout << "\n1. Nhap danh sach nhan vien tu file";
		Doc_File(filename, l);
		break;
	case 2:
		cout << "\n2. Xuat danh sach nhan vien";
		Xuat_DSNV(l);
		break;
	case 3:
		cout << "\n3. Dem so luong nhan vien co he so luong >=3.4";
		Xuat_DSNV(l);
		cout << "\nSo luong nhan vien co he so luong >=3.4 : ";
		cout << DemSoLuongNV(l) << endl;
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh: theo ten nhan vien, tra ve node cuoi cung";
		Xuat_DSNV(l);
		cout << "Nhap ten : ";
		cin >> ten;
		Xuat_NV(TimKiemTen(l, ten)->info);
		break;
	case 5:
		cout << "\n5. Chen 1 nhan vien sau nhan vien co ma nhan vien = x (x nhap tu ban phim)";
		Xuat_DSNV(l);
		nvmoi = Nhap1NV();
		cout << "\nNhap ma nhan vien can chen sau : ";
		cin >> manv;
		/*ChenNVTheoMa(l, manv, nvmoi);
		Xuat_DSNV(l);*/
		break;
	case 6:
		cout << "\n6. Xoa tat ca nhan vien theo ten";
		Xuat_DSNV(l);
		cout << "\nNhap ten can xoa : ";
		cin >> ten;
		XoaALLNV_Ten(l, ten);
		Xuat_DSNV(l);
		break;
	case 7:
		cout << "\n7. Dung thuat giai chon truc tiep sap tang dan theo nam sinh";
		Xuat_DSNV(l);
		SapXepTangDan_TheoNamSinh(l);
		Xuat_DSNV(l);
		break;
	default:
		break;
	}
}

void ChayChuongTrinh() {
	LIST l;
	int menu,
		soMenu = 7,
		n = 0;

	do {
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu > 0);
}

