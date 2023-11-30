#include <iostream>
#include <iomanip>
using namespace std;
int fa(int a){
	if(a==1){return 1;}
	if (a==0) return 1;
	return a*fa(a-1);
}
void fill(double** a, int n, double x){
		
	for(int t = 0; t < n;++t){
		a[t] = new double[n];
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==j){
				a[i][j]=1.0;
			}else if(i>j){
				a[i][j]=pow(x,i)/pow((fa(j)),i);
			}else if(i<j){
				a[i][j]=pow((-1 * x),i)/pow((fa(j)),i);
			}
		}
	
	}


}
void print(double** a, int n, int m){
	for(int i=0;i<n;++i){
		cout<<'\n';
		for(int j=0;j<m;++j){	
			cout<<setw(10)<<a[i][j]<<" ";
	
		}
	
	}
	

}
void clear(double** a, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
}
int main(){
	int n;
	cin>>n;
	double x = 2;
	double** a = new double* [n];
	fill(a,n,x);
	print(a,n,n);
	clear(a, n);
	

}