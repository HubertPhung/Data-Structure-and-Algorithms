#define MAX 100

struct nhanVien {
	char maNV[8];
	char ho[15];
	char tenlot[10];
	char ten[10];
	char diaChi[15];
	unsigned int namSinh;
	unsigned int luong;
};


int File_Array(string filename, nhanVien a[MAX], int& n) {
	ifstream in(filename);
	if (!in) {
		cout << "Khong doc duoc file !";
		return 0;
	}
	n = 0;

	while (in >> a[n].maNV >> a[n].ho >> a[n].tenlot >> a[n].ten >> a[n].diaChi >> a[n].namSinh >> a[n].luong) {
		cout << "\nDang doc nhan vien :" << a[n].maNV;
		n++;
	}
	in.close();
	return 1;
}

void Heading() {
	cout << endl;
	for (int i = 0; i <= 105; i++) {
		cout << "=";
	}
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(10) << "Ma NV"
		<< setw(15) << "Ho"
		<< setw(15) << "Ten lot"
		<< setw(10) << "Ten"
		<< setw(10) << "Dia chi"
		<< setw(10) << "NSinh"
		<< setw(10) << "Luong";
	cout << "\n";
	for (int i = 0; i <= 105; i++) {
		cout << "=";
	}
}

void Output_1NV(nhanVien nv) {
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(10) << nv.maNV
		<< setw(15) << nv.ho
		<< setw(15) << nv.tenlot
		<< setw(10) << nv.ten
		<< setw(10) << nv.namSinh
		<< setw(10) << nv.diaChi
		<< setw(10) << nv.luong;
	cout << "\n";
}

void Output_Arr(nhanVien a[MAX], int n) {
	Heading();
	for (int i = 0; i < n; i++) {
		Output_1NV(a[i]);
		cout << "\n";
	}
}

// Chon truc tiep
void Selection_L(nhanVien a[MAX], int n)
{
	int i, j;
	int cs_min;
	for (i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (a[j].maNV < a[cs_min].maNV)
				cs_min = j;
		swap(a[i].maNV, a[cs_min].maNV);
	}
}

// Chen truc tiep

void Insertion_L(nhanVien a[MAX], int n)
{
	int i, pos;
	nhanVien x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i - 1; (pos >= 0) && (strcmp(a[pos].diaChi, x.diaChi) > 0); pos--)
			a[pos + 1] = a[pos];
		a[pos + 1] = x;
	}
}


// Radix
void Radix(nhanVien a[MAX], int n) {
	int max, m = 0;
	max = a[0].namSinh;

	for (int i = 1; i < n; i++) {
		if (a[i].namSinh > max)
			max = a[i].namSinh;
	}

	while (max != 0) {
		max = max / 10;
		m++;
	}

	int k = 0; 
	nhanVien b0[MAX], b1[MAX], b2[MAX], b3[MAX], b4[MAX];
	nhanVien b5[MAX], b6[MAX], b7[MAX], b8[MAX], b9[MAX];
	int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;

	while (k < m) {
		
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = 0;


		for (int i = 0; i < n; i++) {
			int thuong = a[i].namSinh;
			int du;

			for (int j = 0; j <= k; j++) {
				du = thuong % 10;
				thuong = thuong / 10;
			}

			switch (du) {
			case 0: b0[p0++] = a[i]; break;
			case 1: b1[p1++] = a[i]; break;
			case 2: b2[p2++] = a[i]; break;
			case 3: b3[p3++] = a[i]; break;
			case 4: b4[p4++] = a[i]; break;
			case 5: b5[p5++] = a[i]; break;
			case 6: b6[p6++] = a[i]; break;
			case 7: b7[p7++] = a[i]; break;
			case 8: b8[p8++] = a[i]; break;
			case 9: b9[p9++] = a[i]; break;
			}
		}

		int j = 0;
		for (int i = 0; i < p0; i++) a[j++] = b0[i];
		for (int i = 0; i < p1; i++) a[j++] = b1[i];
		for (int i = 0; i < p2; i++) a[j++] = b2[i];
		for (int i = 0; i < p3; i++) a[j++] = b3[i];
		for (int i = 0; i < p4; i++) a[j++] = b4[i];
		for (int i = 0; i < p5; i++) a[j++] = b5[i];
		for (int i = 0; i < p6; i++) a[j++] = b6[i];
		for (int i = 0; i < p7; i++) a[j++] = b7[i];
		for (int i = 0; i < p8; i++) a[j++] = b8[i];
		for (int i = 0; i < p9; i++) a[j++] = b9[i];

		k++; 
	}
}
