#include <time.h>                                  
#include <stdlib.h>                                
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

int iRandom(int a, int b)
{
	return a + (b - a + 1) * rand() / RAND_MAX;
}


void bub(int a[], int n, char t) {
	cout << "bubble method: ";
	int count = 0,sr=0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			sr++;
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				++count;
			}	
		}
	}
	if (t == 'y') {
		for (int t = 0; t < n; t++) {
			cout << a[t] << " ";
		}
	}
	cout << "\nсравнений: " << sr << "\nперестановок: " << count << "\n";
}


void sel(int a[], int n, char t) {

	int sr = 0, count = 0;
	cout << "selection method: ";
	int minm;
	for (int i = 0; i < n - 1; i++) {
		minm = i;
		for (int j = i + 1; j < n; j++) {
			sr++;
			if (a[j] < a[minm]) {
				minm = j;
			}
		}
		if (minm != i) {
			swap(a[i], a[minm]);
			++count;
		}

	}

	if (t == 'y') {

		for (int t = 0; t < n; t++) {
			cout << a[t] << " ";
		}
	}
	cout << "\nсравнений: " << sr << "\nперестановок: " << count << "\n";
}


void ran(int a[], int n, char t) {
	srand((unsigned int)time(NULL));
	rand();
	int i = 0;
	for (i = 0; i < n; i++) {
		a[i] = iRandom(1, 19);
		if (t == 'y') { cout << a[i] << " "; }
	}
}


int main()
{
	system ("chcp 1251");
	const int n = 5;
	int a[n], se[n],i;
	
	cout << "неотсортированный массив: ";
	ran(a, n, 'y');
	for (i = 0; i < n; i++) {
		se[i] = a[i];
	}

	cout << "\n";
	bub(se, n, 'y');
	sel(a, n, 'y');

	cout << "\nпрямой порядок: \n";
	sel(a, n, 'y');
	bub(se, n, 'y');

	cout << "\nобратный порядок: \n";
	reverse(a, a + n - 1);
	reverse(se, se + n - 1);
	sel(a, n, 'y');
	bub(se, n, 'y');
	
	cout << "\n2 часть:\n";
	for (int r = 1; r <= 1000; r = r * 10) {
		cout << "\n кол-во элементов: " << 5*r << "\n";
		int* p = new int[5 * r];
		ran(p, 5 * r, 'l');
		int* u = new int[5 * r];
		for (i = 0; i < 5 * r; i++) {
			u[i] = p[i];
		}
		bub(p, 5 * r, 'l');
		delete[] p;
		sel(u, 5 * r, 'l');
		delete[] u;
	}
}





