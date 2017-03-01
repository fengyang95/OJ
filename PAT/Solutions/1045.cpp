/*1045. Favorite Color Stripe (30)*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> order;
vector<int> a;

int main(){
	int n;
	cin>>n;
	order.resize(n+1,0);
	int m;
	cin>>m;
	int data;
	for(int i=1;i<=m;++i){
		cin>>data;
		order[data]=i;
	}
	int n_total;
	cin>>n_total;
	for(int i=0;i<n_total;++i){
		cin>>data;
		if(order[data]!=0)
			a.push_back(order[data]);
	}

	int maxn=0;
	vector<int> dp(a.size(),0);
	for(int i=0;i<a.size();++i){
		dp[i]=1;
		for(int j=0;j<i;++j){
			if(a[i]>=a[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
		maxn=max(dp[i],maxn);
	}
	cout<<maxn; 
	return 0;
}
