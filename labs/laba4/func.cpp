#include "fx.h"




void iter(double x,double eps,int k){
	cout << "Метод итераций\n";
	int maxt=10000, it = 0;
	
	while(abs(x-k*cos(x))>=eps && it<maxt){
		x=k*cos(x);
		it++;
	}
	cout<<setprecision(7)<<x << "   " << it << '\n';
	
}


void newt(double x,double eps,int k){
	cout << "Метод Ньютона\n";
	int it=0;
	int maxt=10000;
	while (( abs(x-k*cos(x)) >= eps)&& (it<maxt))
	{
		
		x-=(x-k*cos(x))/(1+k*sin(x));
		it++;
	}
	cout<<setprecision(7)<<x << "   " << it << '\n';
	
}


void dele(double x, double eps,int k){
	cout << "Метод половинного деления\n";
	double l=-1.0,r=2.0;
	int maxt=10000;
	int it=0;
	while (abs(x- k*cos(x))>eps &&(it<maxt)){
		x=(l+r)/2;
	if ((l - k*cos(l)>0)!=(x - k*cos(x)>0)){
		r=x;
	}
	else
	{
		l=x;
	}
	it++;
	}
	cout<<setprecision(7)<<x << "   " << it << '\n';
	

}

