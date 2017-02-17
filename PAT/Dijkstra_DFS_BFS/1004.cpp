/*1004. Counting Leaves (30)*/
/*2.9 20:48--21:11 all passed 23min*/
/*unbelievable*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
	vector<int> child;
	int height=0;
};
int max_height=0;
vector<node> v(100);

void bfs(int root){
	if(v[root].child.empty())
		return;
	for(int i=0;i<v[root].child.size();++i){
		if(v[v[root].child[i]].height==0){
			v[v[root].child[i]].height=v[root].height+1;
			if(max_height<v[v[root].child[i]].height)
				max_height=v[v[root].child[i]].height;
		}	
		bfs(v[root].child[i]);
	}
}

int main(){
	int n,n_non_leaf;
	cin>>n>>n_non_leaf;
	int root_id,k,child_id;
	for(int i=0;i<n_non_leaf;++i){
		scanf("%2d %d",&root_id,&k);
		for(int j=0;j<k;++j){
			scanf("%2d",&child_id);
			v[root_id].child.push_back(child_id);
		}
	}
	v[1].height=1;
	bfs(1);
	vector<int> cnt(max_height+1,0);
	for(int i=0;i<100;++i){
		if(v[i].height!=0){
			if(v[i].child.empty()){
				++cnt[v[i].height];
			}
		}
	}

	cout<<cnt[1];
	for(int i=2;i<=max_height;++i){
		cout<<" "<<cnt[i];
	}
	return 0;
}