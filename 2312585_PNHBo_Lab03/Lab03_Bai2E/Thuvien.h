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



void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[MAX], R[MAX];

	for (int i = 0; i < n1; i++) L[i] = arr[left + i];
	for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int n) {
	for (int p = 1; p < n; p *= 2) {
		for (int left = 0; left < n - p; left += 2 * p) {
			int mid = left + p - 1;
			int right = min(left + 2 * p - 1, n - 1);
			merge(arr, left, mid, right);
		}
		XuatMang(arr, n);
	}
}


void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) largest = left;
	if (right < n && arr[right] > arr[largest]) largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
		XuatMang(arr, n);
	}
}



int getMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max) max = arr[i];
	return max;
}

void countSort(int arr[], int n, int exp) {
	int output[MAX];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++) count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
	int max = getMax(arr, n);
	for (int exp = 1; max / exp > 0; exp *= 10) {
		countSort(arr, n, exp);
		XuatMang(arr, n);
	}

}



int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int left = low + 1, right = high;

	while (left <= right) {
		while (left <= right && arr[left] <= pivot) left++;
		while (left <= right && arr[right] > pivot) right--;

		if (left < right) swap(arr[left], arr[right]);
	}
	swap(arr[low], arr[right]);
	return right;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
		XuatMang(arr, high + 1);
	}
}