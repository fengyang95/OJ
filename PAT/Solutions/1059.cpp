/*1059. Prime Factors (25)*/
#include <iostream>
#include <vector>
using namespace std;
const long long maxsize = 500000;
bool prime[maxsize];

void setprimetable(){
	fill(prime, prime + maxsize, true);
	for(int i=2;i<maxsize;++i){
		for(int j=2;j<maxsize&&j*i<maxsize;++j)
			prime[i*j]=false;
	}
}

int main(){
	long long num;
	cin>>num;
	long long src = num;
	int cnt[maxsize]={0};
	setprimetable();
	for(int i=2;i<maxsize;++i){
		while(prime[i]&&num%i==0){
			num/=i;
			++cnt[i];
		}
		if(num==1)break;
	}
	cout<<src;
	if (src == 1){
		cout << "=1";
		return 0;
	}
	bool isfirst=true;
	for(int i=2;i<maxsize;++i){
		if(cnt[i]!=0){
			if(isfirst){
				cout<<"=";
				isfirst=false;
			}
			else
				cout<<"*";
			if(cnt[i]==1)
				cout<<i;
			else
				cout<<i<<"^"<<cnt[i];
		}
	}
	return 0;
}