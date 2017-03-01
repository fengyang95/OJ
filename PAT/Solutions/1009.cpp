/*1009. Product of Polynomials (25)*/


#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double a[1001]={0.0};
	double b[1001]={0.0};
	double c[2001]={0.0};
	int expon;
	double coef;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>expon>>coef;
		a[expon]=coef;
	}
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>expon>>coef;
		b[expon]=coef;
	}

	for(int i=0;i<=1000;++i){
		for(int j=0;j<=1000;++j){
				c[i+j]+=a[i]*b[j];
		}
	}

	int cnt=0;
	for(int i=0;i<=2000;++i){
		if(abs(c[i])>0.00001)
			++cnt;
	}
	cout<<cnt;
	for(int i=2000;i>=0;--i){
		if(abs(c[i])>0.00001){
			printf(" %d %.1f",i,c[i]);
		}
	}
	return 0;
}