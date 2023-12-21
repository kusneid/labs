#include "h.h"

int iRandom(int a, int b)
{
	return a + (b - a + 1) * rand() / RAND_MAX;
}

void rever(int a[], int n)
{
	int minm;
	for (int i = 0; i < n - 1; i++)
	{
		minm = i;
		for (int j = i + 1; j < n; j++)
		{

			if (a[j] > a[minm])
			{
				minm = j;
			}
		}
		if (minm != i)
		{
			swap(a[i], a[minm]);
		}
	}
}

void bub(int a[], int n, char t)
{
	cout << "bubble method: ";
	int count = 0, sr = 0;

	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - i - 1; j++)
		{
			sr++;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);

				count++;
			}
		}
	}

	if (t == 'y')
	{
		for (int t = 0; t < n; t++)
		{
			cout << a[t] << " ";
		}
	}
	cout << "\n���������: " << sr << "\n������������: " << count << "\n";
}
void bubreversed(int a[], int n, char t)
{
	cout << "\nbubble method: ";
	int count = 0, sr = 0;

	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - i - 1; j++)
		{
			sr++;
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
				count++;
			}
		}
	}

	if (t == 'y')
	{
		for (int t = 0; t < n; t++)
		{
			cout << a[t] << " ";
		}
	}
	cout << "\n���������: " << sr << "\n������������: " << count << "\n";
}

void sel(int a[], int n, char t)
{

	int sr = 0, count = 0;
	cout << "\nselection method: ";
	int minm;
	for (int i = 0; i < n - 1; i++)
	{
		minm = i;
		for (int j = i + 1; j < n; j++)
		{
			sr++;
			if (a[j] < a[minm])
			{
				minm = j;
			}
		}
		if (minm != i)
		{
			swap(a[i], a[minm]);
			count++;
		}
	}

	if (t == 'y')
	{

		for (int t = 0; t < n; t++)
		{
			cout << a[t] << " ";
		}
	}
	cout << "\n���������: " << sr << "\n������������: " << count << "\n";
}

void selreversed(int a[], int n, char t)
{

	int sr = 0, count = 0;
	cout << "selection method: ";
	int maxm;
	for (int i = 0; i < n - 1; i++)
	{
		maxm = i;
		for (int j = i + 1; j < n; j++)
		{
			sr++;
			if (a[j] > a[maxm])
			{
				maxm = j;
			}
		}
		if (maxm != i)
		{
			swap(a[i], a[maxm]);
			count++;
		}
	}

	if (t == 'y')
	{

		for (int t = 0; t < n; t++)
		{
			cout << a[t] << " ";
		}
	}
	cout << "\n���������: " << sr << "\n������������: " << count << "\n";
}

void ran(int a[], int n, char t)
{
	srand((unsigned int)time(NULL));
	rand();
	int i = 0;
	for (i = 0; i < n; i++)
	{
		a[i] = iRandom(1, 19);
		if (t == 'y')
		{
			cout << a[i] << " ";
		}
	}
}