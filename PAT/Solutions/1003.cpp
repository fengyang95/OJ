/*1003. Emergency (25)*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n_city,n_road,Start,End;
vector<int> team;
vector<vector<int>> road;
vector<bool> visit;
int max_team=0,cnt=0;
int min_len=INT_MAX;
void dfs(int st,int en,int num_team,int len){
	if(st==en){
		if(len<min_len){
			min_len=len;
			cnt=1;
			max_team=num_team;
		}
		else if(len==min_len){
			++cnt;
			if(max_team<num_team){
				max_team=num_team;
			}
		}
		return;
	}
	if(len>min_len)return;
	visit[st]=true;
	for(int i=0;i<n_city;++i){
		if(!visit[i]&&road[st][i]!=INT_MAX){
			visit[i]=true;
			dfs(i,en,num_team+team[i],len+road[st][i]);
			visit[i]=false;
		}
	}
}


int main(){
	cin>>n_city>>n_road>>Start>>End;
	team.resize(n_city);
	for(int i=0;i<n_city;++i)
		cin>>team[i];
	int s,e,dis;
	road.resize(n_city,vector<int>(n_city,INT_MAX));
	for(int i=0;i<n_road;++i){
		cin>>s>>e>>dis;
		road[s][e]=road[e][s]=dis;
	}
	visit.resize(n_city,false);
	dfs(Start,End,team[Start],0);
	cout<<cnt<<" "<<max_team;
	return 0;
}