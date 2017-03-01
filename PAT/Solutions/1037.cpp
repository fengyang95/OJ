/*1037. Magic Coupon (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int nc,np;
	cin>>nc;
	vector<int> setc(nc);
	for(int i=0;i<nc;++i)
		cin>>setc[i];
	cin>>np;
	vector<int> setp(np);
	for(int i=0;i<np;++i)
		cin>>setp[i];
	sort(setc.begin(),setc.end());
	sort(setp.begin(),setp.end());
	int total=0;
	for(int i=0,j=0;i<setc.size()&&j<setp.size();++i,++j){
		if(setc[i]>=0||setp[j]>=0)break;
		total+=setc[i]*setp[j];
	}
	for(int i=setc.size()-1,j=setp.size()-1;i>=0&&j>=0;--i,--j){
		if(setc[i]<=0||setp[j]<=0)break;
		total+=setc[i]*setp[j];
	}
	cout<<total;
	return 0;
}