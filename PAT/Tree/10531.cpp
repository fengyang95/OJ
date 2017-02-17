/*1053. Path of Equal Weight (30)*/
/*有毒啊啊啊*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct node{
	vector<int> child;
	int weight;
};

vector<node> v;
int n,n_nonleaf,total_weight;
vector<int> path;
vector<vector<int>> paths;

void dfs(int root, int sum){  
	if(sum>total_weight){
		return;
	}
	else if(sum==total_weight){
		if(v[root].child.empty()){
			paths.push_back(path);
			return;
		}
	}
	for(int i=0;i<v[root].child.size();++i){
		path.push_back(v[v[root].child[i]].weight);
		dfs(v[root].child[i],sum+v[v[root].child[i]].weight);
		path.pop_back();
	}
}  


bool cmp(int a,int b){
	return v[a].weight>v[b].weight;
}

int main(){
	cin>>n>>n_nonleaf>>total_weight;
	v.resize(n);
	for(int i=0;i<n;++i)
		cin>>v[i].weight;
	int id,k;
	for(int i=0;i<n_nonleaf;++i){
		scanf("%2d %d",&id,&k);
		v[id].child.resize(k);
		for(int j=0;j<k;++j){
			scanf("%2d",&v[id].child[j]);
		}
		sort(v[id].child.begin(), v[id].child.end(), cmp);
	}

	dfs(0,v[0].weight);
	for(int i=0;i<paths.size();++i){
		cout<<v[0].weight;
		for(int j=0;j<paths[i].size();++j)
			cout<<" "<<paths[i][j];
		cout<<endl;
	}
	//getchar();
	return 0;
}
