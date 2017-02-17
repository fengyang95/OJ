/*1018. Public Bike Management (30)*/
/*一个测试点不能过 27points*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_capacity,n_station,dest,n_road;
int half;
int mint=INT_MAX;
int send_from_p=INT_MAX;
int back_to_p=INT_MAX;
vector<vector<int>> road;
vector<int> cap;
vector<int> ret_path;
vector<int> path;
vector<int> visit;

void dfs(int start,int end,int t,int send_p,int back_p){
	if(start==end){
		if(t<mint){
			mint=t;
			ret_path=path;
			send_from_p=send_p;
			back_to_p=back_p;
		}
		else if(t==mint){
			if(send_p<send_from_p){
				ret_path=path;
				send_from_p=send_p;
				back_to_p=back_p;
			}
			else if(send_p==send_from_p){
				if(back_p<back_to_p){
					back_to_p=back_p;
					ret_path=path;
				}
			}

		}
		path.clear();

		return;
	}

	if(t>mint){
		path.clear();
		return;
	}

	for(int i=1;i<=n_station;++i){
		if(!visit[i]&&road[start][i]!=INT_MAX){
			visit[i]=true;
			path.push_back(i);
			if(cap[i]>half){
				dfs(i,end,t+road[start][i],send_p,back_p+cap[i]-half);
			}
			else{
				if(half-cap[i]>=back_p){
					dfs(i,end,t+road[start][i],send_p+half-cap[i]-back_p,0);
				}
				else{
					dfs(i,end,t+road[start][i],send_p,back_p-half+cap[i]);
				}
			}
			visit[i]=false;
		}
	}
}

int main(){
	cin>>max_capacity>>n_station>>dest>>n_road;
	half=max_capacity/2;
	cap.resize(n_station+1);
	for(int i=1;i<=n_station;++i){
		cin>>cap[i];
	}
	vector<int> temp(n_station+1,INT_MAX);
	road.resize(n_station+1,temp);
	int a,b,c;
	for(int i=0;i<n_road;++i){
		cin>>a>>b>>c;
		road[a][b]=road[b][a]=c;
	}
	visit.resize(n_station+1,false);
	dfs(0,dest,0,0,0);

	cout<<send_from_p;
	cout<<" 0";
	for(int i=0;i<ret_path.size();++i)
		cout<<"->"<<ret_path[i];
	cout<<" "<<back_to_p;

	return 0;
}