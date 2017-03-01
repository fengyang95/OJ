/*1030. Travel Plan (30)*/
/*2.26 10:20--10:33 13min ac*/
/*1 submition*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,m,s,d;
int min_len=INT_MAX;
int min_cost=INT_MAX;
vector<int> path;
vector<int> temp;
vector<bool> visit;
vector<vector<int>> road;
vector<vector<int>> cost;

void dfs(int start,int end,int now_len,int now_cost){
	if(start==end){
		if(now_len<min_len){
			path=temp;
			min_len=now_len;
			min_cost=now_cost;
		}
		else if(now_len==min_len){
			if(now_cost<min_cost){
				min_cost=now_cost;
				path=temp;
			}
		}
		temp.clear();
	}
	if(now_len>min_len){
		temp.clear();
		return;
	}
	visit[start]=true;
	for(int i=0;i<n;++i){
		if(!visit[i]&&road[start][i]!=INT_MAX){
			visit[i]=true;
			temp.push_back(i);
			dfs(i,end,now_len+road[start][i],now_cost+cost[start][i]);
			visit[i]=false;
		}
	}
}

int main(){
	cin>>n>>m>>s>>d;
	road.resize(n,vector<int>(n,INT_MAX));
	cost.resize(n,vector<int>(n,INT_MAX));
	int st,en,len,co;
	for(int i=0;i<m;++i){
		cin>>st>>en>>len>>co;
		road[st][en]=road[en][st]=len;
		cost[st][en]=cost[en][st]=co;
	}
	visit.resize(n,false);
	dfs(s,d,0,0);
	cout<<s;
	for(int i=0;i<path.size();++i)
		cout<<" "<<path[i];
	cout<<" "<<min_len<<" "<<min_cost;
	return 0;
}