#include "h.h"
#include <Windows.h>




int main(){
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int n;
	char ch;
	cout << "������� ����������� ������� � ������ ������: �������(s)/� ��������� 8 ������ ����� �������(t)\n";
	cin>>n>>ch;
	double x = 2;
	double** a = new double* [n];
	fill(a,n,x);
	cout << "\n������������ ������:\n";
	print(a, n, n, ch);
	cout << "\n\n\n";
	cout << "\n����� ���������������� ������������ ������� 10x10:\n";
	double B[10][10];
	fillst(B);
	cout << "\n��������������� ������������ ������:\n";
	sorti(a, n, n);
	print(a, n, n, ch);
	clear(a, n);
	return 0;
	
	
}