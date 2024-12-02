typedef int Data;

#define NULLDATA 0

// Một phần tử (nút)
struct tagNode
{
	Data info;
	tagNode* pNext;
};

typedef tagNode NODE;

/*

struct NODE
{
	int info;
	NODE* pNext;
};

*/

// Một danh sách liên kết
struct LIST
{
	NODE* pHead; // Con trỏ đầu (required)
	NODE* pTail; // Con trỏ đuôi (optional)
};

// Tạo một phần tử (nút)
NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE; // Cấp phát bộ nhớ (allocation)
	if (p == NULL) // Thiếu bộ nhớ
	{
		cout << "Loi cap phat";
		return NULL;
	}
	p->info = x; // Dữ liệu lưu trữ
	p->pNext = NULL; // Nó chưa trỏ cái gì hết
	return p;
}

// Khởi tạo một danh sách rỗng
void CreateList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(LIST l)
{
	return l.pHead == NULL;
}

// In các phần tử có trong danh sách
void Print(LIST l)
{
	if (IsEmpty(l))
	{
		cout << "Danh sach rong" << '\n';
		return;
	}
	//// Con trỏ p duyệt qua các phần tử
	//NODE* p = l.pHead;
	//while (p != NULL) // Đi hết danh sách
	//{
	//	cout << p->info << '\t'; // In giá trị
	//	p = p->pNext; // Di chuyển sang ptu kế tiếp
	//}
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << '\t';
	}
}

// Tìm phần tử x trong danh sách và
// trả về địa chỉ nút đầu tiên
NODE* SearchFirst(LIST l, Data x)
{
	NODE* p = l.pHead;
	for (; p != NULL && p->info != x; p = p->pNext);
	return p;
}

// Tìm phần tử x trong danh sách và
// trả về địa chỉ nút cuối cùng
NODE* SearchLast(LIST l, Data x)
{
	NODE* p = l.pHead, * q = NULL;
	for (; p != NULL; p = p->pNext)
	{
		if (p->info == x)
			q = p;
	}
	return q;
}

// Chèn x vào đầu danh sách
void InsertHead(LIST& l, Data x)
{
	NODE* p = GetNode(x);
	if (p == NULL) // Thiếu bộ nhớ
		return;
	if (IsEmpty(l)) // DS rỗng
	{
		l.pHead = l.pTail = p;
	}
	else // DS khác rỗng
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

// Chèn x vào cuối danh sách
void InsertTail(LIST& l, Data x)
{
	NODE* p = GetNode(x);
	if (p == NULL) // Thiếu bộ nhớ
		return;
	if (IsEmpty(l)) // DS rỗng
	{
		l.pHead = l.pTail = p;
	}
	else // DS khác rỗng
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

//// Chèn vào vị trí pos trong danh sách do người dùng nhập
//void InsertMiddle(LIST& l, Data x, int pos) {
//	int n = Length(l);
//	if (pos <= 0 || pos > n + 1) {
//		cout << "Vi tri chen khong hop le !\n";
//	}
//	if (n == 1) {
//		InsertHead(l, x);
//		return;
//	}
//	else if (n == pos + 1) {
//		InsertTail(l, x);
//		return;
//	}
//	NODE* p = l.pHead;
//	for (int i = 1; i < pos - 1; i++) {
//		p = p->pNext;
//	}
//	NODE* tmp = GetNode(x);
//	tmp->pNext = p->pNext;
//}

// Chèn ngẫu nhiên n phần tử vào danh sách
void GetRandomList(LIST& l, int n, int min = 0, int max = 10)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		int x = rand() % (max - min + 1) + min;
		InsertTail(l, x);
	}
}

// Đếm số lượng nút có trong danh sách
int Length(LIST l)
{
	int count = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->pNext, count++);
	return count;
}

// Xóa phần tử cuối		
Data RemoveTail(LIST& l)
{
	Data x;
	if (IsEmpty(l)) 
		return ;
	NODE* p = l.pHead;
	if (p->pNext == NULL) 
	{
		l.pHead = l.pTail = NULL;
		delete p;
		return x; 
	}
	while (p->pNext != l.pTail) 
		p = p->pNext;
	delete l.pTail;
	l.pTail = p;
	l.pTail->pNext = NULL;
	return x; 
}

// Chèn new_ele vào sau phần tử ele tìm thấy đầu tiên
void InsertAfter(LIST& l, Data new_ele, Data ele)
{
	NODE* p = GetNode(new_ele);
	if (p == NULL)
		return;
	NODE* q = l.pHead;
	if (IsEmpty(l)) //Nếu danh sách rỗng
		InsertHead(l, new_ele);
	else // Danh sách khác rỗng
		while (q != NULL) // Tìm phần tử q có giá trị ele đầu tiên
		{
			if (q->info == ele)
			{
				p->pNext = q->pNext; // Thay đổi con trỏ
				q->pNext = p;
				return; // Không kiểm tra phía sau nữa
			}
			q = q->pNext;
		}
}

// Xóa phần tử đầu
Data RemoveHead(LIST& l)
{
	Data x = NULLDATA;
	if (!IsEmpty(l)) // Danh sách khác rỗng
	{
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		x = p->info; // Lưu lại giá trị của p
		delete p;
		if (l.pHead == NULL) // Nếu xóa phần tử đầu mà ds rỗng
			l.pTail = NULL;
	}
	return x;
}

// Xóa phần tử cuối
Data RemoveTail(LIST& l)
{
	Data x = NULLDATA;
	if (!IsEmpty(l))
	{
		NODE* p = l.pHead;
		while (p->pNext != l.pTail)
			p = p->pNext;
		delete l.pTail;
		l.pTail = p;
		l.pTail->pNext = NULL;
	}
	return x;
}

// Xóa hết x ra khỏi danh sách
void RemoveX(LIST& l, Data x)
{
	NODE* p = l.pHead;
	NODE* q = NULL; // Phan tu nam truoc p
	while (p != NULL)
	{
		if (p->info == x)
		{
			// x nằm đầu danh sách
			if (p == l.pHead) {
				RemoveHead(l);
				p = l.pHead; // Lấy giá trị mới nhất cập nhật vào p
			}
			// x nằm cuối danh sách
			else if (p == l.pTail) {
				RemoveTail(l);
				p = NULL;
			}
			// x nằm giữa danh sách
			else
			{
				q->pNext = p->pNext;
				delete p;
				p = q;
			}
		}
		else
		{
			q = p;
			p = p->pNext;
		}
	}
}

//Hủy toàn bộ danh sách
void RemoveList(LIST& l)
{
	NODE* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}

// Hoán vị giá trị
void HoanVi(NODE* x, NODE* y)
{
	Data t = y->info;
	y->info = x->info;
	x->info = t;
}

// Sắp xếp theo chiều tăng của Data
void InterchangeSort(LIST& l)
{
	for (NODE* p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->info > q->info)
				HoanVi(p, q);
		}
	}
}