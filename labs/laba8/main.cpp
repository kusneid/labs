#include <iostream>
#include <iomanip>
using namespace std;

int fa(int a) {
	if (a == 1) { return 1; }
	if (a == 0) return 1;
	return a * fa(a - 1);
}

void fill(double** a, int n, double x) {
	for (int t = 0; t < n; ++t) {
		a[t] = new double[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				a[i][j] = 1.0;
			}
			else if (i > j) {
				a[i][j] = pow(x, i) / pow((fa(j)), i);

			}
			else if (i < j) {
				a[i][j] = pow((-1 * x), i) / pow((fa(j)), i);

			}
			else
			{
				cout << "Error\n";
				return;
			}
		}
	}
}

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

double summ(double* a, int m) {
	double s = 0;
	for (int i = 0; i < m; i++) {
		s += a[i];
	}
	return s;
}

void clear(double** a, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
}

void sorti(double** a, int n, int m) {
	int minm;
	for (int i = 0; i < n - 1; i++) {
		minm = i;
		for (int j = i + 1; j < n; j++) {
			if (summ(a[j], m) < summ(a[minm], m)) {
				minm = j;
			}
		}
		if (minm != i) {
			swap(a[i], a[minm]);
		}
	}
}

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int n;
	char ch;
	int r = 8;
	cout << "razmer setpr i type\n";
	cin >> n >> r>>ch;
	cout << "\n";
	double x = 2;
	double** a = new double* [n];
	fill(a, n, x);
	cout << "\nmassiv main:\n";
	print(a, n, n, ch, r);
	cout << "\n\n\n";
	cout << "\nstatic 10x10:\n";
	double B[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			B[i][j] = (i + 1) * 10 + (j + 1);

		}

	}
	print(B, 10, 10, ch, r);
	cout << "\n sortik:\n";
	sorti(a, n, n);
	print(a, n, n, ch, r);
	clear(a, n);
	return 0;
}