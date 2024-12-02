
	struct nhanVien {
		string maNV;
		string ho;
		string tenLot;
		string ten;
		int namSinh;
		float heSoLuong;
	};

	typedef nhanVien Data;

struct tagNode 
{
	Data info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

// Khai bao nguyen mau 
NODE* GetNode(Data x);
void CreateList(LIST& l);
bool IsEmpty(LIST l);
int Doc_File(string filename, LIST& l);
void InsertTail(LIST& l, Data x);

NODE* GetNode(Data x) {
	NODE* p;
	p = new NODE; // cap phat bo nho
	if (p == NULL) { // thieu bo nho
		cout << "Loi cap phat";
		return NULL;
	}
	p->info = x; // du lieu luu tru
	p->pNext = NULL; // chua tro den cai j het
	return p;
}

// Khoi tao danh sach rong
void CreateList(LIST& l) {
	l.pHead = l.pTail = NULL;
}

// Kiem tra danh sach rong
bool IsEmpty(LIST l) {
	return l.pHead == NULL;
}

// Chen vao cuoi danh sach 
void InsertTail(LIST& l, Data x) {
	NODE* p = GetNode(x);
	if (p == NULL)
		return;
	if (IsEmpty(l)) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// Doc file
int Doc_File(string filename, LIST& l) {
	Data x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	while (!in.eof()) {
		in >> x.maNV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.namSinh;
		in >> x.heSoLuong;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

void TieuDe() {
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << "MaNV"
		<< setw(15) << "Ho"
		<< setw(15) << "TenLot"
		<< setw(15) << "Ten"
		<< setw(10) << "NamSinh"
		<< setw(10) << "HeSoLuong"
		<< endl;
}

void Xuat_NV(Data p) {
	cout << setiosflags(ios::left)
		<< setw(10) << p.maNV
		<< setw(15) << p.ho
		<< setw(15) << p.tenLot
		<< setw(15) << p.ten
		<< setw(10) << p.namSinh
		<< setw(10) << fixed << setprecision(2) << p.heSoLuong
		<< endl;
}

void Xuat_DSNV(LIST l) {
	if (IsEmpty(l)) {
		cout << "\nDanh sach rong " << endl;
		return;
	}
	TieuDe();
	NODE* p = l.pHead;
	while (p != NULL) {
		Xuat_NV(p->info);
		p = p->pNext;
	}
}

// Dem so luong nhan vien co he so luong >= 3.4
int DemSoLuongNV(LIST l) {
	NODE* p = l.pHead;
	int dem = 0;
	while (p != NULL) {
		if (p->info.heSoLuong >= 3.4) {
			dem++;
		}
		p = p->pNext;
	}
	return dem;
}

// Tim kiem tuyen tinh : theo ten nhan vien, tra ve node cuoi cung
NODE* TimKiemTen(LIST l, string ten) {
	NODE* p = l.pHead;
	NODE* kq = NULL;
	while (p != NULL) {
		if (p->info.ten == ten) {
			kq = p;
		}
		p = p->pNext;
	}
	return kq;
}

// Tim theo ma NV
NODE* TimTheoMa(LIST l, string manv) {
	NODE* p = l.pHead;
	while (p != NULL) {
		if (p->info.maNV == manv) {
			return p; 
		}
		p = p->pNext;
	}
	return NULL;
}


// Chen 1 nhan vien sau nhan vien co ma nhan vien = x ( x nhap tu ban phim)
NODE* Nhap1NV() {
	Data p = { NULL };

	cout << "\nNhap maNV: "; 
	cin >> p.maNV;
	cout << "\nNhap ho: "; 
	cin >> p.ho;
	cout << "\nNhap tenLot: "; 
	cin >> p.tenLot;
	cout << "\nNhap ten: "; 
	cin >> p.ten;
	cout << "\nNhap namSinh: "; 
	cin >> p.namSinh;
	cout << "\nNhap heSoLuong: "; 
	cin >> p.heSoLuong;
	return GetNode(p);
}


void ChenNVTheoMa(LIST& l, char* manv, NODE* nv) {
	if (nv == NULL) {
		cout << "Khong co nhan vien!" << endl;
		return;
	}

	NODE* p = l.pHead;
	if (IsEmpty(l)) {
		l.pHead = l.pTail = nv;
		return;
	}

	while (p != NULL) {
		if (p->info.maNV == manv) {
			NODE* q = p->pNext;
			p->pNext = nv;
			nv->pNext = q;

			if (p == l.pTail) {
				l.pTail = nv;
			}
			return; 
		}
		p = p->pNext;
	}
}

// Xoa tat ca nhan vien theo ten nhan vien
void XoaALLNV_Ten(LIST& l, string ten) {
	NODE* p = l.pHead;
	NODE* q = NULL;
	while (p != NULL) {
		if (p->info.ten == ten) {
			NODE* temp = p;
			if (p == l.pHead) {
				l.pHead = p->pNext;
				if (l.pHead == NULL) 
					l.pTail = NULL;
			}
			else {
				q->pNext = p->pNext;
				if (p == l.pTail) l.pTail = q;
			}
			p = p->pNext;
			delete temp;
		}
		else {
			q = p;
			p = p->pNext;
		}
	}
}


// Hoan vi
void HoanVi(Data& a, Data& b) {
	Data temp = a;
	a = b;
	b = temp;
}

// Dung thuat giai chon truc tiep sap danh sach tang dan theo nam sinh
void SapXepTangDan_TheoNamSinh(LIST& l) {
	NODE* minNode;
	if (IsEmpty(l)) {
		return;
	}

	for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
		minNode = p;
		for (NODE* q = p->pNext; q != NULL; q = q->pNext) {
			if (q->info.namSinh < minNode->info.namSinh) {
				minNode = q;
			}
		}
		HoanVi(minNode->info, p->info);
	}
}

