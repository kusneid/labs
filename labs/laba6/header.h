#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

typedef double (*PF)(double);
typedef double (*TPF)(double);

struct I_print {	
	char* name;
	double i_sum;	
	double i_toch;	
	int n;		
};
void PrintTabl(I_print i_prn[], int k);

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);


double IntRect(double a, double b, double eps, PF f, int& n);
double IntTrap(double a, double b, double eps, double (*f)(double), int& n);
double conc(double a, double b, char u[]);