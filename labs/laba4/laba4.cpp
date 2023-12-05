#include "fx.h"
int main(){
	system("chcp 1251");
	cout << "x-cos(x), eps: 0.000001\n";
	iter(1,0.000001,1);
	newt(1,0.000001,1);
	dele(1,0.000001,1);

	cout << "\nx-cos(x), eps: 0.00000001\n";
	iter(1,0.00000001,1);
	newt(1,0.00000001,1);
	dele(1,0.00000001,1);

	cout << "\nx-10cos(x), eps: 0.000001\n";
	iter(1,0.000001,10);
	newt(1,0.000001,10);
	dele(1,0.000001,10);


}