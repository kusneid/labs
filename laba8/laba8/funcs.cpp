#include "h.h"
int fa(int a) {
	if (a == 1) { return 1; }
	if (a == 0) return 1;
	return a * fa(a - 1);
}
void fill(double** a, int n, double x) {

	for (int t = 0; t < n; ++t) {
		a[t] = new double[n];
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				a[i][j] = 1.0;
			}
			else if (i > j) {
				a[i][j] = pow(x, i+1) / pow((fa(j+1)), i+1);
			}
			else if (i < j) {
				a[i][j] = pow((-1 * x), i+1) / pow((fa(j+1)), i+1);
			}
			else
			{
				cout << "Error\n";
				return;
			}
		}

	}*/


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				a[i][j] = 1.0;
			}
			else if (i > j) {
				a[i][j] = pow(x, i) / pow((fa(j)), i);
				//a[i][j] = a[i - 1][j] * ((-x) / fa(j + 1));
			}
			else if (i < j) {
				a[i][j] = pow((-1 * x), i) / pow((fa(j)), i);
				//a[i][j] = a[i][j - 1] / pow(j + 1, i + 1);
			}
			else
			{
				cout << "Error\n";
				return;
			}
		}

	}


}
void print(double** a, int n, int m, char ch) {
	/*cout << "\n";
	for (int i = 0; i < m; i++)
	{
		cout << "----------------";
	}*/
	for (int i = 0; i < n; ++i) {
		cout << '\n';
		if (ch == 't') {
			for (int j = 0; j < m; ++j) {
				cout /*<<"|"*/ << setw(14) << fixed << setprecision(8) << a[i][j] << " ";

			}
		}
		else if (ch == 's') {
			for (int j = 0; j < m; ++j) {
				cout /*<< "|"*/ << setw(14) << scientific << a[i][j] << " ";

			}
		}
		else
		{
			cout << "Error";
			return;
		}
		/*cout << "\n";
		for (int i = 0; i < m; i++)
		{
			cout << "----------------";
		}*/

	}


}

void fillst(double B[10][10]) {
	double** a = new double* [10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			B[i][j] = (i + 1) * 10 + (j + 1);

		}
		a[i] = B[i];
	}
	print(a, 10, 10, 't');
	delete[] a;
}
void clear(double** a, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
}
void sorti(double** a,int n, int m) {
	/*double* t = new double[n];
	for (int h = 0; h < n; h++) {
		t[n] = summ(a[n],m);
		
	}*/


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
double summ(double* a, int m) {
	double s = 0;
	for (int i = 0; i < m; i++) {
		s += a[i];
	}
	return s;
}
