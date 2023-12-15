#include "h.h"

int main()
{
	system ("chcp 1251 > nul");
	const int n = 5;
	int a[n], se[n],i;
	
	cout << "Неотсортированный: ";
	ran(a, n, 'y');
	for (i = 0; i < n; i++) {
		se[i] = a[i];
	}

	cout << "\n";
	bub(se, n, 'y');
	sel(a, n, 'y');

	cout << "\nОтсортированный: \n";
	sel(a, n, 'y');
	bub(se, n, 'y');

	cout << "\nОтсортированный в обратном порядке: \n";
	rever(a, n);
	rever(se, n);
	sel(a, n, 'y');
	bub(se, n, 'y');
	
	cout << "\n2 задание:\n";
	for (int r = 1; r <= 1000; r = r * 10) {
		cout << "\nДлина массива: " << 5*r << "\n";
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
	return 0;
}





