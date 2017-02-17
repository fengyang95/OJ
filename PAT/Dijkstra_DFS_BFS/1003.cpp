/*1003. Emergency (25)*/
/*2.9 20:30--20:46 all passed  16min*/
/*amazing*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n_city,n_road,st,dest;
int mind=INT_MAX;
int cnt=0;
int maxteam=0;
vector<vector<int>> road;
vector<bool> visit;
vector<int> team;

void dfs(int start,int end,int dist,int team_num){
	if(start==end){
		if(dist<mind){
			cnt=1;
			mind=dist;
			maxteam=team_num;
		}
		else if(dist==mind){
			++cnt;
			if(team_num>maxteam)
				maxteam=team_num;
		}
		return;
	}
	if(dist>mind)return;
	visit[start]=true;//很有必要加上这句
	for(int i=0;i<n_city;++i){
		if(!visit[i]&&road[start][i]!=INT_MAX){
			visit[i]=true;
			dfs(i,end,dist+road[start][i],team_num+team[i]);
			visit[i]=false;
		}
	}
}

int main(){
	cin>>n_city>>n_road>>st>>dest;
	team.resize(n_city);
	for(int i=0;i<n_city;++i)
		cin>>team[i];
	vector<int> temp(n_city,INT_MAX);
	road.resize(n_city,temp);
	int a,b,c;
	for(int i=0;i<n_road;++i){
		cin>>a>>b>>c;
		road[a][b]=road[b][a]=c;
	}

	visit.resize(n_city,false);
	dfs(st,dest,0,team[st]);
	cout<<cnt<<" "<<maxteam;
	return 0;
} 