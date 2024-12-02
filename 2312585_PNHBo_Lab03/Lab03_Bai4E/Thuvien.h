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


// Hoan vi
void HoanVi(nhanVien& a, nhanVien& b) {
	nhanVien temp = a;
	a = b;
	b = temp;
}

// Phan Hoach

void Partition(nhanVien a[MAX], int l, int r)
{
	int i, j;
	nhanVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (a[i].luong < x.luong)
			i++;
		while (a[j].luong > x.luong)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);

	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}

//Quick sort 
void QuickSort(nhanVien a[MAX], int n)
{
	Partition(a, 0, n - 1);
}

//Heap sort

void Shift(nhanVien a[MAX], int l, int r) {
	int i, j;
	nhanVien x;
	i = 1; j = 2 * i + 1;
	x = a[i];
	while (j <= r) {
		if (i < r) {
			if (a[j].luong < a[j + 1].luong)
				j = j + 1;
			if (a[j].luong <= x.luong)
				return;
			else
			{
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
				a[i] = x;
			}
		}
	}
}

void Create_Heap(nhanVien a[MAX], int n) {
	int l;
	l = (n - 1) / 2;
	while (l >= 0) {
		Shift(a, l, n - 1);
		l = l - 1;
	}
}

void HeapSort(nhanVien a[MAX], int n) {
	int r, i = 0;
	Create_Heap(a, n);
	r = n - 1;
	while (r > 0) {
		i++;
		HoanVi(a[0], a[r]);
		r = r - 1;
		Shift(a, 0, r);
	}
}

void Distribution(nhanVien F[MAX], int n, nhanVien F1[MAX], int& h1, nhanVien F2[MAX], int& h2, int p) {
	int i, k = 1, l = 0;
	h1 = 0; h2 = 0;
	do {
		i = 1;
		while (i <= p && l < n) {
			if (k == 1) {
				F1[h1++] = F[l];
			}
			else
			{
				F2[h2++] = F[l];
			}
			i++;
			l++;
		}
	} while (l < n);
}

void Merge(nhanVien F1[MAX], int h1, nhanVien F2[MAX], int h2, nhanVien F[MAX], int p) {
	int i1 = 0, i2 = 0, r1, r2;
	int h = 0;
	while (i1 < h1 && i2 < h2) {
		r1 = r2 = 1;
		while ((r1 <= p) && (r2 <= p) && i1 < h1 && i2 < h2) {
			if (F1[i1].luong <= F2[i2].luong) {
				F[h++] = F1[i1];
				r1++;
				i1++;
			}
			else
			{
				F[h++] = F1[i1];
				r2++;
				i2++;
			}
		}
		while (i1 < h1 && r1 <= p) {
			F[h++] = F1[i1];
			i1++; r1++;
		}
		while (i2 < h2 && r2 <= p) {
			F[h++] = F2[i2];
			i2++; r2++;
		}
	}
	while (i1 < h1) {
		F[h++] = F1[i1];
		i1++;
	}
	while (i2 < h2) {
		F[h++] = F2[i2];
		i2++;
	}
}

// Merge sort 
void MergeSort(nhanVien F[MAX], int n) {
	int p = 1, h1, h2;
	nhanVien F1[MAX], F2[MAX];
	int i = 1;
	while (p < n) {
		Distribution(F, n, F1, h1, F2, h2, p);
		Merge(F1, h1, F2, h2, F, p);
		i++;
		p = p * 2;
	}
}

// Shaker 
void Shaker(nhanVien a[MAX], int n) {
	int l = 0, r = n - 1;
	int k = n - 1;
	int j;
	while (l < r) {
		j = r;
		while (j > l) {
			if (a[j].luong < a[j - 1].luong) {
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
			j = j - 1;
		}
		l = k;

		j = l;
		while (j < r) {
			if (a[j].luong > a[j + 1].luong) {
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
			j = j + 1;
		}
		r = k;
	}
}
