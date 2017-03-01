/*1085. Perfect Sequence (25)*/
/*用二分查找 有一个测试点老是通不过！！不知道为啥？？？*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,p;
	cin>>n>>p;
	vector<long long> v(n);
	if(n==0){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;++i)
		scanf("%lld",&v[i]);
	sort(v.begin(),v.end());
	int maxnum=0;
	for(int i=0;i<n;++i){
		for(int j=i+maxnum;j<n;++j){
			if(v[i]*p>=v[j]){
				maxnum=j-i+1;
			}
			else
				break;
		}
	}
	cout<<maxnum;
	return 0;
}