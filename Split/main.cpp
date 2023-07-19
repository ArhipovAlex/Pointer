//Split
#include<iostream>

using namespace std;
#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int CountODD(int arr[], const int n);
void Split(int arr1[], int arr2[], const int size, bool ODD);

void main() {
	setlocale(LC_ALL, "rus");
	const int size = 10;
	int arr[size] = {};
	FillRand(arr, size);
	Print(arr, size);
	cout << endl;
	int count_Odd=CountODD(arr,size);
	int count_Even = size - count_Odd;
	int* arr_ODD = new int[count_Odd];
	int* arr_Even = new int[count_Even];
	Split(arr, arr_ODD, size, 1);
	Print(arr_ODD, count_Odd);
	cout << endl;
	delete[] arr_ODD;
	Split(arr, arr_Even, size, 0);
	Print(arr_Even, count_Even);
	cout << endl;
	delete[] arr_Even;
	
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
}

int CountODD(int arr[], const int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) { k++; }
	}
	return k;
}
void Split(int arr1[], int arr2[], const int size, bool ODD) {
	int n = 0;
	for (int i = 0; i < size; i++) {
		if ((ODD) && (arr1[i]%2!=0)) {
			arr2[n] = arr1[i];
			n++;
		}
		else if (!(ODD)&&(arr1[i]%2==0))
		{
			arr2[n] = arr1[i];
			n++;
		}
	}

}