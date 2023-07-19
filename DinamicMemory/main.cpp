#include<iostream>

using namespace std;
#define tab "\t"
#define delimited "\n-------------------------------------\n"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* AddElement(int arr[], int n, int elem);

void main() {
	setlocale(LC_ALL, "rus");
	int n; //���������� ��������� �������
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	int elem;
	cout << "������� ����� ������� �������:"; cin >> elem;
	int* arr2 = AddElement(arr, n++, elem);
	Print(arr2, n);
	cout << endl;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		//��������� � ��������� ������� ����� ���������� ���������� + �������� �������������
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		//��������� ����� �������� �������������� []
		cout << arr[i] << tab;
	}
}

int* AddElement(int arr[], int n, int elem) {
	int* arr2 = new int[n +1];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i];
	arr2[n] = elem;
	delete[] arr;
	return arr2;
}