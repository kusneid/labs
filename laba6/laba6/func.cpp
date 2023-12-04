
#include "header.h"
using namespace std;
double f1(double x) {
	return x;
}
double f2(double x) {
	return sin(22 * x);
}
double f3(double x) {
	return pow(x, 4);
}
double f4(double x) {
	return atan(x);
}
void PrintTabl(I_print i_prn[], int k)
{
	const int m = 4;//число столбцов таблицы
	int wn[m] = { 12,18,18,10 };//ширина столбцов таблицы
	char* title[m] = { "Function","Integral","IntSum","N " };
	int size[m];
	for (int i = 0; i < m; i++)
		size[i] = strlen(title[i]);
	//шапка таблицы
	cout << char(218) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(194);
	cout << setw(wn[m - 1]) << char(191) << endl;

	cout << char(179);
	for (int j = 0; j < m; j++)
		cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
		<< setw((wn[j] - size[j]) / 2) << char(179);
	cout << endl;
	for (int i = 0; i < k; i++)
	{//заполнение таблицы
		cout << char(195) << fixed;
		for (int j = 0; j < m - 1; j++)
			cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;

		cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
			<< setw((wn[0] - strlen(i_prn[i].name)) / 2) << char(179);
		cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].i_toch << char(179)
			<< setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
			<< setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
	}
	//низ таблицы
	cout << char(192) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(193);
	cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}

double conc(double a, double b, char u[]) {
	if (u == "y=x") {
		return (b * b - a * a) / 2.0;
	}
	if (u == "y=sin(22x)") {
		return (cos(a * 22.0) - cos(b * 22.0)) / 22.0;
	}
	if (u == "y=x^4") {
		return (b * b * b * b * b - a * a * a * a * a) / 5.0;
	}
	if (u == "y=arctg(x)") {
		return b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;
	}
	return 10e10;
}



double IntRect(double a, double b, double eps, PF f, int& n) {
	double s1=1, s2=0, dx, f1, f2;
	n = 1;
	while (abs(s2 - s1) >= eps) {
		s1 = 0, s2 = 0, dx = (b - a) / n;
		for (double i = a; i <= b; i += dx) {
			f1 = f(i);
			f2 = f(i + dx);
			if (f1 <= f2)
			{
				s1 += f1 * dx;
				s2 += f2 * dx;
			}
			else
			{
				s2 += f1 * dx;
				s1 += f2 * dx;
			}
			//s1+=f(a+(dx/2))*dx;
		}
		n*=2;
	} 	
	return s1;
}
double IntTrap(double a, double b, double eps, TPF f, int& n) {
	double s1 = 0, s2 = 0, dx, f1, f2,i;
	n = 1;
	do{
		s1 = 0, s2 = 0, dx = (b - a) / n;
		for (i = a; i <= b; i += dx) {
				f1 = f(i);
				f2 = f(i + dx);
				s1 += (dx * (f1 + f2) / 2);

		}
		n = n * 2;
	} while (abs(f(i) - f(i + dx)) >= eps);
	n /= 2;
	return s1;
}
