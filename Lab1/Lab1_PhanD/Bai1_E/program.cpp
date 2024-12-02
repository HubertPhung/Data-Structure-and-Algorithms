#include <iostream>
#include <iomanip>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int n;
	int m;
	int s;
	cout << "\nSo phan thuong m = "; cin >> m;
	cout << "\nSo hoc sinh n = "; cin >> n;
	s = Part(m, n);
	cout << "\nSo cach chia phan thuong: \n" << s;
	cout << endl;
	system("PAUSE");
}