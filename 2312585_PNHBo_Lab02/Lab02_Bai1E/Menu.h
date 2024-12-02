// khai bao nguyen mau
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, nhanvien a[MAX], int& n);

void XuatMenu() {
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Tao danh sach nhan vien";
	cout << "\n1. Xem danh sach nhan vien ";
	cout << "\n2. Tim kiem theo ho, ten: Xuat tat ca cac nhan vien trung ho va ten cho truoc";
	cout << "\n3. Tim kiem theo nam sinh: Xuat tat ca cac nhan vien cung nam sinh";
	cout << "\n4. Tim kiem theo ho, ten va nam sinh: Xuat tat ca cac nhan vien trung ho, ten cho truoc va nam sinh < x";
	cout << "\n5. Tim kiem theo ten va dia chi: Xuat tat ca cac ten nhan vien cung ten va dia chi cho truoc";
	cout << "\n6. Tim kiem theo nam sinh va luong: Xuat tat ca cac nhan vien co muc luong >= x va co nam sinh <= y";
	cout << "\n7. Tim kiem nhi phan theo ma nhan vien khi cho truoc ma nhan vien (can phai kiem tra tinh don dieu cua du lieu)\n";
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

void XuLyMenu(int menu, nhanvien a[MAX], int& n) {
	int kq, nam;
	double luong;
	string filename;
	string ho, ten, diaChi, maNV;

	switch (menu) {
	case 0:
		cout << "\n0. Tao danh sach nhan vien\n";
		do {
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << "so luon nv da doc " << n;
		break;
	case 1:
		cout << "\n1. Xem danh sach nhan vien ";
		Xuat_DSNV(a, n);
		break;
	case 2:
		cout << "\n2. Tim kiem theo ho, ten: Xuat tat ca cac nhan vien trung ho va ten cho truoc";
		Xuat_DSNV(a, n);
		cout << "\nNhap ho:";
		cin >> ho;
		cout << "\nNhap ten:";
		cin >> ten;
		Tim_TheoHoTen(ho, ten, a, n);
		break;
	case 3:
		cout << "\n3. Tim kiem theo nam sinh: Xuat tat ca cac nhan vien cung nam sinh";
		Xuat_DSNV(a, n);
		cout << "\nNhap nam: "; cin >> nam;
		Tim_TheoNamSinh(nam, a, n);
		break;
	case 4:
		cout << "\n4. Tim kiem theo ho, ten va nam sinh: Xuat tat ca cac nhan vien trung ho, ten cho truoc va nam sinh < x";
		Xuat_DSNV(a, n);
		cout << "\nNhap ho:";
		cin >> ho;
		cout << "\nNhap ten:";
		cin >> ten;
		cout << "\nNhap nam: "; cin >> nam;
		Tim_TheoHoTenNamSinh(ho, ten, nam, a, n);
		break;
	case 5:
		cout << "\n5. Tim kiem theo ten va dia chi: Xuat tat ca cac ten nhan vien cung ten va dia chi cho truoc";
		Xuat_DSNV(a, n);
		cout << "\nNhap ten: "; cin >> ten;
		cout << "\nNhap diaChi: "; cin >> diaChi;
		Tim_TheoTenVaDiaChi(ten, diaChi, a, n);
		break;
	case 6:
		cout << "\n6. Tim kiem theo nam sinh va luong: Xuat tat ca cac nhan vien co muc luong >= x va co nam sinh <= y";
		Xuat_DSNV(a, n);
		cout << "\nNhap nam: "; cin >> nam;
		cout << "\nNhap luong"; cin >> luong;
		Tim_TheoLuongVaNamSinh(luong, nam, a, n);
		break;
	case 7:
		cout << "\n7. Tim kiem nhi phan theo ma nhan vien khi cho truoc ma nhan vien (can phai kiem tra tinh don dieu cua du lieu)\n";
		Xuat_DSNV(a, n);
		cout << "\nNhap maNV: "; cin >> maNV;
		if (TimKiemNhiPhan(a, n, maNV) == -1) cout << "\nKo tim thay nhan vien co maNV";
		else Xuat_NV(a[TimKiemNhiPhan(a, n, maNV)]);
		break;
	}
}