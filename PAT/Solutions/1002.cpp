/*1002. A+B for Polynomials (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<double> coef(10001,0.0);
	int k;
	int expon;
	double coefficient;
	for(int j=0;j<2;++j){
		cin>>k;
		for(int i=0;i<k;++i){
			cin>>expon>>coefficient;
			coef[expon]+=coefficient;
		}
	}
	int cnt=0;
	for(int i=0;i<1001;++i){
		if(abs(coef[i])>0.01)++cnt;
	}
	cout<<cnt;
	for(int i=1000;i>=0;--i){
		if(abs(coef[i])>0.01){
			printf(" %d %.1f",i,coef[i]);
		}
	}
	return 0;
}