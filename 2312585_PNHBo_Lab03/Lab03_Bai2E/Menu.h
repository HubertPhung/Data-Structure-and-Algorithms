void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int& n);

void XuatMenu() {
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Tao du lieu";
	cout << "\n1. Xem du lieu";
	cout << "\n2. Thuat giai Merge Sort";
	cout << "\n3. Thuat giai Heap Sort";
	cout << "\n4. Thuat giai Radix Sort";
	cout << "\n5. Thuat giai Quick Sort";

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
	case 0:
		cout << "\n0. Tao du lieu";
		cout << "\nNhap filename: "; cin >> filename;
		File_Array(filename, a, n);
		XuatMang(a, n);
		break;
	case 1:
		cout << "\n1. Xem du lieu";
		if (n == 0) cout << "\nKo co du lieu de xuat";
		XuatMang(a, n);
		break;
	case 2:
		cout << "\n2. Thuat giai Merge Sort";
		mergeSort(a, n);
		XuatMang(a, n);

		break;
	case 3:
		cout << "\n3. Thuat giai Heap Sort";
		heapSort(a, n);
		XuatMang(a, n);
		break;
	case 4:
		cout << "\n4. Thuat giai Radix Sort";
		radixSort(a, n);
		XuatMang(a, n);
		break;
	case 5:
		cout << "\n5. Thuat giai Quick Sort";
		quickSort(a, 0, n - 1);
		XuatMang(a, n);
		break;

	}
}