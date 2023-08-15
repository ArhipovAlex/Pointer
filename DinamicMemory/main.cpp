#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"


template <class T> void Allocate(T**& arr, const int rows, const int cols);
template <class T> void Clear(T** arr, const int rows);

template <class T> void FillRand(T arr[], const int n);
template <class T> void FillRand(T** arr, const int rows, const int cols);

template <class T> void Print(T arr[], const int n);
template <class T> void Print(T** arr, const int rows, const int cols);

template <class T> T* push_back(T arr[], int& n, T elem);
template <class T> T** push_row_back(T** arr, int& rows, const int cols);
template <class T> T** push_col_back(T** arr, const int rows, int& cols);


template <class T> T* push_front(T arr[], int& n, T elem);
template <class T> T** push_row_front(T** arr, int& rows, const int cols);
template <class T> T** push_col_front(T** arr, const int rows, int& cols);

template <class T> T* insert(T arr[], int& n, T elem, int pos);
template <class T> T** insert_row(T** arr, int& rows, const int cols, int pos);
template <class T> T** insert_col(T** arr, const int rows, int& cols, int pos);

template <class T> T* pop_back(T arr[], int& n);
template <class T> T** pop_row_back(T** arr, int& rows, const int cols);
template <class T> T** pop_col_back(T** arr, const int rows, int& cols);

template <class T> T* pop_front(T arr[], int& n);
template <class T> T** pop_row_front(T** arr, int& rows, const int cols);
template <class T> T** pop_col_front(T** arr, const int rows, int& cols);

template <class T> T* erase(T arr[], int& n, int pos);
template <class T> T** erase_row(T** arr, int& rows, const int cols, int pos);
template <class T> T** erase_col(T** arr, const int rows, int& cols, int pos);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main() 
{
	setlocale(LC_ALL, "rus");
#ifdef DYNAMIC_MEMORY_1

	int n; //���������� ��������� �������
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int elem;
	cout << "������� ����� ������� �������:"; cin >> elem;
	arr = push_back(arr, n, elem);
	Print(arr, n);
	cout << endl;

	
	cout << "������� ����� ������� ��� ������ �������:"; cin >> elem;
	arr = push_front(arr, n, elem);
	Print(arr, n);
	cout << endl;

	cout << "������� ����� ������� ��� �������:"; cin >> elem;
	int pos;
	cout << "������� ������� ������ ��������:"; cin >> pos;
	arr = insert(arr, n, elem, pos);
	Print(arr, n);
	cout << endl;

	arr = pop_back(arr, n);
	cout << "������ ��� ���������� ��������: ";
	Print(arr, n);
	cout << endl;

	arr = pop_front(arr, n);
	cout << "������ ��� ������� ��������: ";
	Print(arr, n);
	cout << endl;

	cout << "������� ������� ���������� ��������:"; cin >> pos;
	arr = erase(arr, n, pos);
	Print(arr, n);
	cout << endl;
	delete[] arr;
#endif //DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "������� ���������� ����� "; cin >> rows;
	cout << "������� ���������� ��������� ������ "; cin >> cols;
	//1) ������� ������ ����������
	int** arr = new int*[rows];
	//2) �������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter<<endl;

	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	int pos;
	cout << "������� ������� ����� ������: "; cin >> pos;
	arr = insert_row(arr, rows, cols, pos);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "������� ������� ��������� ������: "; cin >> pos;
	arr = erase_row(arr, rows, cols, pos);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "������� ������� ����� �������: "; cin >> pos;
	arr = insert_col(arr, rows, cols, pos);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "������� ������� ��������� �������: "; cin >> pos;
	arr = erase_col(arr, rows, cols, pos);
	Print(arr, rows, cols);
	cout << delimiter << endl;

#endif
}

template <class T> void Allocate(T**& arr, const int rows, const int cols) {
	arr = new T* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new T[cols];
	}
}

template <class T> void Clear(T** arr, const int rows) {
	for (int i = 0; i < rows; i++) delete[]arr[i];
	delete[]arr;
}

