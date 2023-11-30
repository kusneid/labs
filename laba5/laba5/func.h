#pragma once
#include <time.h>                                  
#include <stdlib.h>                                
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;
void rever(int a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	/*const int len = (sizeof(a) / sizeof(a[0]));*/
	//int* b = new int[len];
	for (int i = 0, l = len; i < l; ++i, --l) {
		swap(a[i], a[l]);
	}


	cout << "\n";
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}

}
int iRandom(int a, int b)
{
	return a + (b - a + 1) * rand() / RAND_MAX;
}
void bub(int a[], int n, char t) {
	int fl = 0;

	int i, sr = 0;

	cout << "bubble method: ";
	int bubcount = 0;
	int j;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {
			sr++;
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				fl = 1;
				++bubcount;
			}
			if (fl == 0) {
				break;
			}
		}

	}
	if (t == 'y') {
		for (i = 0; i < n; i++) {
			cout << a[i] << " ";
		}

	}

	cout << "\nСравнений: " << sr << "\nПерестановок: " << bubcount << "\n";
}
void sel(int a[], int n, char t) {

	int  c, srw = 0;
	cout << "selection method: ";
	int seleccount = 0;
	int v;
	int minm;
	for (c = 0; c < n - 1; c++) {
		minm = c;
		for (v = c + 1; v < n; v++) {
			srw++;
			if (a[v] < a[minm]) {
				minm = v;
			}
		}
		if (minm != c) {
			swap(a[c], a[minm]);
			++seleccount;
		}

	}

	if (t == 'y') {

		for (c = 0; c < n; c++) {
			cout << a[c] << " ";
		}
	}
	cout << "\nСравнений: " << srw << "\nПерестановок: " << seleccount << "\n";
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