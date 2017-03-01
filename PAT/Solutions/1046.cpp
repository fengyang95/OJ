/*1046. Shortest Distance (20)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> sum(n+1,0);
	for(int i=1;i<=n;++i){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	int n_query;
	cin>>n_query;
	int a,b;
	int Min,Max;
	for(int i=0;i<n_query;++i){
		cin>>a>>b;
		Min=min(a,b);
		Max=max(a,b);
		int dis=sum[Max-1]-sum[Min-1];
		dis=min(dis,sum[n]-dis);
		cout<<dis<<endl;
	}
	return 0;
}