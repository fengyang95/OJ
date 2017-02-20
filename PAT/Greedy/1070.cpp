/*1070. Mooncake (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mooncake{
	double num;
	double price;
	double per_price;
};

bool cmp(mooncake a,mooncake b){
	return a.per_price>b.per_price;
}

int main(){
	int n;
	double total_num;
	cin>>n>>total_num;
	vector<mooncake> src(n);
	for(int i=0;i<n;++i)
		cin>>src[i].num;
	for(int i=0;i<n;++i){
		cin>>src[i].price;
		src[i].per_price=src[i].price/src[i].num;
	}
	sort(src.begin(),src.end(),cmp);

	double left_num=total_num;
	double ret=0.0;
	for(int i=0;i<n;++i){
		if(left_num==0)break;
		if(src[i].num<=left_num){
			left_num=left_num-src[i].num;
			ret=ret+src[i].price;
		}
		else{
			ret=ret+src[i].per_price*left_num;
			left_num = 0;
		}
	}
	printf("%.2f",ret);
	return 0;
}