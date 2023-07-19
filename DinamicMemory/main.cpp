#include<iostream>

using namespace std;
#define tab "\t"
#define delimited "\n-------------------------------------\n"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* AddElement(int arr[], int n, int elem);

void main() {
	setlocale(LC_ALL, "rus");
	int n; //Количество элементов массива
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	int elem;
	cout << "Введите новый элемент массива:"; cin >> elem;
	int* arr2 = AddElement(arr, n++, elem);
	Print(arr2, n);
	cout << endl;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		//обращение к элементам массива через арифметику указателей + оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		//обращение через оператор индексирования []
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