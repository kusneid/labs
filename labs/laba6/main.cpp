#include "header.h"

using namespace std;
int main(){
	double eps,a=1,b=3;
	int n=1;
	double (*F[4])(double)={f1,f2,f3,f4};
	//заполнение неизменяемых элементов таблицы
	I_print ans[4];
	ans[0].name="y=x";
	ans[0].i_toch=(b * b - a * a) / 2.0;
	ans[1].name="y=sin(22x)";
	ans[1].i_toch=(cos(a * 22.0) - cos(b * 22.0)) / 22.0;
	ans[2].name="y=x^4";
	ans[2].i_toch=(b * b * b * b * b - a * a * a * a * a) / 5.0;
	ans[3].name="y=arctg(x)";
	ans[3].i_toch=b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;
	//заполнение изменяемых элементов таблицы
	for (int h=1;h<3;++h){
		if (h == 1) {
			cout << "IntTrap:\n";
		}
		else
		{
			cout << "IntRect:\n";
		}
		for(int t=-2;t>=-6;--t){
		eps = pow(10,t);
		cout<<"eps="<<eps<<"\n";
		for(int i=0;i<4;++i){
			switch(h){
			case 1:ans[i].i_sum=IntRect(a,b,eps,F[i],ans[i].n);
			case 2:ans[i].i_sum=IntTrap(a,b,eps,F[i],ans[i].n);
			}
	
		}
		PrintTabl(ans, 4);
	}
	}
}