// 0) г, б, д, а, в

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length) {
	;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}
}


void outputArr(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int findMin(int arr[], int size) {
	int minElem = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < minElem)
			minElem = arr[i];
	}
	return minElem;
}



int findMax(int arr[], int size) {
	int maxElem = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > maxElem)
			maxElem = arr[i];
	}
	return maxElem;
}


int sumArr(int arr[], int size) {
	int s = 0;
	for (int i = 0; i < size; i++)
		s += arr[i];
	return s;
}



int middle(int arr[], int size) {
	return arr[size / 2];
}


int moda(int arr[], int size) {
	int maxElem = arr[0];
	int count = 1;
	for (int i = 0; i < size; i++) {
		int tempCount = 0;
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j]) {
				tempCount++;
			}
		}
		if (tempCount > count) {
			count = tempCount;
			maxElem = arr[i];
		}
	}
	return maxElem;
}


int dispersion(int arr[], int size) {
	float average = (float)sumArr(arr, size) / size;
	float disp = 0;
	for (int i = 0; i < size; i++) {
		disp += pow((float)arr[i] - average, 2) / (size - 1);
	}
	return disp;
}


int binarySearch(int elem, int arr[], int left, int right) {
	int mid = (right + left) / 2;

	if (arr[mid] == elem)
		return mid;
	else if (mid == left)
		return -1;
	else if (elem < arr[mid])
		return binarySearch(elem, arr, left, mid);
	else
		return binarySearch(elem, arr, mid, right);
}



void GaussianTransformation(float (*arr)[3], int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			float mult = arr[j][i] / arr[i][i];
			for (int k = 0; k < width; k++) {
				arr[j][k] -= mult * arr[i][k];
			}
		}
	}

	for (int i = length - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			float mult = arr[j][i] / arr[i][i];
			for (int k = 0; k < width; k++) {
				arr[j][k] -= mult * arr[i][k];
			}
		}
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

}



int main() {
	setlocale(LC_ALL, "Russian");

	const int n = 6;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	outputArr(arr, n);
	/*
	bubbleSort(arr, n);

	outputArr(arr, n);

	cout << "Минимум = " << findMin(arr, n) << " Максимум = " << findMax(arr, n) << endl;
	cout << "Размах = " << findMax(arr, n) - findMin(arr, n) << endl;
	cout << "Среднее арифмитическое = " << (float)sumArr(arr, n) / n << endl;
	cout << "Медиана = " << middle(arr, n) << endl;
	cout << "Мода = " << moda(arr, n) << endl;
	cout << "Дисперсия = " << dispersion(arr, n) << endl;
	*/
	int elem;
	cin >> elem;
	cout << "Index = " << binarySearch(elem, arr, 0, n) << " Elem = " << arr[binarySearch(elem, arr, 0, n)] << endl;

	return 0;
}
