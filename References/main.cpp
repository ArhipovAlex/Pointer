//			References (������)
#include<iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra=a;//������
	ra += 3;
	cout << ra << endl;
}