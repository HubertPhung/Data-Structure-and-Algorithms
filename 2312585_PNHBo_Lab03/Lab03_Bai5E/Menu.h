#define MAX 100 //kích thước khai báo mảng

//Hàm xuất các tên chức năng của chương trình
void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Tao du lieu";
	cout << "\n1. Xem du lieu";
	cout << "\n2. Thuat giai Chon Truc tiep";
	cout << "\n3. Thuat giai Chen Truc tiep";
	cout << "\n4. Thuat giai Doi cho Truc tiep";
	cout << "\n5. Thuat giai Buble";
}
//Hàm điều khiển người dùng chọn chỉ số chức năng hợp lệ : từ 0 đến soMenu
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
//Hàm xử lý menu
void XuLyMenu(int menu, int a[MAX], int& n) {
	int kq;
	string filename;
	string chon;
	switch (menu) {
	case 0:
		cout << "\n1. Tao du lieu\n";
		do {
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		break;
	case 1:
		cout << "\n1. Xem du lieu \n";
		Output(a, n); cout << '\n';
		break;
	case 2:
		cout << "\n2. Thuat giai Chon Truc tiep";
		Selection_R_L(a, n); cout << '\n';
		Output(a, n);
		break;
	case 3:
		cout << "\n3. Thuat giai Chen Truc tiep";
		Insertion_L(a, n); cout << '\n';
		Output(a, n);
		break;
	case 4:
		cout << "\n4. Thuat giai Doi cho Truc tiep";
		Interchange_L(a, n); cout << '\n';
		Output(a, n);
		break;
	case 5:
		cout << "\n5.  Thuat giai Buble";
		Buble_L(a, n); cout << '\n';
		Output(a, n);
		break;
	default:
		cout << "Thoat khoi chuong trinh";
		break;
	}
}


