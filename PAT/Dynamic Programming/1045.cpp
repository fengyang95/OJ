/*1045. Favorite Color Stripe (30)*/
/*book[i] = j表示i颜色的下标为j*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> book(n+1,0);
	int data;
	for(int i=1;i<=m;++i){
		cin>>data;
		book[data]=i;//这步很关键
	}
	vector<int> a;
	int n_query;
	cin>>n_query;
	for(int i=0;i<n_query;++i){
		cin>>data;
		if(book[data]!=0){
			a.push_back(book[data]);
		}
	}

	int maxn=0;
	vector<int> dp(n_query,1);
	for(int i=0;i<a.size();++i){
		for(int j=0;j<i;++j){
			if(a[j]<=a[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}