#include <iostream>

using namespace std;

int main() {
	//int n = 2024;
	//int m = n; // tham trị
	//n++;
	//cout << n << endl;
	//cout << m << endl;

	//int x;
	//int y = x; // uninitialized local variable 'x'
	//cout << x << endl;
	//cout << y << endl;

	//int n = 2024;
	//Func(n); // Tham trị, tạo 1 bản sao của n
	//cout << n << endl;

	//int n = 2024;
	//Func2(n); // Tham chiếu
	//cout << n << endl;

	int n = 2024;
	//cout << n << endl;
	//cout << &n << endl; // địa chỉ của n trong bộ nhớ trong (RAM)
	int m = n;
	//cout << m << endl;
	//cout << &m << endl;
	int* o = &n; // Con trỏ o trỏ đến địa chỉ của biến n (int *o)
	//cout << n << endl;
	n++;
	cout << n << endl;
	cout << o << endl; // o là con trỏ, giá trị của o là địa chỉ của n
	cout << *o << endl; // là giá trị giá trị của n
	cout << &o << endl; // địa chỉ của o
	/*cout << o << endl;
	o++;
	cout << n << endl;
	cout << o << endl;*/
}

