#define MAX 100

typedef int Data;

struct tagNode {
	Data info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* getNode(Data x) {
	NODE* p = new NODE;
	if (p != NULL) {
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreateList(LIST &l) {
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l) {
	if (l.pHead == NULL)
		return 1;
	return 0;
}

//Chen cuoi 
void  InsertTail(LIST& l, Data x)
{
	NODE* new_ele = getNode(x);

	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! khong thuc hien duoc thao tac nay";
		return;
	}

	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

int File_List(char* filename, LIST& l) {
	ifstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	Data x;

	while (!in.eof()) {
		in >> x;
		InsertTail(l, x);
	}

	in.close();
	return 1;
}

void XuatDS(LIST l) {
	NODE *p;
	if (IsEmpty(l)) {
		cout << "\nDanh sach rong!";
		return;
	}
	p = l.pHead;
	while (p != NULL) {
		cout << p->info << "\t";
		p = p->pNext;
	}
}

Data TimGTNN(LIST l) {
	NODE* p;
	Data min = l.pHead->info;
	p = l.pHead;
	while (p != NULL) {
		if (min > p->info) {
			min = p->info;
		}
		p = p->pNext;
	}
	return min;
}

Data TimGTLN(LIST l) {
	NODE* p;
	Data max = l.pHead->info;
	p = l.pHead;
	while (p != NULL) {
		if (max < p->info) {
			max = p->info;
		}
		p = p->pNext;
	}
	return max;
}

int DemSLX(LIST l) {
	NODE* p;
	Data x;
	int i = 0;
	p = l.pHead;
	while (p != NULL) {
		if (x = p->info) {
			i++;
		}
		p->pNext;
	}
	return i;
}

int TinhTongGT(LIST l) {
	NODE* p;
	int sum;
	p = l.pHead;
	while (p != NULL) {
		sum += p->info;
		p = p->pNext;
	}
	return sum;
}

int TinhTongGTKhacNhau(LIST l) {
	NODE* p;
	Data x;
	int sum;
	p = l.pHead;
	while (p != NULL) {
		if (x != p->info) {
			sum += p->info;
		}
		p->pNext;
	}
	return sum;
}

int XuatCaGiaTriKhacNhauTrongDS() {

}


