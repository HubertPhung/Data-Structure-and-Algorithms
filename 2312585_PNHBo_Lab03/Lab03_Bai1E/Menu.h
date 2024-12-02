void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int& n);

void XuatMenu() {
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("CLS");
		XuatMenu();
		cout << "\nNhap so menu: ";
		cin >> stt;
	} while (stt <= 0 && stt > soMenu);
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n) {
	int kq;
	string filename;

	switch (menu) {
	case 1:
		cout << "\n1. Tao du lieu";
		cout << "\nNhap filename: "; cin >> filename;
		File_Array("test1.txt", a, n);
		XuatMang(a, n);
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		if (n == 0) cout << "\nKo co du lieu de xuat";
		XuatMang(a, n);
		break;
	case 3:
		cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
		ChonTrucTiepGTNN(a, n);
		XuatMang(a, n);

		break;
	case 4:
		cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		ChonTrucTiepGTLL(a, n);
		XuatMang(a, n);
		break;
	case 5:
		cout << "\n5. Thuat giai Chon hai dau";
		Chon2Dau(a, n);
		XuatMang(a, n);
		break;
	case 6:
		cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
		ChenTrucTiep(a, n);
		XuatMang(a, n);
		break;
	case 7:
		cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
		ChenTrucTiepBP(a, n);
		XuatMang(a, n);
		break;
	case 8:
		cout << "\n8. Thuat giai Chen nhi phan";
		binaryInsertionSort(a, n);
		XuatMang(a, n);
		break;
	case 9:
		cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
		InterchangeSort_MinToFront(a, n);
		XuatMang(a, n);
		break;
	case 10:
		cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		InterchangeSort_MaxToEnd(a, n);
		XuatMang(a, n);
		break;
	case 11:
		cout << "\n11. Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
		BubbleSort_MinToStart(a, n);
		XuatMang(a, n);
		break;
	case 12:
		cout << "\n12. Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
		BubbleSort_MaxToEnd(a, n);
		XuatMang(a, n);
		break;
	default :
		return ;
	}
}