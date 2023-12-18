#include "h.h"

int main()
{
	system ("chcp 1251 > nul");
	const int n = 5;
	int a[n], se[n],i;
	
	cout << "массив: ";
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

	cout << "\nобратный: \n";
	
	selreversed(a, n, 'y');
	bubreversed(se, n, 'y');
	
	cout << "\n2 задача:\n";
	for (int r = 1; r <= 1000; r = r * 10) {
		cout << "\nкол-во элементов: " << 5*r << "\n";
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





