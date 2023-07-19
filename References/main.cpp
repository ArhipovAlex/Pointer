//			References (—сылки)
#include<iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra=a;//ссылка
	ra += 3;
	cout << ra << endl;
}