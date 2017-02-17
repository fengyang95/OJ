/*1030. Travel Plan (30)*/
/*2.11 13:04--13:23 all passed*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;

struct node{
	int dist=INT_MAX;
	int cost=INT_MAX;
};

vector<vector<node>> road;
vector<int> visit;
int min_distance=INT_MAX;
int min_cost=INT_MAX;
vector<int> path;
vector<int> temp;
void dfs(int start,int end,int now_dist,int now_cost){
	if(start==end){
		if(now_dist<min_distance){
			min_distance=now_dist;
			min_cost=now_cost;
			path=temp;
		}
		else if(now_dist==min_distance){
			if(now_cost<min_cost){
				min_cost=now_cost;
				path=temp;
			}
		}
		temp.clear();
		return;
	}

	if(now_dist>min_distance){
		temp.clear();
		return;
	}
	visit[start]=true;//key point
	for(int i=0;i<n;++i){
		if(!visit[i]&&road[start][i].dist!=INT_MAX){
			visit[i]=true;
			temp.push_back(i);
			dfs(i,end,now_dist+road[start][i].dist,now_cost+road[start][i].cost);
			visit[i]=false;
		}
	}
}


int main(){
	cin>>n;
	int n_road,start,end;
	cin>>n_road>>start>>end;
	vector<node> temp(n);
	road.resize(n,temp);
	int a,b,c,d;
	for(int i=0;i<n_road;++i){
		cin>>a>>b>>c>>d;
		road[a][b].dist=road[b][a].dist=c;
		road[a][b].cost=road[b][a].cost=d;
	}

	visit.resize(n,false);
	dfs(start,end,0,0);
	cout<<start;
	for(int i=0;i<path.size();++i){
		cout<<" "<<path[i];
	}
	cout<<" "<<min_distance<<" "<<min_cost;
	return 0;
}