template <class T> void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++) 
	{
		//��������� � ��������� ������� ����� ���������� ���������� + �������� �������������
		*(arr + i) = rand() % 100;
	}
}
template <class T> void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template <class T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++) 
	{
		//��������� ����� �������� �������������� []
		cout << arr[i] << tab;
	}
}
template <class T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
template <class T> T* push_back(T arr[], int& n, T elem)
{
	T* arr2 = new T[n +1];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i];
	arr2[n] = elem;
	n++;
	delete[] arr;
	return arr2;
}
template <class T> T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows + 1] {};
	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ������� ����������� ������:
	buffer[rows] = new T[cols] {};
	//5) ����� ���������� ������ ����������� ���������� �����:
	rows++;
	return buffer;
}

template <class T> T** push_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = push_back(arr[i], cols, 0);
		cols--;
	}
	delete[] arr;
	cols++;
	return buffer;
}

template <class T> T* push_front(T arr[], int& n, T elem)
{
	T* arr2 = new T[n + 1];
	n++;
	for (int i = 1; i < n; i++)
		arr2[i] = arr[i-1];
	arr2[0] = elem;
	delete[] arr;
	return arr2;
}
template <class T> T** push_row_front(T** arr, int& rows, const int cols)
{
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows + 1] {};
	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ������� ����������� ������:
	buffer[0] = new T[cols] {};
	//5) ����� ���������� ������ ����������� ���������� �����:
	rows++;
	return buffer;
}
template <class T> T** push_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = push_front(arr[i], cols, 0);
		cols--;
	}
	delete[] arr;
	cols++;
	return buffer;
}

template <class T> T* insert(T arr[], int& n, T elem, int pos)
{
	T* arr2 = new T[n + 1];
	for (int i = 0; i < n; i++) 
	{
		arr2[i < (pos-1) ? i : i + 1] = arr[i];
	}
	arr2[pos-1] = elem;
	n++;
	delete[] arr;
	return arr2;
}
template <class T> T** insert_row(T** arr, int& rows, const int cols, int pos)
{
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows + 1] {};
	//2) �������� ������ ����� � ����� ������, ����� ������� ��� ����� ������:
	for (int i = 0; i < rows; i++)buffer[i < (pos) ? i : i + 1] = arr[i];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ������� ����������� ������ �� ��������� �������:
	buffer[pos] = new T[cols] {};
	//5) ����� ���������� ������ ����������� ���������� �����:
	rows++;
	return buffer;
}
template <class T> T** insert_col(T** arr, const int rows, int& cols, int pos)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = insert(arr[i], cols, 0, pos);
		cols--;
	}
	delete[] arr;
	cols++;
	return buffer;
}

template <class T> T* pop_back(T arr[], int& n)
{
	T* arr2 = new T[--n];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i];
	delete[] arr;
	return arr2;
}
template <class T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows - 1] {};
	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows-1; i++)buffer[i] = arr[i];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ����� �������� ������ ��������� ���������� �����:
	rows--;
	return buffer;
}
template <class T> T** pop_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = pop_back(arr[i], cols);
		cols++;
	}
	delete[] arr;
	cols--;
	return buffer;
}

template <class T> T* pop_front(T arr[], int& n)
{
	T* arr2 = new T[--n];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i+1];
	delete[] arr;
	return arr2;
}
template <class T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[] arr[0];
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows - 1] {};
	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows-1; i++)buffer[i] = arr[i+1];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ����� �������� ������ ��������� ���������� �����:
	rows--;
	return buffer;
}
template <class T> T** pop_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = pop_front(arr[i], cols);
		cols++;
	}
	delete[] arr;
	cols--;
	return buffer;
}

template <class T> T* erase(T arr[], int& n, int pos)
{
	T* arr2 = new T[--n];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i < (pos - 1) ? i : i + 1];
	delete[] arr;
	return arr2;
}
template <class T> T** erase_row(T** arr, int& rows, const int cols, int pos)
{
	//1) ������� ��������� ������ ����������
	T** buffer = new T* [rows - 1] {};
	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i < (pos - 1) ? i : i + 1];
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ����� �������� ������ ��������� ���������� �����:
	rows--;
	return buffer;
}
template <class T> T** erase_col(T** arr, const int rows, int& cols, int pos)
{
	T** buffer = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = erase(arr[i], cols, pos);
		cols++;
	}
	delete[] arr;
	cols--;
	return buffer;
}