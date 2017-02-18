/*1068. Find More Coins (30)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int& lhs,int& rhs){
	return lhs>rhs;
}
int main(){
	int n,sum;
	cin>>n>>sum;
	vector<int> v(n+1);
	for(int i=1;i<=n;++i)
		cin>>v[i];
	sort(v.begin()+1,v.end(),cmp);
	vector<vector<bool>> choice(n+1,vector<bool>(sum+1,false));
	vector<int> dp(sum+1);
	for(int i=1;i<=n;++i){
		for(int j=sum;j>=v[i];--j){
			if(dp[j]<=dp[j-v[i]]+v[i]){
				dp[j]=dp[j-v[i]]+v[i];
				choice[i][j]=true;
			}
		}
	}
	
	if(dp[sum]!=sum){
		cout<<"No Solution";
	}
	else{
		vector<int> ret;
		for(int i=n;i>=1;--i){
			if(choice[i][sum]){
				ret.push_back(v[i]);
				sum-=v[i];
			}
		}
		cout<<ret[0];
		for(int i=1;i<ret.size();++i)
			cout<<" "<<ret[i];
	}
	return 0;
}