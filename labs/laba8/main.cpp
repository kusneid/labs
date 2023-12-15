#include "h.h"
using namespace std;


template <typename T>

void print(T a, int n, int m, char ch, int r) {
	int lim = min(79 / (r + 10), m);
	int c = 0;
	int h = 0;
	int j = 0;
	while (h < m) {
		for (int i = 0; i < n; ++i) {
			cout << '\n';
			if (ch == 't') {

				for (j = h; j < ((lim + h) > m ? m : (lim + h)); ++j) {
					cout << setw(r + 6) << fixed << setprecision(r) << a[i][j] << " ";
				}
			}
			else if (ch == 's') {

				for (j = h; j < lim + h; ++j) {
					cout /*<< "|"*/ << setw(r + 6) << scientific << setprecision(r) << a[i][j] << " ";

				}
			}
			else
			{
				cout << "Error";
				return;
			}

		}
		h += lim;
		cout << "\n";
	}



}



int main() {
	

	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int n;
	char ch;
	int r = 8;
	cout << "Введите размер, погрешность и тип вывода:\n";
	cin >> n >> r>>ch;
	cout << "\n";
	double x = 1;
	double** a = new double* [n];
	fill(a, n, x);
	cout << "\nГлавный массив:\n";
	print(a, n, n, ch, r);
	cout << "\n\n\n";
	cout << "\nСтатический массив 10x10:\n";
	double B[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			B[i][j] = (i + 1) * 10 + (j + 1);

		}

	}
	print(B, 10, 10, 't', 0);
	//cout<<"\n\n"<<B<<endl;
	////system ("pause");
	//cout<<B[8]<<"  "<<B+10<<"  "<<B[2]+8<<endl;
	//cout<<*B+8<<"  "<<*(*B+8) <<"  "<<*B[9]<<endl;
	//cout<<*(B+7)<<"  "<<*(B[1])+8<<endl;
	//cout<<*(B[9]+2)<<"  " <<*(B[2])+1<<endl;
	//cout<<B[0][30]<<"  "<<*(B+50)<<"  "<<endl;
	//cout << "\n Отсортированный:\n";
	sorti(a, n, n);
	print(a, n, n, ch, r);
	clear(a, n);
	system ("pause");
	return 0;
}