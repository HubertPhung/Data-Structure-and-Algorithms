#define MAX 100

struct sinhVien {
	char maSV[8];
	char ho[8];
	char tenLot[8];
	char ten[8];
	int namSinh;
	float dtb;
};

int DocFile(char* filename,sinhVien a[MAX], int& n) {
	fstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof()) {
		in >> a[n].maSV;
		in >> a[n].ho;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		n++;
	}
	in.close();
	return 1;
}

void Xuat1SV(sinhVien a) {
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << a.maSV
		<< setw(10) << a.ho
		<< setw(10) << a.tenLot
		<< setw(10) << a.ten
		<< setw(6) << a.namSinh
		<< setw(6) << a.dtb;
	cout << endl;
}

void XuatDSSV(sinhVien a[MAX], int n) {
	for (int i = 0; i < n; i++) {
		Xuat1SV(a[i]);
		cout << endl;
	}
}

//3. Tìm kiếm tuyến tính: xuất tất cả các sinh viên trùng họ, tên cho trước và có năm sinh < x. 
void TKTT_TheoHoTenNamSinh(const char ho[10],const char ten[10], int x, sinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (strcmp(a[i].ho,ho) == 0 && strcmp(a[i].ten, ten) == 0 && a[i].namSinh < x)
		{
			Xuat1SV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay sinh vien" ;
}


//4. Tìm kiếm tuyến tính lính canh: trả về chỉ số đầu tiên sinh viên có tên cho trước. 
int TKTT_TenSV_DauTien(sinhVien a[MAX], int n , char ten[8])
{
	sinhVien x;
	strcpy_s(x.ten, ten);
	int i = 0;
	a[n] = x; 
	while (strcmp(a[i].ten, x.ten) != 0) i++;
	if (i == n)
		return -1;
	return  i;
}


//5. Dùng thuật giải chọn trực tiếp sắp danh sách tăng dần theo năm sinh. 
void HoanVi(sinhVien& a, sinhVien& b) {
	sinhVien temp = a;
	a = b;
	b = temp;
}

void Selection_TangNamSinh(sinhVien a[MAX], int n) {
	int min;
	for (int i = 0; i < n -1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j].namSinh < a[min].namSinh) {
				min = j;
			}
		}
		HoanVi(a[min], a[i]);
	}
}

//6. Dùng thuật giải Quick sort sắp danh sách giảm dần theo điểm trung bình.

int Partition(sinhVien a[], int l, int r) {

	int i = l, j = r + 1;
	while (true) {
		while (a[++i].dtb > a[l].dtb) {
			if (i == r)
				break;
		}

		while (a[--j].dtb < a[l].dtb) {
			if (j == l)
				break;
		}

		if (i >= j)
			break;

		HoanVi(a[i], a[j]);
	}
	HoanVi(a[j], a[l]);
	return j;
}

void Quicksort(sinhVien a[MAX], int l, int r) {
	if (l >= r) return;
	int midle = Partition(a, l, r);
	Quicksort(a, l, midle - 1);
	Quicksort(a, midle + 1, r);
}

void Quicksort(sinhVien a[], int n) {
	Quicksort(a, 0, n - 1);
}
//7. Tìm kiếm nhị phân: trả về chỉ số cuối cùng sinh viên có năm sinh cho trước. 


// 8. Tìm kiếm nhị phân : trả về chỉ số cuối cùng sinh viên có điểm trung bình cho trước.


