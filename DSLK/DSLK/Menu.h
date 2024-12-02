void XuatMenu();
void XuLyMenu(int menu, LIST& l);
int ChonMenu(int soMenu);
void ChayChuongTrinh();


// Xuất menu
void XuatMenu() {
    cout << "\n===================Menu=====================";
    cout << "\n1. Nhap danh sach tu dong";
    cout << "\n2. Xuat danh sach";
    cout << "\n3. Tim phan tu dau tien";
    cout << "\n4. Tim phan tu cuoi cung";
    cout << "\n5. Chen phan tu vao dau danh sach";
    cout << "\n6. Chen phan tu vao cuoi danh sach";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n===========================================================";
}

// Chọn menu
int ChonMenu(int soMenu) {
    int stt;
    for (;;) {
        system("CLS");
        XuatMenu();
        cout << "\nNhap 1 so thuoc khoang [0.." << soMenu << "] de chon chuc nang, stt = ";
        cin >> stt;
        cin.ignore();
        if (stt >= 0 && stt <= soMenu)
            break;
    }
    return stt;
}

// Xử lý menu
void XuLyMenu(int menu, LIST& l) {
    Data x;
    int pos;
    switch (menu) {
    case 1:
        CreateList(l);
        GetRandomList(l, 10, 1, 10);
        Print(l);
        cout << "So luong cac phan tu: " << Length(l) << '\n';
        break;
    case 2:
        Print(l);
        break;
    case 3:
        cout << "Nhap gia tri can tim: ";
        cin >> x;
                if (SearchFirst(l, x) != NULL)
            cout << "Tim thay phan tu cuoi cung co gia tri " << x << '\n';
        else
            cout << "Khong tim thay phan tu co gia tri " << x << '\n';
        break;

    case 4:
        cout << "Nhap gia tri can tim: ";
        cin >> x;
        if (SearchLast(l, x) != NULL)
            cout << "Tim thay phan tu cuoi cung co gia tri " << x << '\n';
        else
            cout << "Khong tim thay phan tu co gia tri " << x << '\n';
        break;
    case 5:
        cout << "Nhap gia tri can chen vao dau danh sach: ";
        cin >> x;
        InsertHead(l, x);
        Print(l);
        break;
    case 6:
        cout << "Nhap gia tri can chen vao cuoi danh sach: ";
        cin >> x;
        InsertTail(l, x);
        Print(l);
        break;
    default:
        break;
    }
    _getch();
}

// Chạy chương trình
void ChayChuongTrinh() {
    int menu,
        soMenu = 6;
    LIST l;
    CreateList(l);
    do {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, l);
    } while (menu > 0);
}