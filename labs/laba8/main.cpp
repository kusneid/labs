#include "h.h"
using namespace std;

template <typename T>

void print(T a, int n, int m, char ch, int r)
{
	int lim = min(80 / (r + 10), m);
	int h = 0;
	int j = 0;
	while (h < m)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << '\n';
			if (ch == 't')
			{

				for (j = h; j < ((lim + h) > m ? m : (lim + h)); ++j)
				{
					cout << setw(r + 6) << fixed << setprecision(r) << a[i][j] << " ";
				}
			}
			else if (ch == 's')
			{

				for (j = h; j < lim + h; ++j)
				{
					cout << setw(r + 6) << scientific << setprecision(r) << a[i][j] << " ";
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

int main()
{
	system("chcp 1251");
	int n;
	char ch;
	int r;
	cout << "������� ������, ����������� � ��� ������(s/t):\n";
	cin >> n >> r >> ch;
	cout << "\n";
	double x = 1;
	double **a = new double *[n];
	fill(a, n, x);
	cout << "\n������� ������:\n";
	print(a, n, n, ch, r);
	cout << "\n\n\n";
	cout << "\n����������� ������ 10x10:\n";
	double B[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			B[i][j] = (i + 1) * 10 + (j + 1);
		}
	}
	print(B, 10, 10, 't', 0);
	clear(a, n);

	return 0;
}