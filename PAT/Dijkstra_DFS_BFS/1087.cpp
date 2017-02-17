/*1087. All Roads Lead to Rome (30)*/
/*2.12 12:52--13:37 25points*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>
using namespace std;

int n_city,n_road;
int least_cost=INT_MAX;
int cnt=0;
int total_happiness=0;
int average_happiness=0;
vector<vector<int>> road;
vector<int> happiness;
map<string,int> index;
map<int,string> itname;
vector<bool> visit;
vector<int> path;
vector<int> ret;
void dfs(int start,int end,int now_cost,int now_happiness,int path_size){
	if(start==end){
		if(now_cost<least_cost){
			cnt=1;
			least_cost=now_cost;
			total_happiness=now_happiness;
			average_happiness=now_happiness/path_size;
			ret=path;
		}
		else if(now_cost==least_cost){
			++cnt;
			if(now_happiness>total_happiness){
				total_happiness=now_happiness;
				average_happiness=now_happiness/path_size;
				ret=path;
			}
			else if(now_happiness==total_happiness){
				if((now_happiness/path_size)>average_happiness){
					average_happiness=now_happiness/path_size;
					ret=path;
				}
			}
		}
		path.clear();
		return;
	}
	if(now_cost>least_cost){
		path.clear();
		return;
	}

	visit[start]=true;
	for(int i=0;i<n_city;++i){
		if(!visit[i]&&road[start][i]!=INT_MAX){
			visit[i]=true;
			path.push_back(i);
			dfs(i,end,now_cost+road[start][i],now_happiness+happiness[i],path_size+1);
			visit[i]=false;
		}
	}
}

int main(){
	cin>>n_city>>n_road;
	string start;
	cin>>start;
	index[start]=0;
	vector<int> temp(n_city,INT_MAX);
	road.resize(n_city,temp);
	happiness.resize(n_city,0);
	string name;
	int h;
	for(int i=1;i<n_city;++i){
		cin>>name>>h;
		itname[i]=name;
		index[name]=i;
		happiness[i]=h;
	}
	string st,en;
	int cost;
	for(int i=0;i<n_road;++i){
		cin>>st>>en>>cost;
		road[index[st]][index[en]]=road[index[en]][index[st]]=cost;
	}
	visit.resize(n_city,false);

	dfs(0,index["ROM"],0,0,0);

	cout<<cnt<<" "<<least_cost<<" "<<total_happiness<<" "<<average_happiness<<endl;
	cout<<start;
	for(int i=0;i<ret.size();++i){
		cout<<"->"<<itname[ret[i]];
	}
	return 0;
}