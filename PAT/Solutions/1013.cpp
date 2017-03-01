/*1013. Battle Over Cities (25)*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n_city,n_road,n_query;
vector<vector<int>> road;
vector<bool> visit;

void dfs(int st){
	visit[st]=true;
	for(int i=1;i<=n_city;++i){
		if(!visit[i]&&road[st][i]==1){
			dfs(i);
		}
	}
}


int main(){
	
	cin>>n_city>>n_road>>n_query;
	road.resize(n_city+1,vector<int>(n_city+1,INT_MAX));
	int st,en;
	for(int i=0;i<n_road;++i){
		cin>>st>>en;
		road[st][en]=road[en][st]=1;
	}
	visit.resize(n_city+1);
	int query;
	for(int i=0;i<n_query;++i){
		for(int j=1;j<=n_city;++j)
			visit[j]=false;
		cin>>query;
		visit[query]=true;
		int cnt=-1;
		for(int k=1;k<=n_city;++k){
			if(!visit[k]){
				dfs(k);
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}