#define MAX 100

struct ngayThangNam {
	int ngay;
	int thang;
	int nam;
};

struct nhanvien {
	string maNV;
	string ho;
	string tenLot;
	string ten;
	ngayThangNam namSinh;
	string diaChi;
	double luong;
};

void Xuat_NV(nhanvien p);

bool inputData(nhanvien& nv) {
	return (nv.maNV.length() <= 7 && nv.ho.length() <= 10 && nv.tenLot.length() <= 10
		&& nv.ten.length() <= 10 && nv.diaChi.length() <= 15 && (nv.luong >= 0 && nv.luong <= 9999999));
}
int TapTin_MangCT(string filename, nhanvien a[], int& n) {
	ifstream in(filename);
	if (!in) {
		return 0;
	}
	n = 0;


	while (in >> a[n].maNV >> a[n].ho >> a[n].tenLot >> a[n].ten
		>> a[n].namSinh.ngay >> a[n].namSinh.thang >> a[n].namSinh.nam >> a[n].diaChi >> a[n].luong) {
		if (inputData(a[n])) {
			n++;
		}
		else {
			cout << "Du lieu nhan vien thu " << n + 1 << " khong hop le!!!";
		}
	}
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << "\n";
	cout;
	for (i = 1; i <= 105; i++)
		cout << '=';
	cout;
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << setw(9) << "Ma SV"

		<< setw(10) << " Ho"

		<< setw(15) << "tLot"

		<< setw(15) << "Ten"

		<< setw(20) << "NTNSinh"

		<< setw(20) << "Dia Chi"

		<< setw(30) << "Luong";
	cout << "\n";
	for (i = 1; i <= 105; i++)
		cout << '=';
	cout;
	cout << "\n";
}



void Xuat_NV(nhanvien p) {
	cout << setiosflags(ios::left);
	cout;
	cout << setw(9) << p.maNV

		<< setw(10) << p.ho

		<< setw(15) << p.tenLot

		<< setw(15) << p.ten

		<< setw(2) << p.namSinh.ngay << setw(1) << "/" << setw(2) << p.namSinh.thang << setw(1) << "/" << setw(4) << p.namSinh.nam << setw(10) << " "

		<< setw(20) << p.diaChi

		<< setw(30) << p.luong;

	cout << "\n";

}

void Xuat_DSNV(nhanvien a[MAX], int n) {
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_NV(a[i]);
		cout << '\n';
	}

}


void Tim_TheoHoTen(string ho, string ten, nhanvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].ho == ho && a[i].ten == ten)
		{
			Xuat_NV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay nhan vien co ho la " << ho << " ten la " << ten;
}

void Tim_TheoNamSinh(int nam, nhanvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].namSinh.nam == nam)
		{
			Xuat_NV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay nhan vien co nam sinh la " << nam;
}

void Tim_TheoHoTenNamSinh(string ho, string ten, int x, nhanvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].ho == ho && a[i].ten == ten && a[i].namSinh.nam < x)
		{
			Xuat_NV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay nhan vien co ho la " << ho << " ten la " << ten << " namSinh < " << x;
}

void Tim_TheoTenVaDiaChi(string ten, string diaChi, nhanvien a[MAX], int n)
{

	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].ten == ten && a[i].diaChi == diaChi)
		{
			Xuat_NV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay nhan vien co ten la " << ten << " diaChi " << diaChi;
}
void Tim_TheoLuongVaNamSinh(double luong, int nam, nhanvien a[MAX], int n)
{

	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].namSinh.nam <= nam && a[i].luong >= luong)
		{
			Xuat_NV(a[i]);
			kq = 1;
		}
	if (kq == -1) cout << "\nKo tim thay nhan vien co nam sinh la " << nam << " luong " << luong;
}


int TimKiemNhiPhan(nhanvien a[MAX], int n, string& maNV) {
	int l = 0;
	int r = n - 1;

	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (a[mid].maNV == maNV) {
			return mid;
		}
		if (a[mid].maNV < maNV) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}