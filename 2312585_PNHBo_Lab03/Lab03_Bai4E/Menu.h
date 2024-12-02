
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, nhanVien a[MAX], int& n);

void XuatMenu() {
	cout << "\n================================Menu===============================";
	cout << "\n0. Tao danh sach nhan vien";
	cout << "\n1. Xem danh sach nhan vien \n";
	cout << "\nSap tang dan theo muc luong, dung mot trong cac thuat giai :\n";
	cout << "\n2. Quick Sort,";
	cout << "\n3. Heap Sort,";
	cout << "\n4. Merge Sort";
	cout << "\n5. Shaker Sort\n";
	cout << "\n##Dieu Kien##\n";
	cout << "\nNeu cung muc luong, sap tang dan theo ten";
	cout << "\nNeu cung luong, ten, sap tang dan theo ho";
	cout << "\nNeu cung luong, ten, ho, sap tang dan theo nam sinh..";
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

void XuLyMenu(int menu, nhanVien a[MAX], int& n) {
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
		cout << "\n2. Quick Sort,";
		cout << "\nChua Sap Xep :";
		Output_Arr(a, n);
		cout << "\nDa Sap Xep :";
		QuickSort(a, n);
		Output_Arr(a, n);
		break;
	case 3:
		cout << "\n3. Heap Sort,";
		cout << "\nChua Sap Xep :";
		Output_Arr(a, n);
		cout << "\nDa Sap Xep :";
		HeapSort(a, n);
		Output_Arr(a, n);
		break;
	case 4:
		cout << "\n4. Merge Sort";
		cout << "\nChua Sap Xep :";
		Output_Arr(a, n);
		cout << "\nDa Sap Xep :";
		MergeSort(a, n);
		Output_Arr(a, n);
		break;
	case 5:
		cout << "\n5. Shaker Sort\n";
		cout << "\nChua Sap Xep :";
		Output_Arr(a, n);
		cout << "\nDa Sap Xep :";
		Shaker(a, n);
		Output_Arr(a, n);
		break;
	default:
		break;
	}
}