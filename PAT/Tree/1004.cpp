/*1004. Counting Leaves (30)*/
/*dfs or bfs　*/
/*all passed*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
	vector<int> child;
};

int max_level=0;
vector<node> v;
int n,n_nonleaf;
vector<bool> visit;
int cnt[100];
void dfs(int root,int level){
	if(v[root].child.empty()){
		if(max_level<level)
			max_level=level;
		++cnt[level];
		return;
	}
	visit[root]=true;
	for(int i=0;i<v[root].child.size();++i){
		visit[i]=true;
		dfs(v[root].child[i],level+1);
		visit[i]=false;
	}
}

int main(){
	cin>>n>>n_nonleaf;
	v.resize(n+1);
	int id,k,child_id;
	for(int i=0;i<n_nonleaf;++i){
		scanf("%2d %d",&id,&k);
		for(int j=0;j<k;++j){
			scanf("%2d",&child_id);
			v[id].child.push_back(child_id);
		}
	}
	visit.resize(n,false);
	dfs(1,0);
	cout<<cnt[0];
	for(int i=1;i<=max_level;++i){
		cout<<" "<<cnt[i];
	}
	return 0;
	
}