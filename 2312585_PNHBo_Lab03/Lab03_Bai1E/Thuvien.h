#define MAX 100

void TaoDuLieu(int a[MAX], int n) {
	srand(1);

	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 101;
	}
}

void XuatMang(int a[MAX], int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}



int File_Array(string filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in) {
		return 0;
	}
	n = 0;

	while (in >> a[n]) {
		n++;
	}
	return 1;

}

int TimVTMin(int a[MAX], int n, int s) {
	int kq = a[s];
	int m = s;
	for (int i = s; i < n; i++)
		if (kq > a[i]) {
			kq = a[i];
			m = i;
		}

	return m;
}

void ChonTrucTiepGTNN(int a[MAX], int n) {
	for (int i = 0; i < n; i++) {
		swap(a[TimVTMin(a, n, i)], a[i]);
	}
}

int TimVTMax(int a[MAX], int n, int s) {
	int kq = a[s];
	int m = s;
	for (int i = 1; i < n; i++) {
		if (kq < a[i]) {
			kq = a[i];
			m = i;
		}
	}
	return m;
}

void ChonTrucTiepGTLL(int a[MAX], int n) {
	for (int i = n - 1; i > 0; i--) {
		swap(a[TimVTMax(a, i + 1, 0)], a[i]);
	}
}

void Chon2Dau(int a[MAX], int n) {
	for (int i = 0; i < trunc(n / 2) + 1; i++) {
		swap(a[TimVTMin(a, n - i, i)], a[i]);
		swap(a[TimVTMax(a, n - i, i)], a[n - i - 1]);
	}
}

void ChenTrucTiep(int a[MAX], int n) {
	int pos, i, x;
	for (i = 1; i < n; i++) {
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (a[pos] > x)) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
		XuatMang(a, n);
	}
}

void ChenTrucTiepBP(int a[MAX], int n) {
	int pos, i, x;
	for (i = n - 2; i >= 0; i--) {
		x = a[i];
		pos = i + 1;

		while (pos < n && a[pos] < x) {
			a[pos - 1] = a[pos];
			pos++;
		}
		a[pos - 1] = x;
		XuatMang(a, n);
	}

}

int binarySearch(int arr[MAX], int item, int low, int high) {
	if (high <= low)
		return (item > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == arr[mid])
		return mid + 1;

	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);
	return binarySearch(arr, item, low, mid - 1);
}

void binaryInsertionSort(int arr[MAX], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		int loc = binarySearch(arr, key, 0, j);

		while (j >= loc) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		XuatMang(arr, n);
	}

}

void InterchangeSort_MinToFront(int arr[MAX], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			swap(arr[i], arr[min_idx]);
		}
		XuatMang(arr, n);
	}
}

void InterchangeSort_MaxToEnd(int arr[MAX], int n) {
	for (int i = 0; i < n - 1; i++) {
		int maxIndex = i;

		for (int j = i + 1; j < n - i; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		if (maxIndex != n - 1 - i) {
			swap(arr[n - 1 - i], arr[maxIndex]);
		}
		XuatMang(arr, n);
	}
}

void BubbleSort_MinToStart(int arr[MAX], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;

		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) break;
		XuatMang(arr, n);
	}

}

void BubbleSort_MaxToEnd(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}

		XuatMang(arr, n);
	}
}