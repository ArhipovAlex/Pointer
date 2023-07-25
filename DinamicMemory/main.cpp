#include<iostream>

using namespace std;
#define tab "\t"
#define delimited "\n-------------------------------------\n"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int elem);
int* push_front(int arr[], int& n, int elem);
int* insert(int arr[], int& n, int elem, int pos);
int* pop_back(int arr[], int& n);

void main() 
{
	setlocale(LC_ALL, "rus");
	int n; //Количество элементов массива
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int elem;
	cout << "Введите новый элемент массива:"; cin >> elem;
	arr = push_back(arr, n, elem);
	Print(arr, n);
	cout << endl;

	
	cout << "Введите новый элемент для начала массива:"; cin >> elem;
	arr = push_front(arr, n, elem);
	Print(arr, n);
	cout << endl;

	cout << "Введите новый элемент для массива:"; cin >> elem;
	int pos;
	cout << "Введите позицию нового элемента:"; cin >> pos;
	arr = insert(arr, n, elem, pos);
	Print(arr, n);
	cout << endl;

	arr = pop_back(arr, n);
	cout << "Массив без последнего элемента: ";
	Print(arr, n);
	cout << endl;

	delete[] arr;
}

void FillRand(int arr[], const int n) 
{
	for (int i = 0; i < n; i++) 
	{
		//обращение к элементам массива через арифметику указателей + оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n) 
{
	for (int i = 0; i < n; i++) 
	{
		//обращение через оператор индексирования []
		cout << arr[i] << tab;
	}
}

int* push_back(int arr[], int& n, int elem) 
{
	int* arr2 = new int[n +1];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i];
	arr2[n] = elem;
	n++;
	delete[] arr;
	return arr2;
}

int* push_front(int arr[], int& n, int elem) 
{
	int* arr2 = new int[n + 1];
	n++;
	for (int i = 1; i < n; i++)
		arr2[i] = arr[i-1];
	arr2[0] = elem;
	delete[] arr;
	return arr2;
}
int* insert(int arr[], int& n, int elem, int pos) 
{
	int* arr2 = new int[n + 1];
	for (int i = 0; i < n; i++) 
	{
		arr2[i < (pos-1) ? i : i + 1] = arr[i];
	}
	arr2[pos-1] = elem;
	n++;
	delete[] arr;
	return arr2;
}

int* pop_back(int arr[], int& n)
{
	int* arr2 = new int[--n];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i];
	delete[] arr;
	return arr2;
}