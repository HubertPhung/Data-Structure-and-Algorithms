#define MAX 100

struct sinhvien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
};


//Ham tra ve 0 neu khong thanh cong
	//Ham tra ve 1 neu thanh cong
int TapTin_MangCT(char* filename, sinhvien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].lop;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		in >> a[n].tichLuy;
		n++;
	}
	in.close();
	return 1;
}

//Ham Xuat tieu de (ten cac truong du lieu)
void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << " Ho va Ten sinh vien"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(8) << "TichLuy"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat_SV(sinhvien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(10) << p.lop
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.dtb
		<< ':'
		<< setw(8) << p.tichLuy
		<< ':';
}

void Xuat_DSSV(sinhvien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_SV(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

int TKTT_TheoMaNV(char maNV[10], sinhvien a[MAX], int n) {
	int i = 0;

}