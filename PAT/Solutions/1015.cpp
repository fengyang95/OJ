/*1015. Reversible Primes (20)*/
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int data){
	if(data==2||data==3)return true;
	if(data==1)return false;
	int up=sqrt(data)+1;
	for(int i=2;i<up;++i){
		if(data%i==0)return false;
	}
	return true;
}

void judge(int data,int radix){
	if(!isprime(data)){
		cout<<"No\n";
		return;
	}
	int reverse=0;
	while(data){
		reverse=reverse*radix+data%radix;
		data/=radix;
	}
	if(!isprime(reverse)){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
}
int main(){
	int data,radix;
	cin>>data;
	while(data>0){
		cin>>radix;
		judge(data,radix);
		cin>>data;
	}
	return 0;
}