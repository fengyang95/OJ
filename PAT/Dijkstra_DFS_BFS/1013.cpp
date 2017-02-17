/*1013. Battle Over Cities (25)*/
/*2.9 22:10--22:48 38min*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n_city,n_road,n_query;
vector<vector<int>> road;
vector<bool> visit;

void dfs(int index){
	visit[index]=true;
	for(int j=1;j<=n_city;++j){
		if(!visit[j]&&road[index][j]==1){
			dfs(j);
		}
	}
}

int main(){
	cin>>n_city>>n_road>>n_query;
	vector<int> temp(n_city+1);
	road.resize(n_city+1,temp);
	int a,b;
	for(int i=0;i<n_road;++i){
		cin>>a>>b;
		road[a][b]=road[b][a]=1;
	}
	
	visit.resize(n_city + 1);
	for(int i=0;i<n_query;++i){
		for (int i = 0; i <= n_city; ++i)
			visit[i] = false;//用resize()只能保证一次初始化为全是false;
		int q;
		cin>>q;
		visit[q]=true;
		int cnt=0;
		for(int j=1;j<=n_city;++j){
			if(!visit[j]){
				dfs(j);
				++cnt;
			}
		}
		cout<<cnt-1<<endl;
	}

	return 0;

}