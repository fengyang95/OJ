/*1019. General Palindromic Number (20)*/
/*注意num为0的特殊情况*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int num,base;
	cin>>num>>base;
	if(num==0){
		cout<<"Yes\n0";
		return 0;
	}
	vector<int> v,v2;
	while(num){
		v.push_back(num%base);
		num/=base;
	}
	v2=v;
	reverse(v.begin(),v.end());
	if(v==v2)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cout<<v[0];
	for(int i=1;i<v.size();++i)
		cout<<" "<<v[i];
	return 0;
}