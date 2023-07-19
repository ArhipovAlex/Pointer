#include<iostream>

using namespace std;
#define tab "\t"
#define delimited "\n-------------------------------------\n"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main() {
	setlocale(LC_ALL, "rus");
	int n; //Количество элементов массива
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
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