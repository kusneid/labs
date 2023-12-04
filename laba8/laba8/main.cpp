#include "h.h"
#include <Windows.h>




int main(){
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int n;
	char ch;
	cout << "Введите размерность массива и формат вывода: научный(s)/с точностью 8 знаков после запятой(t)\n";
	cin>>n>>ch;
	double x = 2;
	double** a = new double* [n];
	fill(a,n,x);
	cout << "\nДинамический массив:\n";
	print(a, n, n, ch);
	cout << "\n\n\n";
	cout << "\nВывод отсортированного статического массива 10x10:\n";
	double B[10][10];
	fillst(B);
	cout << "\nОтсортированный динамический массив:\n";
	sorti(a, n, n);
	print(a, n, n, ch);
	clear(a, n);
	return 0;
	
	
}